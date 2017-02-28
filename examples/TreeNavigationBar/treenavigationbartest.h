#ifndef TREENAVIGATIONBARTEST_H
#define TREENAVIGATIONBARTEST_H

#include <QWidget>

namespace Ui {
class TreeNavigationBarTest;
}

class TreeNavigationBarTest : public QWidget
{
    Q_OBJECT

public:
    explicit TreeNavigationBarTest(QWidget *parent = 0);
    ~TreeNavigationBarTest();

private:
    Ui::TreeNavigationBarTest *ui;
};

#endif // TREENAVIGATIONBARTEST_H
