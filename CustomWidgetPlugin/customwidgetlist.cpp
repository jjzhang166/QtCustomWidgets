#include "circlewaitplugin.h"
#include "colorprogressbarplugin.h"
#include "customwidgetlist.h"
#include "donutwaitplugin.h"
#include "linewaitplugin.h"
#include "piewaitplugin.h"
#include "rotatecircleplugin.h"
#include "roundprogressbarplugin.h"
#include "slidenavigationplugin.h"
#include "taichiwaitplugin.h"
#include "zoomcirclewaitplugin.h"

CustomWidgetList::CustomWidgetList(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new CircleWaitPlugin(this));
    m_widgets.append(new ColorProgressBarPlugin(this));
    m_widgets.append(new DonutWaitPlugin(this));
    m_widgets.append(new LineWaitPlugin(this));
    m_widgets.append(new PieWaitPlugin(this));
    m_widgets.append(new RotateCirclePlugin(this));
    m_widgets.append(new RoundProgressBarPlugin(this));
    m_widgets.append(new SlideNavigationPlugin(this));
    m_widgets.append(new TaiChiWaitPlugin(this));
    m_widgets.append(new ZoomCircleWaitPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> CustomWidgetList::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(customwidgetlistplugin, CustomWidgetList)
#endif // QT_VERSION < 0x050000
