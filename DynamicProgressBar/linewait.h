#ifndef LINEWAIT_H
#define LINEWAIT_H

#include <QWidget>

#ifdef MSC
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT LineWait: public QWidget
#else
class LineWait : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(QColor Color READ getColor WRITE setColor)
    Q_PROPERTY(bool ClockwiseRotate READ getClockwiseRotate WRITE setClockwiseRotate)
    Q_PROPERTY(int RotateDelta READ getRotateDelta WRITE setRotateDelta)
public:
    explicit LineWait(QWidget *parent = 0);

    QColor getColor() const { return m_color; }
    void setColor(QColor color);
    bool getClockwiseRotate() const { return m_clockwiseRotate; }
    int getRotateDelta() const { return m_rotateDelta; }

signals:

public slots:
    void setClockwiseRotate(bool clockwise);
    void setRotateDelta(int delta);

protected:
    void paintEvent(QPaintEvent *);
    void drawLineWait(QPainter& p);//圆形等待
    QSize sizeHint() const { return QSize(100, 100); }

private:
    QColor m_color;
    bool m_clockwiseRotate;//顺时针旋转
    int m_rotateDelta;//旋转步进角度

    int m_rotateAngle;//旋转角度
    QTimer* m_timer;
};

#endif // LINEWAIT_H
