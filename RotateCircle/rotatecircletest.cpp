#include "rotatecircletest.h"
#include "ui_rotatecircletest.h"

RotateCircleTest::RotateCircleTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RotateCircleTest)
{
    ui->setupUi(this);
}

RotateCircleTest::~RotateCircleTest()
{
    delete ui;
}
