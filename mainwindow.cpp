#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->inputField, &QTextEdit::textChanged, this, &MainWindow::get_data);
    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::convertButton_Clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_answer(){
    ui->outputField->setText(context.answer);
}

void MainWindow::get_data(){
    std::string str = ui->inputField->toPlainText().toStdString();
    context.input = str.c_str();
    context.fromBase = ui->buttonGroup->checkedButton()->text().toStdString().c_str(); //должно быть число
    context.toBase = ui->buttonGroup_2->checkedButton()->text().toStdString().c_str(); //должно быть число
}

void MainWindow::convertButton_Clicked() {

}

