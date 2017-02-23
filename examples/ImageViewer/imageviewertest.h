#ifndef IMAGEVIEWERTEST_H
#define IMAGEVIEWERTEST_H

#include <QWidget>

namespace Ui {
class ImageViewerTest;
}

class ImageViewerTest : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewerTest(QWidget *parent = 0);
    ~ImageViewerTest();

private:
    Ui::ImageViewerTest *ui;
};

#endif // IMAGEVIEWERTEST_H
