#include <QCoreApplication>
#include <QtDBus>
#include <QObject>
#include "MyInterface.h"

class FormatMapperDBusService : public QObject
{
    Q_OBJECT

public:
    FormatMapperDBusService(QObject *parent = nullptr) : QObject(parent) {
        // Регистрируем наш класс как DBus сервис
        QDBusConnection connection = QDBusConnection::sessionBus();
        QString serviceName = "org.artem.Service52";
        QString objectPath = "/org/artem/Service43";

        if (!connection.registerService(serviceName)) {
            qWarning() << "Failed to register DBus service:" << serviceName;
        } else {
            // Регистрируем объект для обработки запросов от клиентов с явным указанием пути
            if (!connection.registerObject(objectPath, this)) {
                qWarning() << "Failed to register DBus object at path:" << objectPath;
            } else {
                qDebug() << "DBus service registered successfully with object path:" << objectPath;
            }
        }

        // Регистрируем интерфейс
        MyInterface *interface = new MyInterface(this);
        QString interfacePath = "/org/artem/Interface";
        if (!connection.registerObject(interfacePath, interface)) {
            qWarning() << "Failed to register DBus interface at path:" << interfacePath;
        } else {
            qDebug() << "DBus interface registered successfully.";
        }
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Создание экземпляра сервиса
    FormatMapperDBusService service;



    return app.exec();
}

#include "main.moc"
