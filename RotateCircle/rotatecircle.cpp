#include "rotatecircle.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

RotateCircle::RotateCircle(QWidget *parent)
    : QWidget(parent)
{
    m_bgStartColor = QColor(65,65,65);
    m_bgEndColor = QColor(89,89,89);
    m_pie1StartColor = QColor(0,133,203);
    m_pie1EndColor = QColor(0,118,177);
    m_pie2StartColor = QColor(255,255,255);
    m_pie2EndColor = QColor(233,233,233);
    m_stepAngle = 5;
    m_clockwise = true;

    m_rotateAngle = 0;
    m_rotateTimer = new QTimer;
    m_rotateTimer->setInterval(20);
    connect(m_rotateTimer, SIGNAL(timeout()), this, SLOT(update()));
    m_rotateTimer->start();
}

RotateCircle::~RotateCircle()
{

}

void RotateCircle::setBackgroundStartColor(QColor color)
{
    if(color != m_bgStartColor)
    {
        m_bgStartColor = color;
        update();
    }
}

void RotateCircle::setBackgroundEndColor(QColor color)
{
    if(color != m_bgEndColor)
    {
        m_bgEndColor = color;
        update();
    }
}

void RotateCircle::setPieFirstStartColor(QColor color)
{
    if(color != m_pie1StartColor)
    {
        m_pie1StartColor = color;
        update();
    }
}

void RotateCircle::setPieFirstEndColor(QColor color)
{
    if(color != m_pie1EndColor)
    {
        m_pie1EndColor = color;
        update();
    }
}

void RotateCircle::setPieSecondStartColor(QColor color)
{
    if(color != m_pie2StartColor)
    {
        m_pie2StartColor = color;
        update();
    }
}

void RotateCircle::setPieSecondEndColor(QColor color)
{
    if(color != m_pie2EndColor)
    {
        m_pie2EndColor = color;
        update();
    }
}

void RotateCircle::setSetpAngle(int angle)
{
    if(angle != m_stepAngle)
    {
        m_stepAngle = angle;
        update();
    }
}

void RotateCircle::setClockwise(bool clockwise)
{
    if(clockwise != m_clockwise)
    {
        m_clockwise = clockwise;
        update();
    }
}

void RotateCircle::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.translate(width()/2.0, height()/2.0);

    p.rotate(m_rotateAngle);
    drawBackground(&p);
    drawCircle(&p);
    m_rotateAngle += m_clockwise?m_stepAngle:-m_stepAngle;
    m_rotateAngle %= 360;
}

void RotateCircle::drawBackground(QPainter *p)
{
    p->save();
    qreal radious = qMin(width(), height())/2.0;
    QPointF center(0, 0);
    QRadialGradient radialGradient(center, radious, center);
    radialGradient.setColorAt(0.0, m_bgStartColor);
    radialGradient.setColorAt(1.0, m_bgEndColor);
    p->setPen(Qt::NoPen);
    p->setBrush(radialGradient);
    p->drawEllipse(center, radious, radious);
    p->restore();
}

void RotateCircle::drawCircle(QPainter *p)
{
    p->save();
    qreal radious = qMin(width(), height())/2.0;
    radious *= 0.8;
    QRadialGradient radialGradient(QPointF(0,0), radious, QPointF(0,0));
    radialGradient.setColorAt(0.0, m_pie1StartColor);
    radialGradient.setColorAt(1.0, m_pie1EndColor);
    p->setPen(Qt::NoPen);
    p->setBrush(radialGradient);
    QRectF rect(-radious, -radious, 2*radious, 2*radious);
    p->drawPie(rect, 90*16, 90*16);
    p->drawPie(rect, 270*16, 90*16);
    radialGradient.setColorAt(0.0, m_pie2StartColor);
    radialGradient.setColorAt(1.0, m_pie2EndColor);
    p->setBrush(radialGradient);
    p->drawPie(rect, 0, 90*16);
    p->drawPie(rect, 180*16, 90*16);
    p->restore();
}
