#include "slidenavigation.h"
#include "slidenavigationplugin.h"

#include <QtPlugin>

SlideNavigationPlugin::SlideNavigationPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SlideNavigationPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SlideNavigationPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SlideNavigationPlugin::createWidget(QWidget *parent)
{
    return new SlideNavigation(parent);
}

QString SlideNavigationPlugin::name() const
{
    return QLatin1String("SlideNavigation");
}

QString SlideNavigationPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon SlideNavigationPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/SlideNavigation.png"));
}

QString SlideNavigationPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SlideNavigationPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SlideNavigationPlugin::isContainer() const
{
    return false;
}

QString SlideNavigationPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"SlideNavigation\" name=\"SlideNavigation\">\n"
                         "  <property name=\"geometry\">\n"
                         "   <rect>\n"
                         "    <x>0</x>\n"
                         "    <y>0</y>\n"
                         "    <width>300</width>\n"
                         "    <height>30</height>\n"
                         "   </rect>\n"
                         "  </property>\n"
                         " </widget>\n"
                         "</ui>");
}

QString SlideNavigationPlugin::includeFile() const
{
    return QLatin1String("slidenavigation.h");
}
