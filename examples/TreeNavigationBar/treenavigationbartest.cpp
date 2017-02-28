#include "treenavigationbartest.h"
#include "ui_treenavigationbartest.h"

TreeNavigationBarTest::TreeNavigationBarTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeNavigationBarTest)
{
    ui->setupUi(this);
}

TreeNavigationBarTest::~TreeNavigationBarTest()
{
    delete ui;
}
