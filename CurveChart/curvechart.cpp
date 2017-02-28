#include "curvechart.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>

CurveChart::CurveChart(QWidget *parent)
    : QWidget(parent)
{
    m_bgStartColor = QColor(79, 79, 79);
    m_bgEndColor = QColor(51, 51, 51);
    m_textColor = QColor(Qt::white);
    m_pointColor = QColor(38, 114, 179);
    m_min = 0;
    m_max = 100;
    m_stepH = 10;
    m_stepV = 10;
    m_chartLeftMargin = 50;
    m_chartTopMargin = 50;
    m_chartRightMargin = 10;
    m_chartBottomMargin = 10;
    m_pointRadious = 2;
    m_showLine = true;
    m_showPoint = true;
    m_showPointBg = true;
}

CurveChart::~CurveChart()
{

}

void CurveChart::setBackgroundStartColor(QColor color)
{
    if(color != m_bgStartColor)
    {
        m_bgStartColor = color;
        update();
    }
}

void CurveChart::setBackgroundEndColor(QColor color)
{
    if(color != m_bgEndColor)
    {
        m_bgEndColor = color;
        update();
    }
}

void CurveChart::setTextColor(QColor color)
{
    if(color != m_textColor)
    {
        m_textColor = color;
        update();
    }
}

void CurveChart::setPointColor(QColor color)
{
    if(color != m_pointColor)
    {
        m_pointColor = color;
        update();
    }
}

void CurveChart::setMin(qreal min)
{
    setRange(min, m_max);
}

void CurveChart::setMax(qreal max)
{
    setRange(m_min, max);
}

void CurveChart::setStepHoriginal(qreal val)
{
    if(val != m_stepH)
    {
        m_stepH = val;
        update();
    }
}

void CurveChart::setStepVertical(qreal val)
{
    if(val != m_stepV)
    {
        m_stepV = val;
        update();
    }
}

void CurveChart::setChartLeftMargin(qreal margin)
{
    if(margin>=0 && margin != m_chartLeftMargin)
    {
        m_chartLeftMargin = margin;
        update();
    }
}

void CurveChart::setChartTopMargin(qreal margin)
{
    if(margin>=0 && margin != m_chartTopMargin)
    {
        m_chartTopMargin = margin;
        update();
    }
}

void CurveChart::setChartRightMargin(qreal margin)
{
    if(margin>=0 && margin != m_chartRightMargin)
    {
        m_chartRightMargin = margin;
        update();
    }
}

void CurveChart::setChartBottomMargin(qreal margin)
{
    if(margin>=0 && margin != m_chartBottomMargin)
    {
        m_chartBottomMargin = margin;
        update();
    }
}

QString CurveChart::DataString() const
{
    QStringList points;
    for(int i=0; i<m_points.size(); ++i)
    {
        points << QString("%1").arg(m_points[i]);
    }
    return points.join("|");
}

void CurveChart::addDataStr(QString str)
{
    clearData();
    QStringList dataList = str.split("|");
    foreach(QString valStr, dataList)
    {
        bool ok;
        double val = valStr.toDouble(&ok);
        if(ok)
        {
            addData(val);
        }
    }
}

void CurveChart::addData(qreal val)
{
    int maxNum = qFloor((width()-m_chartLeftMargin-m_chartRightMargin)/m_stepH);
    if(maxNum < 0) { return; }
    if(m_points.size()>maxNum)
    {
        m_points.pop_front();
    }
    m_points.push_back(val);
    update();
}

void CurveChart::setTitle(QString str)
{
    if(str != m_title)
    {
        m_title = str;
        update();
    }
}

void CurveChart::setShowLine(bool show)
{
    if(show != m_showLine)
    {
        m_showLine = show;
        update();
    }
}

void CurveChart::setShowPoint(bool show)
{
    if(show != m_showPoint)
    {
        m_showPoint = show;
        update();
    }
}

void CurveChart::setShowPointBackground(bool show)
{
    if(show != m_showPointBg)
    {
        m_showPointBg = show;
        update();
    }
}

void CurveChart::clearData()
{
    if(m_points.size()>0)
    {
        m_points.clear();
        update();
    }
}

void CurveChart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    drawBackground(&painter);
    drawTitle(&painter);
    drawBorder(&painter);
    drawText(&painter);
    drawPoints(&painter);
}

void CurveChart::drawBackground(QPainter *p)
{
    p->save();
    QLinearGradient linearGradient(QPointF(0,0), QPointF(0,height()));
    linearGradient.setColorAt(0.0, m_bgStartColor);
    linearGradient.setColorAt(1.0, m_bgEndColor);
    p->setPen(Qt::NoPen);
    p->setBrush(linearGradient);
    p->drawRect(rect());
    p->restore();
}

void CurveChart::drawTitle(QPainter *p)
{
    p->save();
    QPointF topLeft(0, 0);
    QPointF bottomRight(width(), m_chartTopMargin);
    QRectF titleRect(topLeft, bottomRight);
    p->setPen(m_textColor);
    p->drawText(titleRect, Qt::AlignCenter, m_title);
    p->restore();
}

void CurveChart::drawBorder(QPainter *p)
{
    p->save();
    //画边框
    QPointF topLeft(m_chartLeftMargin, m_chartTopMargin);
    QPointF bottomRight(width()-m_chartRightMargin, height()-m_chartBottomMargin);
    QRectF borderRect(topLeft, bottomRight);
    p->setPen(m_textColor);
    p->drawRect(borderRect);
    //画线条
    if(m_showLine)
    {
        QPen pen = p->pen();
        pen.setStyle(Qt::DotLine);
        p->setPen(pen);
        qreal count = (m_max-m_min)/m_stepV;
        qreal stepY = borderRect.height()/count;
        qreal dy = m_chartTopMargin+stepY;
        QPointF p1,p2;
        while(dy<borderRect.bottom())
        {
            p1 = QPointF(borderRect.left(), dy);
            p2 = QPointF(borderRect.right(), dy);
            p->drawLine(p1, p2);
            dy += stepY;
        }
    }
    p->restore();
}

void CurveChart::drawText(QPainter *p)
{
    p->save();
    qreal textMargin = 5;
    QFontMetrics fm = fontMetrics();
    int textHeight = fm.height();
    QPointF topLeft(m_chartLeftMargin, m_chartTopMargin);
    QPointF bottomRight(width()-m_chartRightMargin, height()-m_chartBottomMargin);
    QRectF borderRect(topLeft, bottomRight);
    qreal count = (m_max-m_min)/m_stepV;
    qreal stepY = borderRect.height()/count;
    qreal dy = m_chartTopMargin;
    QPointF pos;
    qreal val = m_max;
    p->setPen(m_textColor);
    while(val >= m_min)
    {
        QString text = QString("%1").arg(val);
        int textWidth = fm.width(text);
        pos = QPointF(m_chartLeftMargin-textMargin-textWidth, dy+textHeight/2.0);
        p->drawText(pos, text);
        dy += stepY;
        val -= m_stepV;
    }
    p->restore();
}

void CurveChart::drawPoints(QPainter *p)
{
    if(m_points.isEmpty())
        return;
    p->save();
    QVector<QPointF> posVec;

    qreal dx = width()-m_chartRightMargin;
    qreal dy = height()-m_chartBottomMargin;
    qreal percent = (height()-m_chartTopMargin-m_chartBottomMargin)/(m_max-m_min);
    posVec.append(QPointF(dx, dy));//结束点
    QVector<qreal>::reverse_iterator it;
    for(it = m_points.rbegin(); it!= m_points.rend(); ++it)
    {
        if(dx<m_chartLeftMargin)
        {
            break;
        }
        posVec.append(QPointF(dx, dy-(*it-m_min)*percent));
        dx -= m_stepH;
    }
    posVec.append(QPointF(dx<m_chartLeftMargin?m_chartLeftMargin:dx, dy));
    if(!m_showPointBg)
    {//不显示背景的话去除起始点和结束点
        posVec.pop_front();
        posVec.pop_back();
    }
    //画圆点
    if(m_showPoint)
    {
        int radious = m_stepH/2;
        p->save();
        p->setPen(Qt::NoPen);
        p->setBrush(m_pointColor);
        for(int i=0; i<posVec.size(); ++i)
        {
            p->drawEllipse(posVec[i], radious, radious);
        }
        p->restore();
    }
    //画线
    p->setPen(m_pointColor);
    if(m_showPointBg)
    {
        p->setBrush(m_pointColor);
        p->setOpacity(0.5);
        p->drawConvexPolygon(QPolygonF(posVec));
    }
    else
    {
        p->drawPolyline(QPolygonF(posVec));
    }
    p->restore();
}

void CurveChart::setRange(qreal min, qreal max)
{
    if(min>max)
        qSwap(min, max);
    m_min = min;
    m_max = max;
    update();
}
