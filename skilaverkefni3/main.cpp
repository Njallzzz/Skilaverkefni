#include "ui/mainwindow.h"
#include "ui/computerwindow.h"
#include "ui/personwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon( QIcon(":pi.ico") );
    w.show();

    return a.exec();
}
