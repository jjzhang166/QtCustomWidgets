#include "taichiwait.h"
#include "taichiwaitplugin.h"

#include <QtPlugin>

TaiChiWaitPlugin::TaiChiWaitPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TaiChiWaitPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TaiChiWaitPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TaiChiWaitPlugin::createWidget(QWidget *parent)
{
    return new TaiChiWait(parent);
}

QString TaiChiWaitPlugin::name() const
{
    return QLatin1String("TaiChiWait");
}

QString TaiChiWaitPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon TaiChiWaitPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/TaiChiWait.png"));
}

QString TaiChiWaitPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TaiChiWaitPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TaiChiWaitPlugin::isContainer() const
{
    return false;
}

QString TaiChiWaitPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"TaiChiWait\" name=\"taiChiWait\">\n"
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

QString TaiChiWaitPlugin::includeFile() const
{
    return QLatin1String("taichiwait.h");
}
