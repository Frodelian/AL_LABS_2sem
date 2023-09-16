#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QVector>

struct Item // структура события
{
    QDateTime date_start; // дата и время начала
    QDateTime date_end; // дата и время окончания
    QString placeholder; // заметка
    QString description; // описание

    Item(QDateTime _date_start, QDateTime _date_end, QString _placeholder, QString _description) : date_start(_date_start), date_end(_date_end), placeholder(_placeholder), description(_description) {}; // конструктор инициализации события
};

class EventList // список событий
{
private:
    QVector<Item> itemList; // массив событий
public:
    bool add(QDateTime _date_start, QDateTime _date_end, QString _placeholder, QString _description); // метод добавления события
    void loadToFile(QString& filename); // метод загрузки событий в файл. нужен чтобы при закрытии программы и открытии события сохранялись
    void print(); // метод для отладки
    QVector<Item> getEvents(){return itemList;}; // метод который возвращает информацию о событиях в ui
    EventList(QString& filename);
};

#endif // EVENTLIST_H
