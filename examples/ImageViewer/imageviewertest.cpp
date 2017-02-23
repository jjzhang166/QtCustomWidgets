#pragma execution_character_set("utf-8")
#include "imageviewertest.h"
#include "imageviewer.h"
#include "ui_imageviewertest.h"
#include <QFileDialog>

ImageViewerTest::ImageViewerTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewerTest)
{
    ui->setupUi(this);
    ui->sizeTypeComboBox->addItem("原始大小", (int)ImageViewer::OriginalSize);
    ui->sizeTypeComboBox->addItem("适合大小", (int)ImageViewer::SuitableSize);
    ui->sizeTypeComboBox->addItem("填充大小", (int)ImageViewer::FillSize);

    connect(ui->sizeTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setImageSizeType(int)));
    connect(ui->fadeCkb, SIGNAL(clicked(bool)), ui->imageViewer, SLOT(setFadeEnable(bool)));
    connect(ui->keyMoveCkb, SIGNAL(clicked(bool)), ui->imageViewer, SLOT(setKeyMoveEnable(bool)));
    connect(ui->openBtn, SIGNAL(clicked(bool)), ui->imageViewer, SLOT(loadImages()));
}

ImageViewerTest::~ImageViewerTest()
{
    delete ui;
}

void ImageViewerTest::setImageSizeType(int index)
{
    ImageViewer::ImageSizeType type =(ImageViewer::ImageSizeType)(ui->sizeTypeComboBox->itemData(index).toInt());
    ui->imageViewer->setSizeType(type);
}
