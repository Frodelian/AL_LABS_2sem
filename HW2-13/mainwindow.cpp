#include "mainwindow.h"
#include "event.h"
#include "eventlist.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add.setMainUi(ui);
    filename = "events.txt";
    events = new EventList(filename);
    add.addEventList(events);
    // Добавление элементов списка в ui-listWidget
    for (const Item& event : events->getEvents()) {
        QString eventInfo = event.date_start.toString() + " - " + event.date_end.toString() + ": " + event.placeholder + " " +event.description;
        ui->listWidget->addItem(eventInfo);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    events->loadToFile(filename);
    delete events;
}


void MainWindow::on_pushButton_clicked()
{
    add.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    QDate selectedDate = QDate::fromString(ui->lineEdit->text(), "yyyy-M-d");
    ui->listWidget->clear(); // Очистить список перед выводом новых событий

    for (const Item& event : events->getEvents()) {
        if (event.date_start.date() == selectedDate || event.date_end.date() == selectedDate) {
            QString eventInfo = event.date_start.toString() + " - " + event.date_end.toString() + ": " + event.placeholder + " " +event.description;
            ui->listWidget->addItem(eventInfo);
        }
    }
}
