#ifndef MYINTERFACE_H
#define MYINTERFACE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>

class FormatMapperDbusInterface : public QObject
{
    Q_OBJECT

public:
    explicit FormatMapperDbusInterface(QObject *parent = nullptr);

public slots:
    // Метод регистрации приложения
    void RegisterApplication(const QString &appName, const QStringList &supportedFormats);

    // Метод открытия файла с зарегистрированным приложением
    void OpenFileWithRegisteredApp(const QString &filePath);

    // Метод регистрации системного приложения по умолчанию для указанного формата
    void RegisterDefaultApplication(const QString &format, const QString &defaultApp);

    // Метод для получения системного приложения по умолчанию для указанного расширения файла
    QString GetDefaultApplication(const QString &extension);

    // Метод для получения списка зарегистрированных приложений
    QStringList GetRegisteredApplications();

    // Метод для получения зарегистрированных форматов и соответствующих им приложений
    QMap<QString, QStringList> GetRegisteredFormats();
};


#endif // MYINTERFACE_H
