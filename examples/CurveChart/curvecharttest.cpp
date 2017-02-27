#pragma execution_character_set("utf-8")
#include "curvecharttest.h"
#include "ui_curvecharttest.h"

CurveChartTest::CurveChartTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurveChartTest)
{
    ui->setupUi(this);
    ui->widget->setTitle("简单曲线");
}

CurveChartTest::~CurveChartTest()
{
    delete ui;
}
