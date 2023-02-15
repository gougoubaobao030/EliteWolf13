#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.welcome();
//    w.mainScene();
    return a.exec();
}
//warning: use qDeleteAll();
//中途感想，我想我造了一座罗马
//抓狂捉虫感想，罗马并非一天建成
