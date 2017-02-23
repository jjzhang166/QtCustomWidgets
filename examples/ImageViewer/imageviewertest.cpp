#include "imageviewertest.h"
#include "ui_imageviewertest.h"

ImageViewerTest::ImageViewerTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewerTest)
{
    ui->setupUi(this);

}

ImageViewerTest::~ImageViewerTest()
{
    delete ui;
}
