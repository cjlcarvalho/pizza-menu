#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QDir>
#include <QList>

class Decorator;

class PluginLoader
{
public:
    PluginLoader();
    void update();
    QList<Decorator *> decorators() const;

private:
    QList<QObject *> retrievePlugins(const QString &pluginPath);
    QDir pluginDirectory(const QString &plugin);

private:
    QList<Decorator *> m_decorators;
};

#endif // PLUGINLOADER_H
