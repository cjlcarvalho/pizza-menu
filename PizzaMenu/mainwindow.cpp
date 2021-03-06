#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pluginloader.h"
#include "pizza.h"

#include <QMessageBox>
#include <QMetaClassInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Pizza");

    m_pluginLoader = new PluginLoader;

    for (Decorator *decorator : m_pluginLoader->decorators()) {
        m_decorators.insert(decorator->metaObject()->classInfo(0).value(), decorator);
        ui->selectable->addItem(decorator->metaObject()->classInfo(0).value());
    }

    connect(ui->moveRightButton, &QPushButton::clicked, this, &MainWindow::moveToRight);
    connect(ui->moveLeftButton, &QPushButton::clicked, this, &MainWindow::moveToLeft);
    connect(ui->preparePizzaButton, &QPushButton::clicked, this, &MainWindow::preparePizza);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveToRight()
{
    int currentRow = ui->selectable->currentRow();

    if (currentRow != -1)
        ui->selected->addItem(ui->selectable->item(currentRow)->text());
}

void MainWindow::moveToLeft()
{
    int currentRow = ui->selected->currentRow();

    if (currentRow != -1) {
        QListWidgetItem *item = ui->selected->takeItem(currentRow);
        delete item;
    }
}

void MainWindow::preparePizza()
{
    QMessageBox message;
    message.setWindowTitle("Pizza preparada!");

    Component *component = new Pizza;

    for (int i = 0; i < ui->selected->count(); i++) {
        Decorator *decorator = m_decorators[ui->selected->item(i)->text()]->clone();
        decorator->setDecorated(component);
        component = decorator;
    }

    message.setText(component->preparar());

    message.exec();
}
