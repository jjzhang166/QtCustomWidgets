#include "colorprogressbarplugin.h"
#include "roundprogressbarplugin.h"
#include "customwidgetlist.h"

CustomWidgetList::CustomWidgetList(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new ColorProgressBarPlugin(this));
    m_widgets.append(new RoundProgressBarPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> CustomWidgetList::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(customwidgetlistplugin, CustomWidgetList)
#endif // QT_VERSION < 0x050000
