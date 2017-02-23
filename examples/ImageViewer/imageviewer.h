#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>

class QToolButton;
class QPixmap;

//图片数量统计控件
class PageNum : public QWidget
{
    Q_OBJECT
public:
    PageNum(QWidget *parent = 0);
    ~PageNum();


    void setBackgroundColor(const QColor& color);
    void setTextColor(const QColor& color);

signals:
public slots:
    void setMax(int max);
    void setValue(int value);

protected:
    void paintEvent(QPaintEvent *event);
    void drawBackground(QPainter* p);
    void drawText(QPainter* p);

private:
    int m_value;//当前索引值
    int m_max;//总数
    QColor m_backgroundColor;
    QColor m_textColor;

    QString strFormate;
};

//图片查看控件
class ImageViewer : public QWidget
{
    Q_OBJECT

public:
    enum ImageSizeType
    {
        OriginalSize,//原始大小
        SuitableSize,//适合大小
        FillSize,//填充大小
    };

    ImageViewer(QWidget *parent = 0);
    ~ImageViewer();

    void loadImages(QString path);
signals:
    void imageNumberchanged(int number);
    void imageIndexChanged(int index);

public slots:
    void moveTo(int index);
    void moveToNext();
    void moveToPrevious();
    void moveToFirst();
    void moveToLast();
    void setSizeType(ImageSizeType type);
    void setFadeEnable(bool enable);
    void setKeyMoveEnable(bool enable);

protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
    void drawBackground(QPainter* p);
    void drawImage(QPainter* p);

private:
    void showSuitableImage(QPainter* p);
    void showOriginalImage(QPainter* p);
    void showFillImage(QPainter* p);
    void fadeImage();

private:
    QColor m_backgroundStartColor;//背景起始颜色
    QColor m_backgroundEndColor;//背景结束颜色
    int m_pageBtnLeftMargin;//导航按钮左边距
    int m_pageNumBottomMargin;//数量统计下边距
    QSize m_pageBtnSize;//导航按钮大小
    ImageSizeType m_sizeType;//大小类型
    bool m_fadeEnable;//逐渐显示
    bool m_keyMoveEnable;//按键切换

    QToolButton* m_preBtn;
    QToolButton* m_nextBtn;
    PageNum* m_pageNum;//图片数量统计控件
    int m_curImageIndex;//当前图片索引
    QPixmap m_curPixmap;//当前图片
    QString m_path;//图片路径
    QStringList m_imageNames;//图片名字列表
    QTimer* m_fadeTimer;//逐渐显示定时器
    qreal m_opacity;//当前不透明度

};

#endif // IMAGEVIEWER_H
