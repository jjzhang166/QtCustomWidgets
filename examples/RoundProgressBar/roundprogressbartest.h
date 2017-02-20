#ifndef ROUNDPROGRESSBARTEST_H
#define ROUNDPROGRESSBARTEST_H

#include <QWidget>

namespace Ui {
class RoundProgressBarTest;
}

class RoundProgressBarTest : public QWidget
{
    Q_OBJECT

public:
    explicit RoundProgressBarTest(QWidget *parent = 0);
    ~RoundProgressBarTest();

private:
    void connectToSlider(class RoundProgressBar* bar);
    void connectToBaseCircleCheckBox(class RoundProgressBar* bar);
    void connectToDataCircleCheckBox(class RoundProgressBar* bar);
    void connectToCenterCircleCheckBox(class RoundProgressBar* bar);
    void connectToTextCheckBox(class RoundProgressBar* bar);

private:
    Ui::RoundProgressBarTest *ui;
};

#endif // ROUNDPROGRESSBARTEST_H
