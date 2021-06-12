#include "temp.h"
#include "menu.h"

#include <QApplication>
#include <QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu m;
    m.show();
    return a.exec();
}
