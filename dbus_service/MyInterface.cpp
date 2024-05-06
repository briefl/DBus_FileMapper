#include "MyInterface.h"

void MyInterface::RegisterApplication(const QString &appName, const QStringList &supportedFormats)
{
    // qDebug() << "Registering application:" << appName << "Supported formats:" << supportedFormats;

    if (appName.isEmpty()) {
        qWarning() << "Empty application name provided.";
        return;
    }

    if (supportedFormats.isEmpty()) {
        qWarning() << "No supported formats provided for application:" << appName;
        return;
    }

    // Регистрируем приложение с его поддерживаемыми форматами
    registeredApplications.insert(appName, supportedFormats);

    // qDebug() << "Application" << appName << "registered successfully with formats:" << supportedFormats;
}

void MyInterface::OpenFileWithRegisteredApp(const QString &filePath)
{
    // qDebug() << "Opening file with registered application:" << filePath;

    if (filePath.isEmpty()) {
        qWarning() << "Empty file path provided.";
        return;
    }

    // Получаем расширение файла
    QString extension = QFileInfo(filePath).suffix();

    // Ищем зарегистрированные приложения для формата файла
    QStringList applications;
    for (auto it = registeredApplications.constBegin(); it != registeredApplications.constEnd(); ++it) {
        const QString &app = it.key();
        if (it.value().contains(extension)) {
            applications.append(app);
        }
    }

    if (applications.isEmpty()) {
        qWarning() << "No application found to open file with extension" << extension;

        // Если для формата файла нет зарегистрированных приложений, пытаемся открыть файл с помощью системного приложения по умолчанию
        QProcess process;
        QStringList arguments;
        arguments << filePath;
        process.startDetached("xdg-open", arguments); // Используем xdg-open для открытия файла с помощью системного приложения по умолчанию

        if (process.waitForStarted()) {
            // qInfo() << "Opened file with default application.";
            // Регистрируем системное приложение по умолчанию для данного формата
            QStringList defaultApp;
            defaultApp.append(extension);
            RegisterApplication("Default Application", defaultApp);
        } else {
            qWarning() << "Failed to open file with default application.";
        }
        return;
    }

    // Выбираем первое приложение в списке зарегистрированных для такого формата данных
    QString application = applications.first();
    qDebug() << "Opening file with application:" << application;

    // Запускаем приложение с файлом
    QStringList arguments;
    arguments << filePath;

    if (!QProcess::startDetached(application, arguments)) {
        qWarning() << "Failed to start application:" << application;
        return;
    }

    // qDebug() << "File opened successfully with application:" << application;
}

void MyInterface::RegisterDefaultApplication(const QString &format, const QString &defaultApp)
{
    qDebug() << "Registering default application:" << defaultApp << "for format:" << format;

    if (format.isEmpty()) {
        qWarning() << "Empty format provided.";
        return;
    }

    if (defaultApp.isEmpty()) {
        qWarning() << "Empty default application provided for format:" << format;
        return;
    }

    // Регистрируем системное приложение по умолчанию для формата
    defaultApplications.insert(format, defaultApp);
    qDebug() << "Default application" << defaultApp << "registered successfully for format:" << format;
}

QStringList MyInterface::GetRegisteredApplications()
{
    qDebug() << "Getting registered applications.";
    QStringList applications;

    for (auto it = registeredApplications.constBegin(); it != registeredApplications.constEnd(); ++it) {
        applications.append(it.key());
    }

    return applications;
}

QStringList MyInterface::GetRegisteredFormats()
{
    qDebug() << "Getting registered formats.";
    QStringList formats;

    for (auto it = registeredApplications.constBegin(); it != registeredApplications.constEnd(); ++it) {
        QStringList appFormats = it.value();
        for(const QString &format : appFormats) {
            if(!formats.contains(format)) {
                formats.append(format);
            }
        }
    }

    // qDebug() << "Formats List:" << formats;

    return formats;
}
