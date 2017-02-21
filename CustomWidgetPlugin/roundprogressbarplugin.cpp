#include "roundprogressbar.h"
#include "roundprogressbarplugin.h"

#include <QtPlugin>

RoundProgressBarPlugin::RoundProgressBarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void RoundProgressBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool RoundProgressBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *RoundProgressBarPlugin::createWidget(QWidget *parent)
{
    return new RoundProgressBar(parent);
}

QString RoundProgressBarPlugin::name() const
{
    return QLatin1String("RoundProgressBar");
}

QString RoundProgressBarPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon RoundProgressBarPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/RoundProgressBar.png"));
}

QString RoundProgressBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString RoundProgressBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool RoundProgressBarPlugin::isContainer() const
{
    return false;
}

QString RoundProgressBarPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"RoundProgressBar\" name=\"roundProgressBar\">\n"
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

QString RoundProgressBarPlugin::includeFile() const
{
    return QLatin1String("roundprogressbar.h");
}

