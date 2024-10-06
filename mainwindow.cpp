#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    int length = ui->lengthSpinBox->value();
    bool includeUppercase = ui->uppercaseCheckBox->isChecked();
    bool includeNumbers = ui->numbersCheckBox->isChecked();
    bool includeSymbols = ui->symbolsCheckBox->isChecked();

    QString password = generatePassword(length, includeUppercase, includeNumbers, includeSymbols);
    ui->passwordLineEdit->setText(password);
}

QString MainWindow::generatePassword(int length, bool includeUppercase, bool includeNumbers, bool includeSymbols)
{
    QString chars = "abcdefghijklmnopqrstuvwxyz";
    if (includeUppercase)
        chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (includeNumbers)
        chars += "0123456789";
    if (includeSymbols)
        chars += "!@#$%^&*()_+-=[]{}|;:,.<>?";

    QString password;
    for (int i = 0; i < length; ++i)
    {
        int index = QRandomGenerator::global()->bounded(chars.length());
        password += chars.at(index);
    }

    return password;
}
