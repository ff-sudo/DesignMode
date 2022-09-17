#include "DesignMode.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesignMode w;
    w.show();
    return a.exec();
}
