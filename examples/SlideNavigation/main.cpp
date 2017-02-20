#include "slidenavigationtest.h"
#include <QApplication>
#include "slidenavigation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SlideNavigationTest w;
    w.show();

    return a.exec();
}
