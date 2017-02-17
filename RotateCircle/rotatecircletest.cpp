#include "rotatecircletest.h"
#include "ui_rotatecircletest.h"

RotateCircleTest::RotateCircleTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RotateCircleTest)
{
    ui->setupUi(this);
    ui->widget->setSetpAngle(10);

    ui->widget_2->setSetpAngle(10);
    ui->widget_2->setClockwise(false);
    ui->widget_2->setPieFirstStartColor(QColor(35, 140, 35));
    ui->widget_2->setPieFirstEndColor(QColor(45, 140, 75));

    ui->widget_3->setSetpAngle(10);
    ui->widget_3->setPieFirstStartColor(QColor(255, 50, 45));
    ui->widget_3->setPieFirstEndColor(QColor(255, 65, 10));

    ui->widget_4->setSetpAngle(10);
    ui->widget_4->setClockwise(false);
    ui->widget_4->setPieFirstStartColor(QColor(65, 110, 235));
    ui->widget_4->setPieFirstEndColor(QColor(70, 115, 250));

}

RotateCircleTest::~RotateCircleTest()
{
    delete ui;
}
