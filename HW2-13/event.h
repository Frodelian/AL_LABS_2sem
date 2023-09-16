#ifndef EVENT_H
#define EVENT_H

#include <QDialog>
#include <QDateTime>
#include <QDebug>

#include "eventlist.h"
#include "./ui_mainwindow.h"

namespace Ui {
class Event;
}

class Event : public QDialog
{
    Q_OBJECT

public:
    void addEventList(EventList* events);
    void setMainUi(Ui::MainWindow *ui);
    explicit Event(QWidget *parent = nullptr);
    ~Event();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Event *ui;
    Ui::MainWindow *main_ui;
    EventList* events;
};

#endif // EVENT_H
