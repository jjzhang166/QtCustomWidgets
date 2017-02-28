#ifndef CURVECHARTTEST_H
#define CURVECHARTTEST_H

#include <QWidget>

namespace Ui {
class CurveChartTest;
}

class CurveChartTest : public QWidget
{
    Q_OBJECT

public:
    explicit CurveChartTest(QWidget *parent = 0);
    ~CurveChartTest();
private slots:
    void addData();

private:
    Ui::CurveChartTest *ui;
    QTimer* dataTimer;
};

#endif // CURVECHARTTEST_H
