#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    curveChartDataTimer = new QTimer(this);
    curveChartDataTimer->setInterval(300);
    connect(curveChartDataTimer, SIGNAL(timeout()), this, SLOT(curveChartAddData()));
    curveChartDataTimer->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::curveChartAddData()
{
    ui->curveChart->addData(qrand()%100);
}
