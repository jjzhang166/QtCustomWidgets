#include "slidenavigationapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SlideNavigationApp w;
    w.show();

    return a.exec();
}
