#include "imageviewertest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewerTest w;
    w.show();

    return a.exec();
}
