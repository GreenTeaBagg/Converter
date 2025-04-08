#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entrypoint.h"
#include "appcontext.h"

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

private:
    Ui::MainWindow *ui;

    struct AppContext context;

    void convertButton_Clicked();

    void text_changed();
    void get_notation();
    void show_answer();
};
#endif // MAINWINDOW_H
