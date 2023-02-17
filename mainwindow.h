#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots://методы
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations_function();
    void on_pushButton_clear_clicked();
    void on_pushButton_equal_clicked();
    void math_operations();
    void on_pushButton_erase_clicked();
};
#endif // MAINWINDOW_H
