#include "frmprogressbarcolor.h"
#include "ui_frmprogressbarcolor.h"
#include "flatui.h"

frmProgressBarColor::frmProgressBarColor(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::frmProgressBarColor)
{
	ui->setupUi(this);	
    FlatUI::Instance()->setSliderQss(ui->horizontalSlider1, "#505050", "#1ABC9C", "#1ABC9C");
    FlatUI::Instance()->setSliderQss(ui->horizontalSlider2, "#505050", "#E74C3C", "#E74C3C");
    FlatUI::Instance()->setSliderQss(ui->horizontalSlider3, "#505050", "#31495A", "#31495A");
}

frmProgressBarColor::~frmProgressBarColor()
{
	delete ui;
}
