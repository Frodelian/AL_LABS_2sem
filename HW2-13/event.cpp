#include "event.h"
#include "ui_event.h"

Event::Event(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Event)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
}

Event::~Event()
{
    delete ui;
}

void Event::setMainUi(Ui::MainWindow *ui){
    main_ui = ui;
}

void Event::addEventList(EventList *_events)
{
    events = _events;
}

void Event::on_pushButton_clicked()
{
    QDateTime eventDateStart = ui->dateTimeEdit->dateTime();// берём из формы время начала события
    QDateTime eventDateEnd = ui->dateTimeEdit_2->dateTime();// берём из формы время окончания события
    if(eventDateStart < QDateTime::currentDateTime() || eventDateEnd < QDateTime::currentDateTime() || eventDateStart > eventDateEnd) { // проверки на правильно заданное время
        ui->label_6->setText("Oops! You can't make time travel! ;)");// если неправильно то выводим ошибку
        ui->label_6->setStyleSheet("color: red"); // меняем цвет ошибки на красный
        qDebug() << "Oops! You can't make time travel! ;)";
    } else {
        QString placeholder = ui->lineEdit->text();
        QString description = ui->textEdit->toPlainText();
        if(!events->add(eventDateStart, eventDateEnd, placeholder, description)){
            ui->label_6->setText("Oops! At this time you have any events ;(");// если на заданное время уже есть мероприятие то выводим ошибку
            ui->label_6->setStyleSheet("color: red"); // меняем цвет ошибки на красный
        } else {
            main_ui->listWidget->clear();
            for (const Item& event : events->getEvents()) {
                QString eventInfo = event.date_start.toString() + " - " + event.date_end.toString() + ": " + event.placeholder + " " +event.description;
                main_ui->listWidget->addItem(eventInfo);
            }
        }
    }
    events->print();
}
