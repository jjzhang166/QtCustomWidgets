#pragma execution_character_set("utf-8")
#include "slidenavigation.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QtMath>
#include <QDebug>

SlideNavigation::SlideNavigation(QWidget *parent)
    : QWidget(parent)
{
    m_barStartColor = QColor(121,121,121);
    m_barEndColor = QColor(78,78,78);
    m_itemStartColor = QColor(46,132,243);
    m_itemEndColor = QColor(39,110,203);
    m_itemTextColor = Qt::white;
    m_itemLineColor = QColor(255,107,107);
    m_barRadious = 0;
    m_itemRadious = 0;
    m_space = 25;
    m_itemLineWidth = 3;
    m_itemLineStyle = ItemLineStyle::None;
    m_orientation = Qt::Horizontal;
    m_enableKeyMove = false;
    m_totalTextWidth = 0;
    m_totalTextHeight = 0;
    m_currentItemIndex = -1;
    m_fixed = false;

    setAttribute(Qt::WA_TranslucentBackground);
    m_slideTimer = new QTimer(this);
    m_slideTimer->setInterval(10);
    connect(m_slideTimer, SIGNAL(timeout()), this, SLOT(doSlide()));
    m_shakeTimer = new QTimer(this);
    m_shakeTimer->setInterval(10);
    connect(m_shakeTimer, SIGNAL(timeout()), this, SLOT(doShake()));
    setFocusPolicy(Qt::ClickFocus);
}

SlideNavigation::~SlideNavigation()
{

}

void SlideNavigation::addItem(QString str)
{
    if(str.isEmpty())
        return;
    QMap<int, QPair<QString,QRectF> >::iterator it = m_itemList.begin();
    while(it != m_itemList.end())
    {
        QPair<QString, QRectF>& itemData = it.value();
        if(str == itemData.first)
            return;
        ++it;
    }
    QFont f = font();
    QFontMetrics fm(f);
    int textWidth = fm.width(str);
    int textHeight = fm.height();
    int itemCount = m_itemList.size();
    if(itemCount > 0)
    {
        QPointF topLeft, bottomRight;
        if(m_orientation == Qt::Horizontal)
        {
            topLeft = QPointF(m_totalTextWidth,0);
            m_totalTextWidth += textWidth+m_space;
            bottomRight = QPointF(m_totalTextWidth, m_totalTextHeight);
        }
        else
        {
            topLeft = QPointF(0, m_totalTextHeight);
            m_totalTextHeight += textHeight+m_space;
            bottomRight = QPointF(m_totalTextWidth, m_totalTextHeight);
        }
        QRectF textRect(topLeft, bottomRight);
        m_itemList.insert(itemCount, qMakePair(str, textRect));
    }
    else
    {
        if(m_orientation == Qt::Horizontal)
        {
            m_totalTextWidth = textWidth+m_space;
            m_totalTextHeight = textHeight+m_space;//水平方向,水平占1个m_space,竖直占1个m_space
        }
        else
        {
            m_totalTextWidth = textWidth+2*m_space;//竖直方向,水平占2个m_space,竖直占1个m_space
            m_totalTextHeight = textHeight+m_space;
        }
        QPointF topLeft(0.0, 0.0);
        QPointF bottomRight(m_totalTextWidth, m_totalTextHeight);
        QRectF textRect(topLeft, bottomRight);
        m_itemList.insert(itemCount, qMakePair(str, textRect));
    }
    setMinimumSize(m_totalTextWidth, m_totalTextHeight);
    if(m_fixed)
    {
        if(m_orientation == Qt::Horizontal)
            setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);//固定高度
        else
            setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);//固定宽度
    }
    update();
}

void SlideNavigation::setBarStartColor(QColor color)
{
    if(color != m_barStartColor)
    {
        m_barStartColor = color;
        update();
    }
}

void SlideNavigation::setBarEndColor(QColor color)
{
    if(color != m_barEndColor)
    {
        m_barEndColor = color;
        update();
    }
}

void SlideNavigation::setItemStartColor(QColor color)
{
    if(color != m_itemStartColor)
    {
        m_itemStartColor = color;
        update();
    }
}

void SlideNavigation::setItemEndColor(QColor color)
{
    if(color != m_itemEndColor)
    {
        m_itemEndColor = color;
        update();
    }
}

void SlideNavigation::setItemTextColor(QColor color)
{
    if(color != m_itemTextColor)
    {
        m_itemTextColor = color;
        update();
    }
}

void SlideNavigation::setItemLineColor(QColor color)
{
    if(color != m_itemLineColor)
    {
        m_itemLineColor = color;
        update();
    }
}

void SlideNavigation::setBarRadious(int radious)
{
    if(radious>=0 && radious != m_barRadious)
    {
        m_barRadious = radious;
        update();
    }
}

void SlideNavigation::setItemRadious(int radious)
{
    if(radious>=0 && radious != m_itemRadious)
    {
        m_itemRadious = radious;
        update();
    }
}

void SlideNavigation::setSpace(int space)
{
    if(space>=0 && space != m_space)
    {
        m_space = space;
        update();
    }
}

void SlideNavigation::setItemLineWidth(int width)
{
    if(width>=0 && width != m_itemLineWidth)
    {
        m_itemLineWidth = width;
        update();
    }
}

void SlideNavigation::setItemLineStyle(SlideNavigation::ItemLineStyle style)
{
    if(style != m_itemLineStyle)
    {
        m_itemLineStyle = style;
        update();
    }
}

void SlideNavigation::setOrientation(Qt::Orientation orientation)
{
    if(orientation != m_orientation)
    {
        m_orientation = orientation;
        update();
    }
}

void SlideNavigation::setFixed(bool fixed)
{
    if(fixed != m_fixed)
    {
        m_fixed = fixed;
        update();
    }
}

void SlideNavigation::setEnableKeyMove(bool enable)
{
    if(enable != m_enableKeyMove)
    {
        m_enableKeyMove = enable;
    }
}

void SlideNavigation::moveToFirst()
{
    moveTo(0);
}

void SlideNavigation::moveToLast()
{
    moveTo(m_itemList.size()-1);
}

void SlideNavigation::moveToPrevious()
{
    moveTo(m_currentItemIndex-1);
}

void SlideNavigation::moveToNext()
{
    moveTo(m_currentItemIndex+1);
}

void SlideNavigation::moveTo(int index)
{
    if(index>=0 && index<m_itemList.size() && index!=m_currentItemIndex)
    {
        emit itemClicked(index, m_itemList[index].first);
        if(index == m_currentItemIndex)
            return;
        if(m_currentItemIndex == -1)
            m_startRect = m_itemList[index].second;
        m_forward = index > m_currentItemIndex;
        m_currentItemIndex = index;
        m_stopRect = m_itemList[index].second;
        m_slideTimer->start();
    }
}

void SlideNavigation::moveTo(QString str)
{
    QMap<int, QPair<QString, QRectF> >::iterator it = m_itemList.begin();
    for(; it!=m_itemList.end(); ++it)
    {
        if(it.value().first == str)
        {
            int targetIndex = it.key();
            if(targetIndex == m_currentItemIndex)
                return;
            moveTo(targetIndex);
            break;
        }
    }
}

void SlideNavigation::moveTo(QPointF point)
{
    QMap<int, QPair<QString, QRectF> >::iterator it = m_itemList.begin();
    for(; it!=m_itemList.end(); ++it)
    {
        if(it.value().second.contains(point))
        {
            int targetIndex = it.key();
            if(targetIndex == m_currentItemIndex)
                return;
            moveTo(targetIndex);
            break;
        }
    }
}

void SlideNavigation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    drawBarBackground(&painter);
    drawItemBackground(&painter);
    drawItemLine(&painter);
    drawText(&painter);
}

void SlideNavigation::resizeEvent(QResizeEvent *)
{
    adjuseItemSize();
}

void SlideNavigation::mousePressEvent(QMouseEvent *event)
{
    QMap<int, QPair<QString, QRectF> >::iterator it = m_itemList.begin();
    for(; it!=m_itemList.end(); ++it)
    {
        if(it.value().second.contains(event->pos()))
        {
            int targetIndex = it.key();
            emit itemClicked(targetIndex, it.value().first);
            if(targetIndex == m_currentItemIndex)
                return;
            if(m_currentItemIndex == -1)
            {
                m_startRect = it.value().second;
            }
            m_forward = targetIndex > m_currentItemIndex;
            m_currentItemIndex = targetIndex;
            m_stopRect = it.value().second;
            m_slideTimer->start();
            break;
        }
    }
}

void SlideNavigation::keyPressEvent(QKeyEvent *event)
{
    if(!m_enableKeyMove)
    {
        QWidget::keyPressEvent(event);
        return;
    }
    switch (event->key()) {
    case Qt::Key_Home:
        moveToFirst();
        break;
    case Qt::Key_End:
        moveToLast();
        break;
    case Qt::Key_Up:
    case Qt::Key_Left:
        moveToPrevious();
        break;
    case Qt::Key_Down:
    case Qt::Key_Right:
        moveToNext();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

void SlideNavigation::drawBarBackground(QPainter *p)
{
    p->save();
    p->setPen(Qt::NoPen);
    QLinearGradient linerGradient(QPointF(0,0), QPointF(0,height()));
    linerGradient.setColorAt(0.0, m_barStartColor);
    linerGradient.setColorAt(1.0, m_barEndColor);
    p->setBrush(linerGradient);
    p->drawRoundedRect(rect(), m_barRadious, m_barRadious);
    p->restore();
}

void SlideNavigation::drawItemBackground(QPainter *p)
{
    if(m_startRect.isNull())
        return;
    p->save();
    QLinearGradient linerGradient(m_startRect.topLeft(), m_startRect.bottomRight());
    linerGradient.setColorAt(0.0, m_itemStartColor);
    linerGradient.setColorAt(1.0, m_itemEndColor);
    p->setPen(Qt::NoPen);
    p->setBrush(linerGradient);
    p->drawRoundedRect(m_startRect, m_itemRadious, m_itemRadious);
    p->restore();
}

void SlideNavigation::drawItemLine(QPainter *p)
{
    if(m_startRect.isNull())
        return;
    QPointF p1,p2;
    switch(m_itemLineStyle)
    {
    case None:
        return;
        break;
    case ItemTop:
        p1 = m_startRect.topLeft();
        p2 = m_startRect.topRight();
        break;
    case ItemRight:
        p1 = m_startRect.topRight();
        p2 = m_startRect.bottomRight();
        break;
    case ItemBottom:
        p1 = m_startRect.bottomLeft();
        p2 = m_startRect.bottomRight();
        break;
    case ItemLeft:
        p1 = m_startRect.topLeft();
        p2 = m_startRect.bottomLeft();
        break;
    case ItemRect:
        p1 = m_startRect.topLeft();
        p2 = m_startRect.bottomRight();
        break;
    default:
        return;
        break;
    }
    p->save();
    QPen linePen;
    linePen.setColor(m_itemLineColor);
    linePen.setWidth(m_itemLineWidth);
    p->setPen(linePen);
    if(m_itemLineStyle == ItemRect)
    {
        p->drawRoundedRect(QRectF(p1, p2), m_itemRadious, m_itemRadious);
    }
    else
    {
        p->drawLine(p1, p2);
    }
    p->restore();
}

void SlideNavigation::drawText(QPainter *p)
{
    p->save();
    p->setPen(m_itemTextColor);
    QMap<int, QPair<QString,QRectF> >::iterator it = m_itemList.begin();
    while(it != m_itemList.end())
    {
        QPair<QString, QRectF>& itemData = it.value();
        p->drawText(itemData.second, Qt::AlignCenter, itemData.first);
        ++it;
    }
    p->restore();
}

void SlideNavigation::adjuseItemSize()
{
    if(m_fixed)
    {//针对固定大小的不对Item的位置进行调整
        return;
    }
    qreal addWidth, addHeight;
    if(m_orientation == Qt::Horizontal)
    {
        addWidth = 1.0*(width()-m_totalTextWidth)/m_itemList.size();
        addHeight = 1.0*(height()-m_totalTextHeight);
    }
    else
    {
        addWidth = 1.0*(width()-m_totalTextWidth);
        addHeight = 1.0*(height()-m_totalTextHeight)/m_itemList.size();
    }
    int itemCount = m_itemList.size();
    qreal dx = 0;
    qreal dy = 0;
    QPointF topLeft, bottomRight;
    for(int i=0; i<itemCount; ++i)
    {
        QPair<QString, QRectF>& itemData = m_itemList[i];
        QFont f = font();
        QFontMetrics fm(f);
        int textWidth = fm.width(itemData.first);
        int textHeight = fm.height();
        if(m_orientation == Qt::Horizontal)
        {
            topLeft = QPointF(dx, 0);
            dx += textWidth+m_space+addWidth;
            dy = m_totalTextHeight+addHeight;
        }
        else
        {
            topLeft = QPointF(0, dy);
            dx = m_totalTextWidth+addWidth;
            dy += textHeight+m_space+addHeight;
        }
        bottomRight = QPointF(dx, dy);
        QRectF textRect(topLeft, bottomRight);
        itemData.second = textRect;
        if(i == m_currentItemIndex)
        {
            m_startRect = textRect;
            m_stopRect = textRect;
        }
    }
    update();
}

void SlideNavigation::doSlide()
{
    if(m_space <= 0 || m_startRect == m_stopRect)
        return;
    qreal dx,dy;
    if(m_orientation == Qt::Horizontal)
    {
        dx = m_space/2.0;
        dy = 0;
    }
    else
    {
        dx = 0;
        dy = m_space/2.0;
    }
    if(m_forward)
    {
        m_startRect.adjust(dx, dy, dx, dy);
        if((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() >= m_stopRect.topLeft().x()) ||
                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() >= m_stopRect.topLeft().y()))
        {
            m_slideTimer->stop();
            if(m_startRect != m_stopRect)
                m_shakeTimer->start();
        }
    }
    else
    {
        m_startRect.adjust(-dx, -dy, -dx, -dy);
        if((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() <= m_stopRect.topLeft().x()) ||
                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() <= m_stopRect.topLeft().y()))
        {
            m_slideTimer->stop();
            if(m_startRect != m_stopRect)
                m_shakeTimer->start();
        }
    }
    update();

//    static qreal stepDx = m_space/2.0;//步进平移
//    static qreal stepDy = m_space/2.0;
//    static qreal adjustDx = m_space/2.0;//调整平移
//    static qreal adjustDy = m_space/2.0;
//    static int state = 1; //1普通平移,2偏移,3回弹
//    if(m_orientation == Qt::Horizontal)
//    {
//        stepDy = 0;
//        adjustDy = 0;
//    }
//    else
//    {
//        stepDx = 0;
//        adjustDx = 0;
//    }
//    if(m_forward)
//    {
//        m_startRect.adjust(stepDx, stepDy, stepDx, stepDy);
//        if(state == 1 &&
//                ((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() >= m_stopRect.topLeft().x()) ||
//                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() >= m_stopRect.topLeft().y())) )
//        {//偏移
//            if(m_orientation == Qt::Horizontal)
//            {
//                stepDx = 1;
//            }
//            else
//            {
//                stepDy = 1;
//            }
//            m_startRect = m_stopRect;
//            m_stopRect.adjust(adjustDx, adjustDy, adjustDx, adjustDy);
//            state = 2;
//            qDebug() << "开始右偏移" << m_startRect << m_stopRect;
//        }
//        if(state == 2 &&
//                ((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() >= m_stopRect.topLeft().x()) ||
//                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() >= m_stopRect.topLeft().y())) )
//        {//回弹
//            if(m_orientation == Qt::Horizontal)
//            {
//                stepDx = -1;
//            }
//            else
//            {
//                stepDy = -1;
//            }
//            m_startRect = m_stopRect;
//            m_stopRect.adjust(-adjustDx, adjustDy, -adjustDx, adjustDy);
//            state = 3;
//            qDebug() << "开始右回弹" << m_startRect << m_stopRect;
//        }
//        if(state == 3 &&
//                ((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() <= m_stopRect.topLeft().x()) ||
//                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() <= m_stopRect.topLeft().y())) )
//        {//重置变量
//            stepDx = m_space/2.0;
//            stepDy = m_space/2.0;
//            adjustDx = m_space/2.0;
//            adjustDy = m_space/2.0;
//            state = 1;
//            m_slideTimer->stop();
//            qDebug() << "开始右重置变量";
//        }
//    }
//    else
//    {
//        m_startRect.adjust(-stepDx, stepDy, -stepDx, stepDy);
//        if(state == 1 &&
//                ((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() <= m_stopRect.topLeft().x()) ||
//                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() <= m_stopRect.topLeft().y())) )
//        {//偏移
//            if(m_orientation == Qt::Horizontal)
//            {
//                stepDx = 1;
//            }
//            else
//            {
//                stepDy = 1;
//            }
//            m_startRect = m_stopRect;
//            m_stopRect.adjust(-adjustDx, adjustDy, -adjustDx, adjustDy);
//            state = 2;
//            qDebug() << "开始左偏移" << m_startRect << m_stopRect;
//        }
//        if(state == 2 &&
//                ((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() <= m_stopRect.topLeft().x()) ||
//                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() <= m_stopRect.topLeft().y())) )
//        {//回弹
//            if(m_orientation == Qt::Horizontal)
//            {
//                stepDx = -1;
//            }
//            else
//            {
//                stepDy = -1;
//            }
//            m_startRect = m_stopRect;
//            m_stopRect.adjust(adjustDx, adjustDy, adjustDx, adjustDy);
//            state = 3;
//            qDebug() << "开始左回弹" << m_startRect << m_stopRect;
//        }
//        if(state == 3 &&
//                ((m_orientation == Qt::Horizontal && m_startRect.topLeft().x() >= m_stopRect.topLeft().x()) ||
//                (m_orientation == Qt::Vertical && m_startRect.topLeft().y() >= m_stopRect.topLeft().y())) )
//        {//重置变量
//            stepDx = m_space/2.0;
//            stepDy = m_space/2.0;
//            adjustDx = m_space/2.0;
//            adjustDy = m_space/2.0;
//            state = 1;
//            m_slideTimer->stop();
//            qDebug() << "开始左重置变量";
//        }
//    }
//    update();
}

void SlideNavigation::doShake()
{
    qreal delta = 2.0;
    qreal dx1,dy1,dx2,dy2;
    dx1=dy1=dx2=dy2=0.0;
    if(m_startRect.topLeft().x()>m_stopRect.topLeft().x())
    {
        dx1 = -delta;
    }
    else if(m_startRect.topLeft().x()<m_stopRect.topLeft().x())
    {
        dx1 = delta;
    }
    if(m_startRect.topLeft().y()>m_stopRect.topLeft().y())
    {
        dy1 = -delta;
    }
    else if(m_startRect.topLeft().y()<m_stopRect.topLeft().y())
    {
        dy1 = delta;
    }
    if(m_startRect.bottomRight().x()>m_stopRect.bottomRight().x())
    {
        dx2 = -delta;
    }
    else if(m_startRect.bottomRight().x()<m_stopRect.bottomRight().x())
    {
        dx2 = delta;
    }
    if(m_startRect.bottomRight().y()>m_stopRect.bottomRight().y())
    {
        dy2 = -delta;
    }
    else if(m_startRect.bottomRight().y()<m_stopRect.bottomRight().y())
    {
        dy2 = delta;
    }
    m_startRect.adjust(dx1,dy1,dx2,dy2);
    if(qAbs(m_startRect.topLeft().x()-m_stopRect.topLeft().x()) <= delta)
    {
        m_startRect.setLeft(m_stopRect.topLeft().x());
    }
    if(qAbs(m_startRect.topLeft().y()-m_stopRect.topLeft().y()) <= delta)
    {
        m_startRect.setTop(m_stopRect.topLeft().y());
    }
    if(qAbs(m_startRect.bottomRight().x()-m_stopRect.bottomRight().x()) <= delta)
    {
        m_startRect.setRight(m_stopRect.bottomRight().x());
    }
    if(qAbs(m_startRect.bottomRight().y()-m_stopRect.bottomRight().y()) <= delta)
    {
        m_startRect.setBottom(m_stopRect.bottomRight().y());
    }
    if(m_startRect == m_stopRect)
        m_shakeTimer->stop();
    update();
}
