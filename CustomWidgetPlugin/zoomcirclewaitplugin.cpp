#include "zoomcirclewait.h"
#include "zoomcirclewaitplugin.h"

#include <QtPlugin>

ZoomCircleWaitPlugin::ZoomCircleWaitPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ZoomCircleWaitPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ZoomCircleWaitPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ZoomCircleWaitPlugin::createWidget(QWidget *parent)
{
    return new ZoomCircleWait(parent);
}

QString ZoomCircleWaitPlugin::name() const
{
    return QLatin1String("ZoomCircleWait");
}

QString ZoomCircleWaitPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon ZoomCircleWaitPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/ZoomCircleWait.png"));
}

QString ZoomCircleWaitPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ZoomCircleWaitPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ZoomCircleWaitPlugin::isContainer() const
{
    return false;
}

QString ZoomCircleWaitPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"ZoomCircleWait\" name=\"zoomCircleWait\">\n"
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

QString ZoomCircleWaitPlugin::includeFile() const
{
    return QLatin1String("zoomcirclewait.h");
}
