#ifndef CURVECHART_H
#define CURVECHART_H

#include <QWidget>

#ifdef MSC
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT CurveChart: public QWidget
#else
class CurveChart : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor BackgroundStartColor READ BackgroundStartColor WRITE setBackgroundStartColor)
    Q_PROPERTY(QColor BackgroundEndColor READ BackgroundEndColor WRITE setBackgroundEndColor)
    Q_PROPERTY(QColor TextColor READ TextColor WRITE setTextColor)
    Q_PROPERTY(QColor PointColor READ PointColor WRITE setPointColor)
    Q_PROPERTY(qreal Min READ Min WRITE setMax)
    Q_PROPERTY(qreal Max READ Max WRITE setMax)
    Q_PROPERTY(qreal StepHoriginal READ StepHoriginal WRITE setStepHoriginal)
    Q_PROPERTY(qreal StepVertical READ StepVertical WRITE setStepVertical)
    Q_PROPERTY(qreal ChartLeftMargin READ ChartLeftMargin WRITE setChartLeftMargin)
    Q_PROPERTY(qreal ChartTopMargin READ ChartTopMargin WRITE setChartTopMargin)
    Q_PROPERTY(qreal ChartRightMargin READ ChartRightMargin WRITE setChartRightMargin)
    Q_PROPERTY(qreal ChartBottomMargin READ ChartBottomMargin WRITE setChartBottomMargin)
    Q_PROPERTY(QString DataString READ DataString WRITE addDataStr)

public:
    CurveChart(QWidget *parent = 0);
    ~CurveChart();

    QColor BackgroundStartColor() const { return m_bgStartColor; }
    void setBackgroundStartColor(QColor color);
    QColor BackgroundEndColor() const { return m_bgEndColor; }
    void setBackgroundEndColor(QColor color);
    QColor TextColor() const { return m_textColor; }
    void setTextColor(QColor color);
    QColor PointColor() const { return m_pointColor; }
    void setPointColor(QColor color);
    qreal Min() const { return m_min; }
    void setMin(qreal min);
    qreal Max() const { return m_max; }
    void setMax(qreal max);
    qreal StepHoriginal() const { return m_stepH; }
    void setStepHoriginal(qreal val);
    qreal StepVertical() const { return m_stepV; }
    void setStepVertical(qreal val);
    qreal ChartLeftMargin() const { return m_chartLeftMargin; }
    void setChartLeftMargin(qreal margin);
    qreal ChartTopMargin() const { return m_chartTopMargin; }
    void setChartTopMargin(qreal margin);
    qreal ChartRightMargin() const { return m_chartRightMargin; }
    void setChartRightMargin(qreal margin);
    qreal ChartBottomMargin() const { return m_chartBottomMargin; }
    void setChartBottomMargin(qreal margin);
    QString DataString() const;
    void addDataStr(QString str);
    void addData(qreal val);

public slots:
    void setTitle(QString str);
    void setShowLine(bool show);
    void setShowPoint(bool show);
    void setShowPointBackground(bool show);
    void clearData();

protected:
    void paintEvent(QPaintEvent *);
    void drawBackground(QPainter* p);
    void drawTitle(QPainter* p);
    void drawBorder(QPainter* p);
    void drawText(QPainter* p);
    void drawPoints(QPainter* p);

    QSize minimumSizeHint() const { return QSize(400, 250); }

private:
    void setRange(qreal min, qreal max);

private:
    QColor m_bgStartColor;//背景颜色
    QColor m_bgEndColor;
    QColor m_textColor;//标题/文本/边框颜色
    QColor m_pointColor;//统计点颜色
    QString m_title;//标题文本
    qreal m_min;//最小值
    qreal m_max;//最大值
    qreal m_stepH;//水平间隔
    qreal m_stepV;//垂直间隔
    qreal m_chartLeftMargin;//图表左边距
    qreal m_chartTopMargin;
    qreal m_chartRightMargin;
    qreal m_chartBottomMargin;
    int m_pointRadious;//数据点半径
    bool m_showLine;//显示刻度线
    bool m_showPoint;//显示数据点
    bool m_showPointBg;//显示数据点覆盖背景

    QVector<qreal> m_points;
};

#endif // CURVECHART_H
