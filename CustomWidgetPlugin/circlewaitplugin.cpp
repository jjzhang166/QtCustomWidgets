#include "circlewait.h"
#include "circlewaitplugin.h"

#include <QtPlugin>

CircleWaitPlugin::CircleWaitPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CircleWaitPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CircleWaitPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CircleWaitPlugin::createWidget(QWidget *parent)
{
    return new CircleWait(parent);
}

QString CircleWaitPlugin::name() const
{
    return QLatin1String("CircleWait");
}

QString CircleWaitPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon CircleWaitPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/CircleWait.png"));
}

QString CircleWaitPlugin::toolTip() const
{
    return QLatin1String("");
}

QString CircleWaitPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool CircleWaitPlugin::isContainer() const
{
    return false;
}

QString CircleWaitPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"CircleWait\" name=\"circleWait\">\n"
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

QString CircleWaitPlugin::includeFile() const
{
    return QLatin1String("circlewait.h");
}
