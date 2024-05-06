#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include <QStringList>
#include <QMap>
#include <QtDBus/QtDBus>

class FormatMapperDBusService : public QObject, protected QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.artem.Service11")

public:
    explicit FormatMapperDBusService(QObject *parent = nullptr);

public slots:
    // Методы интерфейса D-Bus
    Q_INVOKABLE void RegisterApplication(const QString &appName, const QStringList &supportedFormats);
    Q_INVOKABLE void OpenFileWithRegisteredApp(const QString &filePath);
    Q_INVOKABLE void RegisterDefaultApplication(const QString &format, const QString &defaultApp);
    Q_INVOKABLE QString GetDefaultApplication(const QString &extension);
    Q_INVOKABLE QStringList GetRegisteredApplications();
    Q_INVOKABLE QMap<QString, QStringList> GetRegisteredFormats();
};

#endif // INTERFACE_H
