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
    setMinimumSize(400, 300);
    setMaximumSize(400, 300);

    m_pluginLoader = new PluginLoader;

    for (Decorator *decorator : m_pluginLoader->decorators()) {
        m_decorators.insert(decorator->metaObject()->classInfo(0).value(), decorator);
        ui->selectable->addItem(decorator->metaObject()->classInfo(0).value());
    }

    connect(ui->moveRightButton, &QPushButton::released, this, &MainWindow::moveToRight);
    connect(ui->moveLeftButton, &QPushButton::released, this, &MainWindow::moveToLeft);
    connect(ui->preparePizzaButton, &QPushButton::released, this, &MainWindow::preparePizza);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveToRight()
{
    int currentRow = ui->selectable->currentRow();

    if (currentRow != -1)
        ui->selected->addItem(ui->selectable->takeItem(currentRow));
}

void MainWindow::moveToLeft()
{
    int currentRow = ui->selected->currentRow();

    if (currentRow != -1)
        ui->selectable->addItem(ui->selected->takeItem(currentRow));
}

void MainWindow::preparePizza()
{
    QMessageBox message;
    message.setWindowTitle("Pizza preparada!");

    QString result;

    Component *component = new Pizza;

    if (ui->selected->count()) {
        for (int i = 0; i < ui->selected->count(); i++) {
            Decorator *decorator = m_decorators[ui->selected->item(i)->text()];
            decorator->setDecorated(component);
            component = decorator;
        }
    }

    message.setText(component->preparar());

    message.exec();
}
