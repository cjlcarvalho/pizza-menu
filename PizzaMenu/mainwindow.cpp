#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Pizza");
    setMinimumSize(400, 300);
    setMaximumSize(400, 300);

    ui->selectable->addItem("Calabresa");
    ui->selectable->addItem("Borda Recheada");
    ui->selectable->addItem("Acarajé");

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

    QString result("Pizza básica");

    if (ui->selected->count())
        for (int i = 0; i < ui->selected->count(); i++)
            result += "\ncom " + ui->selected->item(i)->text();

    message.setText(result);

    message.exec();
}
