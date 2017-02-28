#include "curvechart.h"
#include "curvechartplugin.h"

#include <QtPlugin>

CurveChartPlugin::CurveChartPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CurveChartPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CurveChartPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CurveChartPlugin::createWidget(QWidget *parent)
{
    return new CurveChart(parent);
}

QString CurveChartPlugin::name() const
{
    return QLatin1String("CurveChart");
}

QString CurveChartPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon CurveChartPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/CurveChart.png"));
}

QString CurveChartPlugin::toolTip() const
{
    return QLatin1String("");
}

QString CurveChartPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool CurveChartPlugin::isContainer() const
{
    return false;
}

QString CurveChartPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"CurveChart\" name=\"curveChart\">\n"
                         "  <property name=\"geometry\">\n"
                         "   <rect>\n"
                         "    <x>0</x>\n"
                         "    <y>0</y>\n"
                         "    <width>400</width>\n"
                         "    <height>250</height>\n"
                         "   </rect>\n"
                         "  </property>\n"
                         " </widget>\n"
                         "</ui>");
}

QString CurveChartPlugin::includeFile() const
{
    return QLatin1String("curveChart.h");
}
