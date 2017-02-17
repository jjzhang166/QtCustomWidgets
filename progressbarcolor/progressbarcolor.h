#ifndef PROGRESSBARCOLOR_H
#define PROGRESSBARCOLOR_H

/**
 * 多彩进度条控件 作者:feiyangqingyun(QQ:517216493) 2016-10-28
 * 1:可设置精确度/步长/圆角角度
 * 2:可设置范围值和当前值
 * 3:可设置前景色背景色等各种颜色
 */

#include <QWidget>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT ProgressBarColor : public QWidget
#else
class ProgressBarColor : public QWidget
#endif

{
	Q_OBJECT	
	Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
	Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
	Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

	Q_PROPERTY(double step READ getStep WRITE setStep)
	Q_PROPERTY(double space READ getSpace WRITE setSpace)
	Q_PROPERTY(double radius READ getRadius WRITE setRadius)

	Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
	Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

	Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
	Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

	Q_PROPERTY(QColor barBgColor READ getBarBgColor WRITE setBarBgColor)
	Q_PROPERTY(QColor barColor READ getBarColor WRITE setBarColor)

public:
	explicit ProgressBarColor(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawBar(QPainter *painter);

private:	
	double maxValue;                //最小值
	double minValue;                //最大值
    double value;                   //目标值
	int precision;                  //精确度,小数点后几位

	int step;                       //步长
	int space;                      //间距
	int radius;                     //圆角角度

	QColor bgColorStart;            //背景渐变开始颜色
	QColor bgColorEnd;              //背景渐变结束颜色

	QColor lineColor;               //线条颜色
	QColor textColor;               //文本颜色

	QColor barBgColor;              //进度背景颜色
	QColor barColor;                //进度颜色

public:	
	double getMinValue()            const;
	double getMaxValue()            const;
    double getValue()               const;
	int getPrecision()              const;

	int getStep()                   const;
	int getSpace()                  const;
	int getRadius()                 const;

	QColor getBgColorStart()        const;
	QColor getBgColorEnd()          const;

	QColor getLineColor()           const;
	QColor getTextColor()           const;

	QColor getBarBgColor()          const;
	QColor getBarColor()            const;

	QSize sizeHint()                const;
	QSize minimumSizeHint()         const;

public Q_SLOTS:
	//设置范围值
	void setRange(double minValue, double maxValue);
	void setRange(int minValue, int maxValue);

	//设置最大最小值
	void setMinValue(double minValue);
	void setMaxValue(double maxValue);

	//设置目标值
	void setValue(double value);
	void setValue(int value);

	//设置精确度
	void setPrecision(int precision);

	//设置步长
	void setStep(int step);
	//设置间距
	void setSpace(int space);
	//设置圆角角度
	void setRadius(int radius);

	//设置背景颜色
	void setBgColorStart(const QColor &bgColorStart);
	void setBgColorEnd(const QColor &bgColorEnd);

	//设置线条颜色
	void setLineColor(QColor lineColor);
	//设置文本颜色
	void setTextColor(QColor textColor);
	//设置进度颜色
	void setBarBgColor(QColor barBgColor);
	void setBarColor(QColor barColor);

signals:
	void valueChanged(double value);
};

#endif // PROGRESSBARCOLOR_H
