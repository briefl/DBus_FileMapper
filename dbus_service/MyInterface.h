#ifndef MYINTERFACE_H
#define MYINTERFACE_H

#include <QObject>
#include <QStringList>
#include <QMap>
#include <QUrl>
#include <QtDBus/QtDBus>

class MyInterface : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.artem.Interface")


public:
    explicit MyInterface(QObject *obj) : QDBusAbstractAdaptor(obj) {}

public slots:
    // Методы интерфейса D-Bus
    Q_INVOKABLE void RegisterApplication(const QString &appName, const QStringList &supportedFormats);
    Q_INVOKABLE void OpenFileWithRegisteredApp(const QString &filePath);
    Q_INVOKABLE void RegisterDefaultApplication(const QString &format, const QString &defaultApp);
    Q_INVOKABLE QStringList GetRegisteredApplications();
    Q_INVOKABLE QStringList GetRegisteredFormats();

private:
    QMap<QString, QStringList> registeredApplications;
    QMap<QString, QString> defaultApplications;
};

#endif // MYINTERFACE_H
