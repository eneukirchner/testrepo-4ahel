#include "portscanner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Portscanner w;
    w.show();
    return a.exec();
}
