#include "mainwindow.h"
#include "./ui_mainwindow.h"


double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(digits_numbers()));//работаем с этим объектом
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_A,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_B,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_C,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_D,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_E,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_F,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_percent,SIGNAL(clicked()), this, SLOT(operations_function()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_del,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_del->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button1 = (QPushButton*)sender();//отслеживание кнопки
    double numbers;
    QString new_string;

    if(ui->result_show->text().contains(".") && button1->text() == "0"){
        new_string = (ui->result_show->text() + button1->text());
    }else{
        numbers = (ui->result_show->text() + button1->text()).toDouble();
        new_string = QString::number(numbers, 'g', 16);//превращение числа в строку
    }
    ui->result_show->setText(new_string);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.'))) {
        ui->result_show->setText(ui->result_show->text() + ".");
    }
}

void MainWindow::operations_function()
{
    QPushButton *button1 = (QPushButton*)sender();
    double numbers;
    QString new_string;

    if(button1->text() == "%"){
        numbers = (ui->result_show->text()).toDouble();
        numbers = numbers * 0.01;
        new_string = QString::number(numbers, 'g', 16);

    ui->result_show->setText(new_string);
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);//неактивы
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, num_second;

     QString new_string;

     num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber = num_first + num_second;
        new_string = QString::number(labelNumber, 'g', 16);
        ui->result_show->setText(new_string);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
        labelNumber = num_first - num_second;
        new_string = QString::number(labelNumber, 'g', 16);
        ui->result_show->setText(new_string);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_del->isChecked()){
        if(num_second == 0){
            ui->result_show->setText("0");
        }else{
            labelNumber = num_first / num_second;
            new_string = QString::number(labelNumber, 'g', 16);
            ui->result_show->setText(new_string);
        }
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_mult->isChecked()){
        labelNumber = num_first * num_second;
        new_string = QString::number(labelNumber, 'g', 16);
        ui->result_show->setText(new_string);
        ui->pushButton_plus->setChecked(false);
    }
}

void MainWindow::math_operations()
{
     QPushButton *button1 = (QPushButton*)sender();

     num_first = ui->result_show->text().toDouble();

     ui->result_show->setText("");

     button1->setChecked(true);

}

void MainWindow::on_pushButton_erase_clicked()
{
    QString s = ui->result_show->text();
    s.chop(1);//удаление 1 элемента
    if(s.isEmpty()){
        s = " 0 ";
    }
    ui->result_show->setText(s);
}

////////radiobuttons///////////




