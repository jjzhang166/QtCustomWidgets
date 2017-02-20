#ifndef ZOOMCIRCLEWAIT_H
#define ZOOMCIRCLEWAIT_H

#include <QWidget>

#ifdef MSC
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT ZoomCircleWait: public QWidget
#else
class ZoomCircleWait : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(QColor Color READ getColor WRITE setColor)
    Q_PROPERTY(bool ZoomOut READ getZoomOut WRITE setZoomOut)
    Q_PROPERTY(int ZoomDelta READ getZoomDelta WRITE setZoomDelta)
    Q_PROPERTY(int MinRadious READ getMinRadious WRITE setMinRadious)
    Q_PROPERTY(int Radious READ getRadious WRITE setRadious)
public:
    explicit ZoomCircleWait(QWidget *parent = 0);

    QColor getColor() const { return m_color; }
    void setColor(QColor color);
    bool getZoomOut() const { return m_zoomOut; }
    void setZoomOut(bool zoomOut);
    int getZoomDelta() const { return m_zoomDelta; }
    void setZoomDelta(int delta);
    int getMinRadious() const { return m_minRadious; }
    void setMinRadious(int value);
    int getRadious() const { return m_radious; }
    void setRadious(int value);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
    void drawZoomCricleWait(QPainter& p);//缩放圆
//    QSize sizeHint() const { return QSize(100, 100); }
    QSize minimumSizeHint() const { return QSize(10, 10); }

private:
    QColor m_color;//前景色
    bool m_zoomOut;//是否缩小
    int m_zoomDelta;//缩放步进
    int m_radious;//当前半径
    int m_minRadious;//最小半径

    QTimer* m_timer;

    void fixRaidous(int max);
};

#endif // ZOOMCIRCLEWAIT_H
