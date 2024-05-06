#include "formatmapper.h"
#include <QProcess>

FormatMapper::FormatMapper(QObject *parent)
    : QObject(parent)
{
}

// Метод для регистрации приложения для поддерживаемых форматов
void FormatMapper::RegisterApplication(const QString &appName, const QStringList &supportedFormats)
{
    qDebug() << "Registering application:" << appName << "Supported formats:" << supportedFormats;

    if (appName.isEmpty()) {
        qWarning() << "Empty application name provided.";
        return;
    }

    if (supportedFormats.isEmpty()) {
        qWarning() << "No supported formats provided for application:" << appName;
        return;
    }

    // Проверяем, зарегистрировано ли уже приложение
    if (registeredApplications.contains(appName)) {
        qWarning() << "Application" << appName << "is already registered.";
        return;
    }

    // Регистрируем приложения с его поддерживаемыми форматами
    registeredApplications.insert(appName, supportedFormats);

    qDebug() << "Application" << appName << "registered successfully with formats:" << supportedFormats;
}

// Метод для регистрации системного приложения по умолчанию для указанного формата
void FormatMapper::RegisterDefaultApplication(const QString &format, const QString &defaultApp)
{
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

// Метод для получения системного приложения по умолчанию для указанного расширения файла
QString FormatMapper::GetDefaultApplication(const QString &extension)
{
    // Используем команду xdg-mime для запроса системного приложения по умолчанию для указанного типа файла
    QString command = "xdg-mime query default " + extension;
    QProcess process;
    process.start(command);
    process.waitForFinished();
    QString result = process.readAllStandardOutput().trimmed();
    return result;
}

// Метод для открытия файла с помощью зарегистрированных приложений
void FormatMapper::OpenFileWithRegisteredApp(const QString &filePath)
{
    qDebug() << "Opening file with registered application:" << filePath;

    if (filePath.isEmpty()) {
        qWarning() << "Empty file path provided.";
        return;
    }

    // Получаем расширения файла
    QString extension = QFileInfo(filePath).suffix();

    // Ищем зарегистрированные приложений для формата файла
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
        if (QDesktopServices::openUrl(QUrl::fromLocalFile(filePath))) {
            qInfo() << "Opened file with default application.";
            // Регистрируем системне приложение по умолчанию для данного формата
            QStringList defaultApp;
            defaultApp.append(extension);
            RegisterApplication("Default Application", defaultApp);
        } else {
            qWarning() << "Failed to open file with default application.";
        }
        return;
    }

    // Выбираем первое приложение в списке зарегестрированных для такого формата данных
    QString application = applications.first();
    qDebug() << "Opening file with application:" << application;

    // Запускаем приложение с файлом
    QStringList arguments;
    arguments << filePath;

    if (!QProcess::startDetached(application, arguments)) {
        qWarning() << "Failed to start application:" << application;
        return;
    }

    qDebug() << "File opened successfully with application:" << application;
}

// Метод для получения списка зарегистрированных приложений
QStringList FormatMapper::GetRegisteredApplications()
{
    QStringList applications;

    for (auto it = registeredApplications.constBegin(); it != registeredApplications.constEnd(); ++it) {
        applications.append(it.key());
    }

    return applications;
}

// Метод для получения зарегистрированных форматов и соответствующих им приложений
QMap<QString, QStringList> FormatMapper::GetRegisteredFormats()
{
    return registeredApplications;
}

