#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontext.h"
#include "entrypoint.h"
#include "logic.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertButton_Clicked();

    void get_data();
    void show_answer();
    // void show_error();

private:
    Ui::MainWindow *ui;

    struct AppContext context;
};
#endif // MAINWINDOW_H
