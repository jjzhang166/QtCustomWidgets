#include "imageviewer.h"
#include "imageviewerplugin.h"
#include <QtPlugin>

ImageViewerPlugin::ImageViewerPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ImageViewerPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ImageViewerPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ImageViewerPlugin::createWidget(QWidget *parent)
{
    return new ImageViewer(parent);
}

QString ImageViewerPlugin::name() const
{
    return QLatin1String("ImageViewer");
}

QString ImageViewerPlugin::group() const
{
    return QLatin1String("CustomWidget");
}

QIcon ImageViewerPlugin::icon() const
{
    return QIcon(QLatin1String(":/images/ImageViewer.png"));
}

QString ImageViewerPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ImageViewerPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ImageViewerPlugin::isContainer() const
{
    return false;
}

QString ImageViewerPlugin::domXml() const
{
    return QLatin1String("<ui language=\"c++\">\n"
                         " <widget class=\"ImageViewer\" name=\"imageViewer\">\n"
                         "  <property name=\"geometry\">\n"
                         "   <rect>\n"
                         "    <x>0</x>\n"
                         "    <y>0</y>\n"
                         "    <width>400</width>\n"
                         "    <height>150</height>\n"
                         "   </rect>\n"
                         "  </property>\n"
                         " </widget>\n"
                         "</ui>");
}

QString ImageViewerPlugin::includeFile() const
{
    return QLatin1String("imageviewer.h");
}
