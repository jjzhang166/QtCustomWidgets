#include "linewait.h"
#include "linewaitplugin.h"

#include <QtPlugin>

LineWaitPlugin::LineWaitPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LineWaitPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LineWaitPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LineWaitPlugin::createWidget(QWidget *parent)
{
    return new LineWait(parent);
}

QString LineWaitPlugin::name() const
{
    return QLatin1String("LineWait");
}

QString LineWaitPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon LineWaitPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/LineWait.png"));
}

QString LineWaitPlugin::toolTip() const
{
    return QLatin1String("");
}

QString LineWaitPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool LineWaitPlugin::isContainer() const
{
    return false;
}

QString LineWaitPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"LineWait\" name=\"lineWait\">\n"
                         "  <property name=\"geometry\">\n"
                         "   <rect>\n"
                         "    <x>0</x>\n"
                         "    <y>0</y>\n"
                         "    <width>100</width>\n"
                         "    <height>100</height>\n"
                         "   </rect>\n"
                         "  </property>\n"
                         " </widget>\n"
                         "</ui>");
}

QString LineWaitPlugin::includeFile() const
{
    return QLatin1String("linewait.h");
}
