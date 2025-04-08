#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logic.c" //только тут видит logic.c

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->inputField, &QTextEdit::textChanged, this, &MainWindow::text_changed);
    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::convertButton_Clicked);
    connect(ui->buttonGroup_1, &QButtonGroup::buttonClicked, this, &MainWindow::get_notation);
    connect(ui->buttonGroup_2, &QButtonGroup::buttonClicked, this, &MainWindow::get_notation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_answer(){
    ui->outputField->setText(QString::number(context.answer));
}

void MainWindow::text_changed(){
    std::string str;

    str = ui->inputField->toPlainText().toStdString();
    context.input = str.c_str();
    if(checkNumber(context.input, context.inputBase))
        show_answer();
}

void MainWindow::get_notation(){
    std::string str;

    str = ui->buttonGroup_1->checkedButton()->text().toStdString();
    numericalRepresentation(&(context.inputBase), str.c_str());

    str = ui->buttonGroup_2->checkedButton()->text().toStdString();
    numericalRepresentation(&(context.outputBase), str.c_str());
}

void MainWindow::convertButton_Clicked() {

}
