#include "mainwindow.h"
#include "computerwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ComputerWindow c;
    c.show();

    return a.exec();
}
