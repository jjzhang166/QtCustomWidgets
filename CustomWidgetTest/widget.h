#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void curveChartAddData();

private:
    Ui::Widget *ui;
    QTimer* curveChartDataTimer;
};

#endif // WIDGET_H
