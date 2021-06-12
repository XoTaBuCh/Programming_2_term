#include "temp.h"
#include "ui_temp.h"

temp::temp(QWidget *parent) : QWidget(parent), ui(new Ui::temp)
{
    ui->setupUi(this);
    QDateTime dat;
    dat =QDateTime::currentDateTime();
    ui->tabWidget_2->setTabText(0, dat.toString("dd.MM"));
    ui->tabWidget_2->setTabText(1, dat.addDays(1).toString("dd.MM"));
    ui->tabWidget_2->setTabText(2, dat.addDays(2).toString("dd.MM"));
    ui->tabWidget_2->setTabText(3, dat.addDays(3).toString("dd.MM"));
    ui->tabWidget_2->setTabText(4, dat.addDays(4).toString("dd.MM"));
    ui->tabWidget_2->setTabText(5, dat.addDays(5).toString("dd.MM"));
    ui->tabWidget_2->setTabText(6, dat.addDays(6).toString("dd.MM"));

}

temp::~temp()
{
    delete ui;
}



void temp::draw_all(){
    int current = ui->tabWidget->currentIndex();
    if(current == 0 && ui->checkBox->isChecked()){
        painter->drawImage(0, 40, (*pictures)[ui->tabWidget_2->currentIndex()][3]);
        update();
    }
    else{
        painter->drawImage(0, 40, (*pictures)[ui->tabWidget_2->currentIndex()][current]);
        update();
    }
}


void temp::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    temp::painter = &painter;
    draw_all();
}

void temp::on_tabWidget_currentChanged(int index)
{
    if(index == 0){
        ui->checkBox->setVisible(1);
    }
    else{
        ui->checkBox->setVisible(0);
    }
}
