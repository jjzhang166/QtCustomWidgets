#ifndef DONUTWAIT_H
#define DONUTWAIT_H

#include <QWidget>

#ifdef MSC
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT DonutWait: public QWidget
#else
class DonutWait : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(QColor FrontColor READ getFrontColor WRITE setFrontColor)
    Q_PROPERTY(QColor BackColor READ getBackColor WRITE setBackColor)
    Q_PROPERTY(bool ClockwiseRotate READ getClockwiseRotate WRITE setClockwiseRotate)
    Q_PROPERTY(int RotateDelta READ getRotateDelta WRITE setRotateDelta)

public:
    explicit DonutWait(QWidget *parent = 0);

    QColor getFrontColor() const { return m_frontColor; }
    void setFrontColor(QColor color);
    QColor getBackColor() const { return m_backColor; }
    void setBackColor(QColor color);
    bool getClockwiseRotate() { return m_clockwiseRotate; }
    void setClockwiseRotate(bool clockwise);
    int getRotateDelta() const { return m_rotateDelta; }
    void setRotateDelta(int delta);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
    void drawDonutWait(QPainter& p);//环形
    void drawText(QPainter& p);
    QSize sizeHint() const { return QSize(100, 100); }

private:
    QColor m_frontColor;//前景色
    QColor m_backColor;//背景色
    bool m_clockwiseRotate;//顺时针旋转
    int m_rotateDelta;//旋转步进角度

    int m_rotateAngle;//旋转角度
    QTimer* m_timer;
};

#endif // DONUTWAIT_H
