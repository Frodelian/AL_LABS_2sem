#include "eventlist.h"

EventList::EventList(QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // ошибка открытия файла
        return;
    }

    QTextStream in(&file); // создаём текстовый поток
    while (!in.atEnd()) { // считываем информацию из файла пока она есть
        QString line = in.readLine();
        QStringList parts = line.split(" ");

        if (parts.size() >= 4) {
            QDateTime date_start = QDateTime::fromString(parts[0] + " " + parts[1], "yyyy-MM-dd hh:mm:ss");
            QDateTime date_end = QDateTime::fromString(parts[2] + " " + parts[3], "yyyy-MM-dd hh:mm:ss");
            QString placeholder = parts[4];
            QString description = parts[5];

            if (date_end >= QDateTime::currentDateTime()) { // если событие не истекло то загружаем его
                Item item(date_start, date_end, placeholder, description);
                itemList.push_back(item);
            }
        }
    }

    file.close();
}


bool EventList::add(QDateTime _date_start, QDateTime _date_end, QString _placeholder, QString _description)
{
    QVector<Item>::iterator it = std::find_if(itemList.begin(), itemList.end(), [&](const Item& item) {
        return item.date_start == _date_start && item.date_end == _date_end;
    });
    if(it == itemList.end()){
        itemList.push_back(Item(_date_start, _date_end, _placeholder, _description));
        return true;
    } else {
        qDebug() << "false";
        return false;
    }
}

void EventList::print(){
    for (const Item& item : itemList) { // проходим по всем событиям
        qDebug() << item.date_start.toString("yyyy-MM-dd hh:mm:ss") << item.date_end.toString("yyyy-MM-dd hh:mm:ss") << item.placeholder << item.description;
    }
}

void EventList::loadToFile(QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Ошибка открытия файла
        return;
    }

    QTextStream out(&file);// создаём текстовый поток
    for (const Item& item : itemList) { // проходим по всем событиям
        if(item.date_end > QDateTime::currentDateTime()){
            out << item.date_start.toString("yyyy-MM-dd hh:mm:ss") << " "
                << item.date_end.toString("yyyy-MM-dd hh:mm:ss") << " "
                << item.placeholder << " "
                << item.description << "\n";
        }
    }

    file.close();
}

