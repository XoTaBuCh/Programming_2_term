#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) : QWidget(parent), ui(new Ui::menu)
{
    ui->setupUi(this);    
}

menu::~menu()
{
    delete ui;
}

void menu::get_weather(){
    QString api = "f8bae8ee19f9925608df929c76202fa7";
    auto *manager = new QNetworkAccessManager(this);
    ui->progressBar->setRange(-90, 160);
    ui->progressBar->setValue(-90);
    int p = 1000, t = 1000;
    for(int i = -90; i <= 90; i=i+10){
        for(int j = -180; j <= 180; j=j+10){
            QEventLoop eventLoop;
            connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
            QNetworkRequest request;
            QString baseUrl = "http://api.openweathermap.org/data/2.5/forecast/daily?lat=" +
                    QString::number(i) + "&lon="+QString::number(j)+"&cnt=7&appid=" + api;
            request.setUrl(baseUrl);
            QNetworkReply* reply = manager->get(request);
            eventLoop.exec();
            QJsonDocument document = QJsonDocument::fromJson(((QString) reply->readAll()).toUtf8());
            QJsonObject json = document.object();
            for(int k = 0; k < json["list"].toArray().size(); k++){
                QList<double> list;
                list.push_back(json["list"].toArray()[k].toObject()["temp"].toObject()["day"].toDouble());
                list.push_back(json["list"].toArray()[k].toObject()["pressure"].toDouble());
                list.push_back(json["list"].toArray()[k].toObject()["humidity"].toDouble());
                if(json["list"].toArray()[k].toObject()["pressure"].toDouble() > p){
                    p = json["list"].toArray()[k].toObject()["pressure"].toDouble();
                }
                if(json["list"].toArray()[k].toObject()["temp"].toObject()["day"].toDouble() < t){
                    t = json["list"].toArray()[k].toObject()["temp"].toObject()["day"].toDouble();
                }
                (*data)[qMakePair(j * 4 + 680, i * (-4) + 400)].push_back(qMakePair(list,
                    (*icons)[json["list"].toArray()[k].toObject()["weather"].toArray()[0].toObject()["icon"].toString()]));
            }
            delete reply;
        }
        if (i>-77){
            ui->progressBar->setValue(i);
        }
    }
    delete manager;
}

long double map(long double x, long double in_min, long double in_max, long double out_min, long double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void menu::get_coords(){
    QFile file(QString(PRJ_PATH)+ "/world.json");
    QJsonDocument document;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        document = QJsonDocument::fromJson(file.readAll());
    }
    file.close();
    QJsonArray json = document.array();
    for(int i = 0; i < json.size(); i++){
        QList<QPolygon> list;
        if (json[i].toObject()["fields"].toObject()["geo_shape"].toObject()["coordinates"].toArray()[0].toArray()[0].toArray()[0].isArray())
        {
            QJsonArray jsonArray = json[i].toObject()["fields"].toObject()["geo_shape"].toObject()["coordinates"].toArray();
            for(int j = 0; j < jsonArray.size(); j++){
                QJsonArray jsonArray0 = jsonArray[j].toArray();
                QPolygon poly;
                QJsonArray jsonArray2 = jsonArray0[0].toArray();

                for(int k = 0; k < jsonArray2.size(); k++){
                    QJsonArray jsonArray3 = jsonArray2[k].toArray();
                    poly << QPoint(jsonArray3[0].toDouble() * (4) + 680, jsonArray3[1].toDouble() * (-4) + 400);
                }
                list.push_back(poly);
            }
        }
        else{
            QJsonArray jsonArray = json[i].toObject()["fields"].toObject()["geo_shape"].toObject()["coordinates"].toArray()[0].toArray();
            QPolygon poly;
            for (int j =0; j<jsonArray.size(); j++){
                QJsonArray jsonArray2 = jsonArray[j].toArray();
                poly<<QPoint(jsonArray2[0].toDouble() * (4) + 680, jsonArray2[1].toDouble() * (-4)  + 400);
            }
            list.push_back(poly);

        }

        coords->push_back(list);
    }
}

void menu::get_pictures(){
    for(int k = 0; k < 7; k++){
        QImage temper(1367,721,QImage::Format_RGB32);
        QImage pressur(1367, 721,QImage::Format_RGB32);
        QImage humidity(1367, 721, QImage::Format_RGB32);
        QPainter painter_t(&temper);
        QPainter painter_p(&pressur);
        QPainter painter_h(&humidity);
        for(int y = 40; y<760; y++){
            double new_y = y / 40 * 40;
            for(int x = 0; x<=1366; x++){
                double new_x = x / 40 * 40;
                double t1 = (x - new_x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x + 40, new_y)][k].first[0] +
                        (new_x + 40 - x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x, new_y)][k].first[0];
                double t2 = (x - new_x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x + 40, new_y + 40)][k].first[0] +
                        (new_x + 40 - x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x, new_y + 40)][k].first[0];
                double t = (y - new_y) / (new_y + 40 - new_y) * t2 +
                        (new_y + 40 - y) / (new_y + 40 - new_y) * t1;
                double p1 = (x - new_x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x + 40, new_y)][k].first[1] +
                        (new_x + 40 - x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x, new_y)][k].first[1];
                double p2 = (x - new_x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x + 40, new_y + 40)][k].first[1] +
                        (new_x + 40 - x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x, new_y + 40)][k].first[1];
                double p = (y - new_y) / (new_y + 40 - new_y) * p2 +
                        (new_y + 40 - y) / (new_y + 40 - new_y) * p1;
                double h1 = (x - new_x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x + 40, new_y)][k].first[2] +
                        (new_x + 40 - x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x, new_y)][k].first[2];
                double h2 = (x - new_x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x + 40, new_y + 40)][k].first[2] +
                        (new_x + 40 - x) / (new_x + 40 - new_x) * (*data)[qMakePair(new_x, new_y + 40)][k].first[2];
                double h = (y - new_y) / (new_y + 40 - new_y) * h2 +
                        (new_y + 40 - y) / (new_y + 40 - new_y) * h1;
                t = map(t, 200, 320, 0, 255);
                p = map(p, 950, 1083, 0, 255);
                h = map(h, 0, 100, 0, 255);
                temper.setPixel(x, y - 40, qRgb(0, t, 255-t));
                pressur.setPixel(x, y - 40, qRgb(p, p, 255-p));
                humidity.setPixel(x, y - 40, qRgb(255-h, 0, h));
            }
        }
        draw_boundaries(painter_t);
        draw_boundaries(painter_p);
        draw_boundaries(painter_h);
        QImage temper_icons = temper;
        QPainter painter_t_icons(&temper_icons);
        for(int i = -90; i <= 90; i=i+10){
            for(int j = -180; j <= 180; j=j+10){

                painter_t_icons.drawImage(j * 4 + 680, i * (-4) + 400, (*data)[qMakePair(j * 4 + 680, i * (-4) + 400)][k].second);

            }
        }
        draw_palitra_temp(painter_t);
        draw_palitra_temp(painter_t_icons);
        draw_palitra_press(painter_p);
        draw_palitra_humid(painter_h);
        painter_t.end();
        painter_p.end();
        painter_h.end();
        painter_t_icons.end();
        QList<QImage> list = {temper, pressur, humidity, temper_icons};
        pictures->push_back(list);
        ui->progressBar->setValue(k*10 + 90);
    }
}

void menu::get_icons(){
    auto *manager = new QNetworkAccessManager(this);
    QStringList tmp = {"01", "02", "03", "04", "09", "10", "11", "13", "50"};
    for(int i = 0; i < 9; i++){
        QEventLoop eventLoop;
        connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
        QNetworkRequest request;
        QString baseUrl = "http://openweathermap.org/img/wn/" + tmp[i] +"d@2x.png";
        request.setUrl(baseUrl);
        QNetworkReply* reply = manager->get(request);
        eventLoop.exec();
        QByteArray data = reply->readAll();
        QImage image = QImage::fromData(data);
        (*icons)[tmp[i] +"d"] = image.scaled(30, 30);
        delete reply;
    }
    delete manager;
}

void menu::draw_boundaries(QPainter &painter){
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    for(int j = 0; j<(*coords).size();j++){
        for(int k = 0; k <(*coords)[j].size(); k++){
            painter.drawPolygon((*coords)[j][k]);
        }
    }
}

void menu::draw_palitra_temp(QPainter& painter){
    for(int i = 0; i < 255; i++){
        painter.setPen(QColor(0, i, 255 - i, 255));
        painter.drawLine(20 + i, 650, i + 20, 670);
    }
    painter.setPen(Qt::white);
    QPainterPath text1, text2;
    QFont font("times");
    font.setPointSize(20);
    painter.setBrush(QBrush(Qt::white));

    text1.addText(QPoint(15, 640), font, QString("200°K"));
    text2.addText(QPoint(255, 640), font, QString("320°K"));
    painter.drawPath(text1);
    painter.drawPath(text2);
}

void menu::draw_palitra_humid(QPainter& painter){
    for(int i = 0; i < 255; i++){
        painter.setPen(QColor(255 - i, 0, i, 255));
        painter.drawLine(20 + i, 650, i + 20, 670);
    }
    painter.setPen(Qt::white);
    QPainterPath text1, text2;
    QFont font("times");
    font.setPointSize(20);
    painter.setBrush(QBrush(Qt::white));

    text1.addText(QPoint(15, 640), font, QString("0 %"));
    text2.addText(QPoint(255, 640), font, QString("100 %"));
    painter.drawPath(text1);
    painter.drawPath(text2);
}

void menu::draw_palitra_press(QPainter &painter){
    for(int i = 0; i < 255; i++){
        painter.setPen(QColor(i, i, 255 - i, 255));
        painter.drawLine(20 + i, 650, i + 20, 670);
    }
    painter.setPen(Qt::white);
    QPainterPath text1, text2;
    QFont font("times");
    font.setPointSize(20);
    painter.setBrush(QBrush(Qt::white));

    text1.addText(QPoint(15, 640), font, QString("950 mbar"));
    text2.addText(QPoint(255, 640), font, QString("1083 mbar"));
    painter.drawPath(text1);
    painter.drawPath(text2);
}


void menu::paintEvent(QPaintEvent *event){
    QImage back(QString(PRJ_PATH) + "/water.png");
    QRect dst_rc = rect();
    QPainter painter(this);
    painter.drawImage(0, 0, back.scaled(dst_rc.width(), dst_rc.height()));
}

void menu::on_pushButton_clicked()
{
    coords = new QVector<QList<QPolygon>>;

    data = new QMap<QPair<int, int>, QVector<QPair<QList<double>,QImage>>>;

    pictures = new QVector<QList<QImage>>;

    icons = new QMap<QString, QImage>;

    get_coords();

    get_icons();

    get_weather();

    get_pictures();

    temp* t = new temp();

    t->pictures = pictures;

    t->setWindowFlags(Qt::WindowStaysOnTopHint);
    t->setWindowState(Qt::WindowMaximized);
    t->show();

    this->close();
}
