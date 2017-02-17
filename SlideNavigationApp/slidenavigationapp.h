#ifndef SLIDENAVIGATIONAPP_H
#define SLIDENAVIGATIONAPP_H

#include <QWidget>

namespace Ui {
class SlideNavigationApp;
}

class SlideNavigationApp : public QWidget
{
    Q_OBJECT

public:
    explicit SlideNavigationApp(QWidget *parent = 0);
    ~SlideNavigationApp();

private slots:
    void updateLabel(int index, QString str);
private:
    Ui::SlideNavigationApp *ui;
};

#endif // SLIDENAVIGATIONAPP_H
