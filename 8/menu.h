#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPainter>
#include <temp.h>

class menu;
namespace Ui { class menu; }

class menu : public QWidget
{
    Q_OBJECT
public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private:
    Ui::menu *ui;

    QVector<QList<QPolygon>>* coords;

    QMap<QPair<int, int>, QVector<QPair<QList<double>,QImage>>>* data;

    QVector<QList<QImage>>* pictures;

    QMap<QString, QImage>* icons;

protected:
    void paintEvent(QPaintEvent *event);

    void get_weather();

    void get_coords();

    void get_pictures();

    void get_icons();

    void draw_palitra_press(QPainter &painter);

    void draw_boundaries(QPainter &painter);

    void draw_palitra_temp(QPainter& painter);

    void draw_palitra_humid(QPainter& painter);

private slots:
    void on_pushButton_clicked();

};

#endif // MENU_H
