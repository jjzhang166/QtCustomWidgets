#include "roundprogressbartest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoundProgressBarTest w;
    w.show();

    return a.exec();
}
