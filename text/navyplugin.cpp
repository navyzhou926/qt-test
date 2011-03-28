#include "navy.h"
#include "navyplugin.h"

#include <QtCore/QtPlugin>

navyPlugin::navyPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void navyPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool navyPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *navyPlugin::createWidget(QWidget *parent)
{
    return new navy(parent);
}

QString navyPlugin::name() const
{
    return QLatin1String("navy");
}

QString navyPlugin::group() const
{
    return QLatin1String("");
}

QIcon navyPlugin::icon() const
{
    return QIcon();
}

QString navyPlugin::toolTip() const
{
    return QLatin1String("");
}

QString navyPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool navyPlugin::isContainer() const
{
    return false;
}

QString navyPlugin::domXml() const
{
    return QLatin1String("<widget class=\"navy\" name=\"navy\">\n</widget>\n");
}

QString navyPlugin::includeFile() const
{
    return QLatin1String("navy.h");
}

Q_EXPORT_PLUGIN2(navyplugin, navyPlugin)
