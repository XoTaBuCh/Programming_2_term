#ifndef TEMP_H
#define TEMP_H

#include <QWidget>
#include <QtGui>
#include <QDialog>
#include <QtCore>
#include <menu.h>

class temp;

namespace Ui { class temp; }

class temp : public QWidget
{
    Q_OBJECT
public:
    temp(QWidget *parent = nullptr);

    ~temp();

    QVector<QList<QImage>>* pictures;

    QPainter* painter;

private:
    Ui::temp *ui;

protected:
    void paintEvent(QPaintEvent *event);

    void draw_all();

private slots:
    void on_tabWidget_currentChanged(int index);
};


#endif // TEMP_H
