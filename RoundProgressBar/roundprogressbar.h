#ifndef ROUNDPROGRESSBAR_H
#define ROUNDPROGRESSBAR_H

#include <QWidget>

#ifdef MSC
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT RoundProgressBar: public QWidget
#else
class RoundProgressBar : public QWidget
#endif
{
    Q_OBJECT


    Q_PROPERTY(double StartAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(RoundProgressBar::BarStyle BarStyle READ getBarStyle WRITE setBarStyle)

public:
    explicit RoundProgressBar(QWidget *parent = 0);
    ~RoundProgressBar();

    //进度条显示类型
    enum BarStyle
    {
        StyleDonut,//圆环
        StylePie,//饼状
        StyleLine,//线条
    };
    //起始角度
    static const int PositionLeft = 180;
    static const int PositionTop = 90;
    static const int PositionRight = 0;
    static const int PositionBottom = -90;

    double getStartAngle() const { return m_startAngle; }
    void setStartAngle(double angle);
    BarStyle getBarStyle() const { return m_barStyle; }
    void setBarStyle(BarStyle style);
    void setOutlinePenWidth(double penWidth);
    void setDataPenWidth(double penWidth);
    void setDataColors(const QGradientStops& stopPoints);
    void setFormat(const QString& format);
    void setDecimals(int count);
    void setClockwise(bool clockwise);

public slots:
    void setRange(double min, double max);
    void setValue(int val);
    void setValue(double val);
    void setBaseCircleVisible(bool visible);
    void setDataCircleVisible(bool visible);
    void setCenterCircleVisible(bool visible);
    void setTextVisible(bool visible);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void drawBackground(QPainter& p, const QRectF& baseRect);
    virtual void drawBase(QPainter& p, const QRectF& baseRect);
    virtual void drawValue(QPainter& p, const QRectF& baseRect, double value, double delta);
    virtual void calculateInnerRect(const QRectF& baseRect, double outerRadius, QRectF& innerRect, double& innerRadius);
    virtual void drawInnerBackground(QPainter& p, const QRectF& innerRect);
    virtual void drawText(QPainter& p, const QRectF& innerRect, double innerRadius, double value);
    virtual QString valueToText(double value) const;
    virtual void valueFormatChanged();

    virtual QSize minimumSizeHint() const { return QSize(32,32); }
    void rebuildDataBrushIfNeeded();

private:
    double m_min, m_max;//最小值,最大值
    double m_value;//当前值
    double m_startAngle;//起始角度
    BarStyle m_barStyle;//显示类型
    double m_outlinePenWidth, m_dataPenWidth;//外圆画笔宽度,数据圆画笔宽度(主要用在线条显示类型)
    QGradientStops m_gradientData;//渐变颜色(主要用在圆环和饼状显示类型)
    bool m_rebuildBrush;
    QString m_format;//文本显示格式
    int m_decimals;//小数点位数
    bool m_clockwise;//顺时针
    bool m_baseCircleVisible;//显示外圆
    bool m_dataCircleVisible;//显示数据圆
    bool m_centerCircleVisible;//显示内圆
    bool m_textVisible;//显示文字

    static const int UF_VALUE = 1;//文本格式-当前值
    static const int UF_PERCENT = 2;//文本格式-当前值百分比
    static const int UF_MAX = 4;//文本格式-最大值
    int m_updateFlags;

};

#endif // ROUNDPROGRESSBAR_H
