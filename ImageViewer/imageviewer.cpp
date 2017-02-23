#pragma execution_character_set("utf-8")
#include "imageviewer.h"
#include <QApplication>
#include <QStyle>
#include <QPainter>
#include <QToolButton>
#include <QTimer>
#include <QDir>
#include <QKeyEvent>
#include <QAction>
#include <QFileDialog>
#include <QDebug>

PageNum::PageNum(QWidget *parent)
    : QWidget(parent)
{
    m_value = -1;
    m_max = 0;
    m_backgroundColor = QColor(46, 132, 243);
    m_textColor = QColor(Qt::white);

    strFormate = QString("第 %1 张 / 共 %2 张");
    setMinimumWidth(150);
}

PageNum::~PageNum()
{

}

void PageNum::setMax(int max)
{
    if(max>=0 && max!=m_max)
    {
        m_max = max;
        setValue(max>0?0:-1);
        QString text = strFormate.arg(m_max).arg(m_max);
        QFontMetrics fm = fontMetrics();
        int minWidth = fm.width(text);
        setMinimumWidth(minWidth+50);
        update();
    }
}

void PageNum::setValue(int value)
{
    if(value!=m_value)
    {
        m_value = value<0?-1:value;
        update();
    }
}

void PageNum::setBackgroundColor(const QColor &color)
{
    if(color != m_backgroundColor)
    {
        m_backgroundColor = color;
        update();
    }
}

void PageNum::setTextColor(const QColor &color)
{
    if(color !=m_textColor)
    {
        m_textColor = color;
        update();
    }
}

void PageNum::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    drawBackground(&painter);
    drawText(&painter);
}

void PageNum::drawBackground(QPainter *p)
{
    p->save();
    p->setPen(Qt::NoPen);
    p->setBrush(m_backgroundColor);
    p->drawRect(rect());
    p->restore();
}

void PageNum::drawText(QPainter *p)
{
    QString text = strFormate.arg(m_value+1).arg(m_max);
    p->save();
    QFont f = font();
    f.setBold(true);
    p->setFont(f);
    p->drawText(rect(), Qt::AlignCenter, text);
    p->restore();
}

ImageViewer::ImageViewer(QWidget *parent)
    : QWidget(parent)
{
    m_backgroundStartColor = QColor(100, 100, 100);
    m_backgroundEndColor = QColor(60, 60, 60);
    m_pageBtnLeftMargin = 10;
    m_pageNumBottomMargin = 10;
    m_pageBtnSize = QSize(50, 50);
    m_sizeType = OriginalSize;
    m_fadeEnable = false;
    m_opacity = 1.0;
    m_keyMoveEnable = false;

    QStyle* style = QApplication::style();
    m_preBtn = new QToolButton(this);
    m_preBtn->setIcon(style->standardIcon(QStyle::SP_ArrowLeft));
    m_preBtn->setIconSize(m_pageBtnSize);
    m_preBtn->setAutoRaise(true);
    m_nextBtn = new QToolButton(this);
    m_nextBtn->setIcon(style->standardIcon(QStyle::SP_ArrowRight));
    m_nextBtn->setIconSize(m_pageBtnSize);
    m_nextBtn->setAutoRaise(true);
    m_pageNum = new PageNum(this);
    m_curImageIndex = 0;
    m_fadeTimer = new QTimer(this);
    m_fadeTimer->setInterval(20);

    QAction* clearAction = new QAction("清空", this);
    QAction* reloadImageAction = new QAction("加载", this);
    setContextMenuPolicy(Qt::ActionsContextMenu);
    addAction(clearAction);
    addAction(reloadImageAction);
    connect(clearAction, SIGNAL(triggered(bool)), this, SLOT(clear()));
    connect(reloadImageAction, SIGNAL(triggered(bool)), this, SLOT(loadImages()));

    connect(m_preBtn, SIGNAL(clicked(bool)), this, SLOT(moveToPrevious()));
    connect(m_nextBtn, SIGNAL(clicked(bool)), this, SLOT(moveToNext()));
    connect(m_fadeTimer, SIGNAL(timeout()), this, SLOT(fadeImage()));
    connect(this, SIGNAL(imageNumberchanged(int)), m_pageNum, SLOT(setMax(int)));
    connect(this, SIGNAL(imageIndexChanged(int)), m_pageNum, SLOT(setValue(int)));
    setMinimumSize(200,100);
    setFocusPolicy(Qt::StrongFocus);
    adjustWidgetPos();
}

ImageViewer::~ImageViewer()
{

}

void ImageViewer::loadImages(QString path)
{
    QDir imagePath(path);
    if(!imagePath.exists()) { return; }
    m_path = path;
    QStringList nameFilters;
    nameFilters << "*.bmp" << "*.jpg" << "*.png";
    m_imageNames = imagePath.entryList(nameFilters);
    emit imageNumberchanged(m_imageNames.size());

    moveTo(0);
}

void ImageViewer::moveTo(int index)
{
    if(index>=0 && index<m_imageNames.size())
    {
        QString imageName = m_imageNames.at(index);
        QString imagePath = QDir::toNativeSeparators(QString("%1/%2").arg(m_path).arg(imageName));
        bool ok = m_curPixmap.load(imagePath);
        if(!ok) { return; }
        m_curImageIndex = index;
        emit imageIndexChanged(index);
        if(m_fadeEnable)
        {
            m_opacity = 0.0;
            m_fadeTimer->start();
        }
        update();
    }
}

void ImageViewer::moveToNext()
{
    moveTo(m_curImageIndex+1);
}

void ImageViewer::moveToPrevious()
{
    moveTo(m_curImageIndex-1);
}

void ImageViewer::moveToFirst()
{
    moveTo(0);
}

void ImageViewer::moveToLast()
{
    moveTo(m_imageNames.size()-1);
}

void ImageViewer::setSizeType(ImageViewer::ImageSizeType type)
{
    if(type != m_sizeType)
    {
        m_sizeType = type;
        update();
    }
}

void ImageViewer::setFadeEnable(bool enable)
{
    if(enable != m_fadeEnable)
    {
        m_fadeEnable = enable;
        if(!m_fadeEnable)
        {
            m_fadeTimer->stop();
            m_opacity = 1.0;
            update();
        }
    }
}

void ImageViewer::setKeyMoveEnable(bool enable)
{
    if(enable != m_keyMoveEnable)
    {
        m_keyMoveEnable = enable;
        if(m_keyMoveEnable)
            setFocus();
        else
            clearFocus();
    }
}

void ImageViewer::clear()
{
    m_curImageIndex = 0;
    m_curPixmap.swap(QPixmap());
    m_path = "";
    m_imageNames.clear();
    m_fadeTimer->stop();
    m_opacity = 1.0;
    emit imageNumberchanged(m_imageNames.size());
}

void ImageViewer::loadImages()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("选择图片文件夹"),
                                                    ".",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    loadImages(dir);
}

void ImageViewer::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setOpacity(m_opacity);
    painter.setRenderHint(QPainter::Antialiasing);
    drawBackground(&painter);
    drawImage(&painter);
}

void ImageViewer::keyPressEvent(QKeyEvent *event)
{
    if(!m_keyMoveEnable)
        return;
    switch(event->key())
    {
    case Qt::Key_Left:
        moveToPrevious();
        break;
    case Qt::Key_Right:
        moveToNext();
        break;
    case Qt::Key_Home:
        moveToFirst();
        break;
    case Qt::Key_End:
        moveToLast();
        break;
    default:
        break;
    }
}

void ImageViewer::showEvent(QShowEvent *)
{
    adjustWidgetPos();
}

void ImageViewer::resizeEvent(QResizeEvent *)
{
    adjustWidgetPos();
}

void ImageViewer::drawBackground(QPainter *p)
{
    p->save();
    QLinearGradient linearGradient(QPointF(0,0), QPointF(0,height()));
    linearGradient.setColorAt(0.0, m_backgroundStartColor);
    linearGradient.setColorAt(1.0, m_backgroundEndColor);
    p->setPen(Qt::NoPen);
    p->setBrush(linearGradient);
    p->drawRect(rect());
    p->restore();
}

void ImageViewer::drawImage(QPainter *p)
{
    if(m_curPixmap.isNull()) { return; }
    switch (m_sizeType) {
    case OriginalSize:
        showOriginalImage(p);
        break;
    case SuitableSize:
        showSuitableImage(p);
        break;
    case FillSize:
        showFillImage(p);
        break;
    default:
        break;
    }
}

void ImageViewer::showOriginalImage(QPainter *p)
{
    p->save();
    int pixWidth = m_curPixmap.width();
    int pixHeight = m_curPixmap.height();
    int x = rect().center().x() - pixWidth/2;
    int y = rect().center().y() - pixHeight/2;
    p->drawPixmap(x, y, m_curPixmap);
    p->restore();
}

void ImageViewer::showSuitableImage(QPainter *p)
{
    p->save();
    int pixWidth = m_curPixmap.width();
    int pixHeight = m_curPixmap.height();
    qreal wRatio = 1.0*width()/pixWidth;
    qreal hRatio = 1.0*height()/pixHeight;
    qreal ratio = qMin(wRatio, hRatio);
    pixWidth *= ratio;
    pixHeight *= ratio;
    int x = rect().center().x() - pixWidth/2;
    int y = rect().center().y() - pixHeight/2;
    p->drawPixmap(x, y, pixWidth, pixHeight, m_curPixmap);
    p->restore();
}

void ImageViewer::showFillImage(QPainter *p)
{
    p->save();
    p->drawPixmap(rect(), m_curPixmap);
    p->restore();
}

void ImageViewer::adjustWidgetPos()
{
    QPoint prePoint(m_pageBtnLeftMargin, (height()-m_preBtn->height())/2);
    m_preBtn->move(prePoint);

    QPoint nextPoint(width()-m_pageBtnLeftMargin-m_nextBtn->width(), (height()-m_nextBtn->height())/2);
    m_nextBtn->move(nextPoint);

    QPoint numPoint(width()/2-m_pageNum->width()/2, height()-m_pageNumBottomMargin-m_pageNum->height());
    m_pageNum->move(numPoint);
}

void ImageViewer::fadeImage()
{
    m_opacity += 0.05;
    if(m_opacity >= 1.0)
    {
        m_opacity = 1.0;
        m_fadeTimer->stop();
    }
    update();
}
