#ifndef FLATUI_H
#define FLATUI_H

/**
 * FlatUI辅助类 作者:feiyangqingyun(QQ:517216493) 2016-12-16
 */

#include <QObject>
#include <QMutex>

class QPushButton;
class QLineEdit;
class QProgressBar;
class QSlider;
class QRadioButton;
class QCheckBox;
class QScrollBar;

class FlatUI : public QObject
{
    Q_OBJECT
public:
    explicit FlatUI(QObject *parent = 0);
    static FlatUI *Instance()
    {
        static QMutex mutex;

        if (!self) {
            QMutexLocker locker(&mutex);

            if (!self) {
                self = new FlatUI;
            }
        }

        return self;
    }

private:
    static FlatUI *self;

public:
    //设置按钮样式
    void setPushButtonQss(QPushButton *btn,
                          QString normalColor, QString normalTextColor,
                          QString hoverColor, QString hoverTextColor,
                          QString pressedColor, QString pressedTextColor);

    //设置文本框样式
    void setLineEditQss(QLineEdit *txt, QString normalColor, QString focusColor);

    //设置进度条样式
    void setProgressBarQss(QProgressBar *bar, QString normalColor, QString chunkColor);

    //设置滑块条样式
    void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor);

    //设置单选框样式
    void setRadioButtonQss(QRadioButton *rbtn, QString normalColor, QString checkColor);

    //设置复选框样式
    void setCheckBoxQss(QCheckBox *ck, QString normalColor, QString checkColor);

    //设置滚动条样式
    void setScrollBarQss(QScrollBar *scroll, QString bgColor,
                         QString handleNormalColor, QString handleHoverColor,
                         QString handlePressedColor);
};

#endif // FLATUI_H
