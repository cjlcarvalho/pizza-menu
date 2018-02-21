#include "pluginloader.h"

#include "../PizzaCore/decorator.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QPluginLoader>

PluginLoader::PluginLoader()
{
    update();
}

void PluginLoader::update()
{
    QList<QObject *> decoratorsPlugins = retrievePlugins("decorators/");

    m_decorators.clear();

    for (QObject *plugin : decoratorsPlugins)
        m_decorators << dynamic_cast<Decorator *>(plugin);
}

QList<Decorator *> PluginLoader::decorators() const
{
    return m_decorators;
}

QList<QObject *> PluginLoader::retrievePlugins(const QString &pluginPath)
{
    QDir pluginsDir = pluginDirectory(pluginPath);

    QList<QObject *> resultList;

    for (const QString &file : pluginsDir.entryList(QDir::Files)) {
        if (!QLibrary::isLibrary(pluginsDir.absoluteFilePath(file)))
            continue;

        qDebug() << "Arquivo: " << pluginsDir.absoluteFilePath(file);
        QPluginLoader loader(pluginsDir.absoluteFilePath(file));

        resultList << loader.instance();
    }

    return resultList;
}

QDir PluginLoader::pluginDirectory(const QString &plugin)
{
    QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());

    #if defined(Q_OS_WIN)
        if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
            pluginsDir.cdUp();
    #elif defined(Q_OS_MAC)
        if (pluginsDir.dirName() == "MacOS") {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #endif

    pluginsDir.cdUp();
    pluginsDir.cd(plugin);

    return pluginsDir;
}
