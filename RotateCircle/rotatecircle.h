#ifndef ROTATECIRCLE_H
#define ROTATECIRCLE_H

#include <QWidget>

#ifdef MSC
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT RotateCircle: public QWidget
        #else
class RotateCircle : public QWidget
        #endif
{
    Q_OBJECT
    Q_PROPERTY(QColor BackgroundStartColor READ getBackgroundStartColor WRITE setBackgroundStartColor)
    Q_PROPERTY(QColor BackgroundEndColor READ getBackgroundEndColor WRITE setBackgroundEndColor)
    Q_PROPERTY(QColor PieFirstStartColor READ getPieFirstStartColor WRITE setPieFirstStartColor)
    Q_PROPERTY(QColor PieFirstEndColor READ getPieFirstEndColor WRITE setPieFirstEndColor)
    Q_PROPERTY(QColor PieSecondStartColor READ getPieSecondStartColor WRITE setPieSecondStartColor)
    Q_PROPERTY(QColor PieSecondEndColor READ getPieSecondEndColor WRITE setPieSecondEndColor)
    Q_PROPERTY(int SetpAngle READ getSetpAngle WRITE setSetpAngle)
    Q_PROPERTY(bool Clockwise READ getClockwise WRITE setClockwise)

public:
    RotateCircle(QWidget *parent = 0);
    ~RotateCircle();

    QColor getBackgroundStartColor() const { return m_bgStartColor; }
    void setBackgroundStartColor(QColor color);
    QColor getBackgroundEndColor() const { return m_bgEndColor; }
    void setBackgroundEndColor(QColor color);
    QColor getPieFirstStartColor() const { return m_pie1StartColor; }
    void setPieFirstStartColor(QColor color);
    QColor getPieFirstEndColor() const { return m_pie1EndColor; }
    void setPieFirstEndColor(QColor color);
    QColor getPieSecondStartColor() const { return m_pie2StartColor; }
    void setPieSecondStartColor(QColor color);
    QColor getPieSecondEndColor() const { return m_pie2EndColor; }
    void setPieSecondEndColor(QColor color);
    int getSetpAngle() const { return m_stepAngle; }
    void setSetpAngle(int angle);//设置每次旋转角度
    bool getClockwise() const { return m_clockwise; }

signals:

public slots:
    void setClockwise(bool clockwise);//顺时针旋转

protected:
    void paintEvent(QPaintEvent *);
    void drawBackground(QPainter* p);
    void drawCircle(QPainter* p);
    QSize sizeHint() const { return QSize(100, 100); }

private:
    QColor m_bgStartColor;//背景色
    QColor m_bgEndColor;
    QColor m_pie1StartColor;
    QColor m_pie1EndColor;
    QColor m_pie2StartColor;
    QColor m_pie2EndColor;
    int m_stepAngle;//旋转步进角度
    bool m_clockwise;//顺时针旋转

    int m_rotateAngle;//当前旋转角度
    QTimer* m_rotateTimer;
};

#endif // ROTATECIRCLE_H
