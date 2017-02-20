#pragma execution_character_set("utf-8")
#include "slidenavigationtest.h"
#include "ui_slidenavigationtest.h"
#include <QKeyEvent>

SlideNavigationTest::SlideNavigationTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlideNavigationTest)
{
    ui->setupUi(this);
    ui->widget->addItem("星期一");
    ui->widget->addItem("星期二");
    ui->widget->addItem("星期三");
    ui->widget->addItem("星期四");
    ui->widget->addItem("星期五");
    ui->widget->addItem("星期六");
    ui->widget->addItem("星期日");
    ui->widget->addItem("星期八");
    helpConnect(ui->widget);

    ui->widget_2->setBarRadious(5);
    ui->widget_2->setItemRadious(5);
    ui->widget_2->setItemStartColor(QColor(254, 176, 42));
    ui->widget_2->setItemEndColor((QColor(225, 156, 37)));
    ui->widget_2->addItem("第一次");
    ui->widget_2->addItem("第二次");
    ui->widget_2->addItem("第三次");
    ui->widget_2->addItem("第四次");
    ui->widget_2->addItem("第五次");
    ui->widget_2->addItem("第六次");
    ui->widget_2->addItem("第七次");
    ui->widget_2->addItem("第八次");
    helpConnect(ui->widget_2);

    ui->widget_3->setBarRadious(10);
    ui->widget_3->setItemRadious(10);
    ui->widget_3->setItemStartColor(QColor(255, 0, 0));
    ui->widget_3->setItemEndColor((QColor(225, 20, 10)));
    ui->widget_3->addItem("第一名");
    ui->widget_3->addItem("第二名");
    ui->widget_3->addItem("第三名");
    ui->widget_3->addItem("第四名");
    ui->widget_3->addItem("第五名");
    ui->widget_3->addItem("第六名");
    ui->widget_3->addItem("第七名");
    ui->widget_3->addItem("第八名");
    helpConnect(ui->widget_3);

    ui->widget_4->setBarRadious(5);
    ui->widget_4->setItemRadious(5);
    ui->widget_4->setSpace(20);
    ui->widget_4->setOrientation(Qt::Vertical);
    ui->widget_4->addItem("系统设置");
    ui->widget_4->addItem("记录查询");
    ui->widget_4->addItem("学生管理");
    ui->widget_4->addItem("教师管理");
    ui->widget_4->addItem("制卡刷卡");
    ui->widget_4->addItem("数据统计");
    ui->widget_4->addItem("用户推出");
    helpConnect(ui->widget_4);

    ui->widget_5->setBarRadious(5);
    ui->widget_5->setItemRadious(5);
    ui->widget_5->setSpace(20);
    ui->widget_5->setItemStartColor(QColor(254, 176, 42));
    ui->widget_5->setItemEndColor((QColor(225, 156, 37)));
    ui->widget_5->setOrientation(Qt::Vertical);
    ui->widget_5->addItem("系统设置");
    ui->widget_5->addItem("记录查询");
    ui->widget_5->addItem("学生管理");
    ui->widget_5->addItem("教师管理");
    ui->widget_5->addItem("制卡刷卡");
    ui->widget_5->addItem("数据统计");
    ui->widget_5->addItem("用户推出");
    helpConnect(ui->widget_5);

    ui->widget_6->setBarRadious(5);
    ui->widget_6->setItemRadious(5);
    ui->widget_6->setSpace(20);
    ui->widget_6->setItemStartColor(QColor(255, 0, 0));
    ui->widget_6->setItemEndColor((QColor(225, 20, 10)));
    ui->widget_6->setOrientation(Qt::Vertical);
    ui->widget_6->addItem("系统设置");
    ui->widget_6->addItem("记录查询");
    ui->widget_6->addItem("学生管理");
    ui->widget_6->addItem("教师管理");
    ui->widget_6->addItem("制卡刷卡");
    ui->widget_6->addItem("数据统计");
    ui->widget_6->addItem("用户推出");
    helpConnect(ui->widget_6);

    ui->widget_7->setBarRadious(5);
    ui->widget_7->setItemRadious(5);
    ui->widget_7->setSpace(20);
    ui->widget_7->setItemStartColor(QColor(191, 65, 249));
    ui->widget_7->setItemEndColor((QColor(187, 83, 217)));
    ui->widget_7->setOrientation(Qt::Vertical);
    ui->widget_7->addItem("系统设置");
    ui->widget_7->addItem("记录查询");
    ui->widget_7->addItem("学生管理");
    ui->widget_7->addItem("教师管理");
    ui->widget_7->addItem("制卡刷卡");
    ui->widget_7->addItem("数据统计");
    ui->widget_7->addItem("用户推出");
    helpConnect(ui->widget_7);

    ui->widget_8->setBarRadious(5);
    ui->widget_8->setItemRadious(5);
    ui->widget_8->setSpace(20);
    ui->widget_8->setItemStartColor(QColor(62, 139, 6));
    ui->widget_8->setItemEndColor((QColor(40, 139, 28)));
    ui->widget_8->setOrientation(Qt::Vertical);
    ui->widget_8->addItem("系统设置");
    ui->widget_8->addItem("记录查询");
    ui->widget_8->addItem("学生管理");
    ui->widget_8->addItem("教师管理");
    ui->widget_8->addItem("制卡刷卡");
    ui->widget_8->addItem("数据统计");
    ui->widget_8->addItem("用户推出");
    helpConnect(ui->widget_8);
}

SlideNavigationTest::~SlideNavigationTest()
{
    delete ui;
}

void SlideNavigationTest::helpConnect(SlideNavigation *widget)
{
    connectToFirst(widget);
    connectToLast(widget);
    connectToPrevious(widget);
    connectToNext(widget);
    connectToIndex(widget);
    connectEnableKeyMove(widget);
    widget->moveTo(0);
}

void SlideNavigationTest::connectToFirst(SlideNavigation *widget)
{
    connect(ui->toFirstBtn, SIGNAL(clicked()), widget, SLOT(moveToFirst()));
}

void SlideNavigationTest::connectToLast(SlideNavigation *widget)
{
    connect(ui->toLastBtn, SIGNAL(clicked()), widget, SLOT(moveToLast()));
}

void SlideNavigationTest::connectToPrevious(SlideNavigation *widget)
{
    connect(ui->previousBtn, SIGNAL(clicked()), widget, SLOT(moveToPrevious()));
}

void SlideNavigationTest::connectToNext(SlideNavigation *widget)
{
    connect(ui->nextBtn, SIGNAL(clicked()), widget, SLOT(moveToNext()));
}

void SlideNavigationTest::connectToIndex(SlideNavigation *widget)
{
    connect(ui->indexCb, SIGNAL(currentIndexChanged(int)), widget, SLOT(moveTo(int)));
}

void SlideNavigationTest::connectEnableKeyMove(SlideNavigation *widget)
{
    connect(ui->keyMoveCkb, SIGNAL(clicked(bool)), widget, SLOT(setEnableKeyMove(bool)));
}
