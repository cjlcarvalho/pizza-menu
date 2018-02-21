#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../PizzaCore/decorator.h"

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class PluginLoader;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void moveToLeft();
    void moveToRight();
    void preparePizza();

private:
    Ui::MainWindow *ui;
    PluginLoader *m_pluginLoader;
    QMap<QString, Decorator *> m_decorators;
};

#endif // MAINWINDOW_H
