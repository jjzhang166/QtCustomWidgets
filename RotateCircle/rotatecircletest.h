#ifndef ROTATECIRCLETEST_H
#define ROTATECIRCLETEST_H

#include <QWidget>

namespace Ui {
class RotateCircleTest;
}

class RotateCircleTest : public QWidget
{
    Q_OBJECT

public:
    explicit RotateCircleTest(QWidget *parent = 0);
    ~RotateCircleTest();

private:
    Ui::RotateCircleTest *ui;
};

#endif // ROTATECIRCLETEST_H
