#include "piewait.h"
#include "piewaitplugin.h"

#include <QtPlugin>

PieWaitPlugin::PieWaitPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void PieWaitPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool PieWaitPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *PieWaitPlugin::createWidget(QWidget *parent)
{
    return new PieWait(parent);
}

QString PieWaitPlugin::name() const
{
    return QLatin1String("PieWait");
}

QString PieWaitPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon PieWaitPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/PieWait.png"));
}

QString PieWaitPlugin::toolTip() const
{
    return QLatin1String("");
}

QString PieWaitPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool PieWaitPlugin::isContainer() const
{
    return false;
}

QString PieWaitPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"PieWait\" name=\"pieWait\">\n"
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

QString PieWaitPlugin::includeFile() const
{
    return QLatin1String("piewait.h");
}
