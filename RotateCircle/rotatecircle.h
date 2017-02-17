#ifndef ROTATECIRCLE_H
#define ROTATECIRCLE_H

#include <QWidget>

class RotateCircle : public QWidget
{
    Q_OBJECT

public:
    RotateCircle(QWidget *parent = 0);
    ~RotateCircle();

    void setBackgroundStartColor(QColor color);
    void setBackgroundEndColor(QColor color);
    void setPieFirstStartColor(QColor color);
    void setPieFirstEndColor(QColor color);
    void setPieSecondStartColor(QColor color);
    void setPieSecondEndColor(QColor color);
    void setSetpAngle(int angle);//设置每次旋转角度
    void setClockwise(bool clockwise);//顺时针旋转

protected:
    void paintEvent(QPaintEvent *);
    void drawBackground(QPainter* p);
    void drawCircle(QPainter* p);

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
