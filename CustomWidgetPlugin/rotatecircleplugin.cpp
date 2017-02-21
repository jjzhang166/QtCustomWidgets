#include "rotatecircle.h"
#include "rotatecircleplugin.h"

#include <QtPlugin>

RotateCirclePlugin::RotateCirclePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void RotateCirclePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool RotateCirclePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *RotateCirclePlugin::createWidget(QWidget *parent)
{
    return new RotateCircle(parent);
}

QString RotateCirclePlugin::name() const
{
    return QLatin1String("RotateCircle");
}

QString RotateCirclePlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon RotateCirclePlugin::icon() const
{
    return QIcon(QLatin1String(":/images/RotateCircle.png"));
}

QString RotateCirclePlugin::toolTip() const
{
    return QLatin1String("");
}

QString RotateCirclePlugin::whatsThis() const
{
    return QLatin1String("");
}

bool RotateCirclePlugin::isContainer() const
{
    return false;
}

QString RotateCirclePlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"RotateCircle\" name=\"rotateCircle\">\n"
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

QString RotateCirclePlugin::includeFile() const
{
    return QLatin1String("rotatecircle.h");
}
