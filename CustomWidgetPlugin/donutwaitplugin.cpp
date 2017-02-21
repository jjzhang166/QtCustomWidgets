#include "donutwait.h"
#include "donutwaitplugin.h"

#include <QtPlugin>

DonutWaitPlugin::DonutWaitPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void DonutWaitPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool DonutWaitPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *DonutWaitPlugin::createWidget(QWidget *parent)
{
    return new DonutWait(parent);
}

QString DonutWaitPlugin::name() const
{
    return QLatin1String("DonutWait");
}

QString DonutWaitPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon DonutWaitPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/DonutWait.png"));
}

QString DonutWaitPlugin::toolTip() const
{
    return QLatin1String("");
}

QString DonutWaitPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool DonutWaitPlugin::isContainer() const
{
    return false;
}

QString DonutWaitPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"DonutWait\" name=\"donutWait\">\n"
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

QString DonutWaitPlugin::includeFile() const
{
    return QLatin1String("donutwait.h");
}
