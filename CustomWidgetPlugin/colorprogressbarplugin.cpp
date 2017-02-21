#include "colorprogressbar.h"
#include "colorprogressbarplugin.h"

#include <QtPlugin>

ColorProgressBarPlugin::ColorProgressBarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ColorProgressBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ColorProgressBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ColorProgressBarPlugin::createWidget(QWidget *parent)
{
    return new ColorProgressBar(parent);
}

QString ColorProgressBarPlugin::name() const
{
    return QLatin1String("ColorProgressBar");
}

QString ColorProgressBarPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon ColorProgressBarPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/ColorProgressBar.png"));
}

QString ColorProgressBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ColorProgressBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ColorProgressBarPlugin::isContainer() const
{
    return false;
}

QString ColorProgressBarPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"ColorProgressBar\" name=\"colorProgressBar\">\n"
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

QString ColorProgressBarPlugin::includeFile() const
{
    return QLatin1String("colorprogressbar.h");
}

