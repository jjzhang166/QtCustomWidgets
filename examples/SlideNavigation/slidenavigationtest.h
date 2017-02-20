#ifndef SLIDENAVIGATIONTEST_H
#define SLIDENAVIGATIONTEST_H

#include <QWidget>

namespace Ui {
class SlideNavigationTest;
}

class SlideNavigation;
class SlideNavigationTest : public QWidget
{
    Q_OBJECT

public:
    explicit SlideNavigationTest(QWidget *parent = 0);
    ~SlideNavigationTest();

private:
    void helpConnect(SlideNavigation* widget);
    void connectToFirst(SlideNavigation* widget);
    void connectToLast(SlideNavigation* widget);
    void connectToPrevious(SlideNavigation* widget);
    void connectToNext(SlideNavigation* widget);
    void connectToIndex(SlideNavigation* widget);
    void connectEnableKeyMove(SlideNavigation* widget);

private:
    Ui::SlideNavigationTest *ui;
};

#endif // SLIDENAVIGATIONTEST_H
