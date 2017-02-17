#ifndef FRMPROGRESSBARCOLOR_H
#define FRMPROGRESSBARCOLOR_H

#include <QWidget>

namespace Ui
{
class frmProgressBarColor;
}

class frmProgressBarColor : public QWidget
{
	Q_OBJECT

public:
	explicit frmProgressBarColor(QWidget *parent = 0);
	~frmProgressBarColor();

private:
	Ui::frmProgressBarColor *ui;
};

#endif // FRMPROGRESSBARCOLOR_H
