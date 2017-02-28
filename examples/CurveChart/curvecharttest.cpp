#pragma execution_character_set("utf-8")
#include "curvecharttest.h"
#include "ui_curvecharttest.h"
#include <QTimer>

CurveChartTest::CurveChartTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurveChartTest)
{
    ui->setupUi(this);
    ui->widget->setTitle("简单曲线");
    dataTimer = new QTimer(this);
    dataTimer->setInterval(300);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(addData()));
    dataTimer->start();
}

CurveChartTest::~CurveChartTest()
{
    delete ui;
}

void CurveChartTest::addData()
{
    ui->widget->addData(qrand()%100);
}
