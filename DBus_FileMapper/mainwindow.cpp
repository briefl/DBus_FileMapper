#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем экземпляр QDBusInterface для взаимодействия с DBus сервисом

    QString serviceName = "org.artem.Service52";
    QString objectPath = "/org/artem/Service43";
    QString interfaceName = "org.artem.Interface";

    dbusInterface = new QDBusInterface(serviceName, objectPath, interfaceName, QDBusConnection::sessionBus(), this);
    if (!dbusInterface->isValid()) {
        qDebug() << "Failed to get DBus interface!";
        return;
    }


    // Привязываем сигналы к слотам для кнопок
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::registerApplication);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openWithRegisteredApp);
    connect(ui->showAppsButton, &QPushButton::clicked, this, &MainWindow::showRegisteredApplications);
    connect(ui->showFormatsButton, &QPushButton::clicked, this, &MainWindow::showRegisteredFormats);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dbusInterface;    // Не забудьте освободить ресурсы
}

void MainWindow::registerApplication()
{
    QString appName = ui->appNameEdit->text();
    QStringList supportedFormats = ui->formatsEdit->text().split(",", Qt::SkipEmptyParts);

    // Вызываем метод DBus сервиса для регистрации приложения
    QDBusReply<void> reply = dbusInterface->call("RegisterApplication", appName, supportedFormats);
    if (!reply.isValid()) {
        qWarning() << "Failed to register application:" << reply.error().message();
    }
}

void MainWindow::openWithRegisteredApp()
{
    QString filePath = ui->filePathEdit->text();

    // Вызываем метод DBus сервиса для открытия файла
    QDBusReply<void> reply = dbusInterface->call("OpenFileWithRegisteredApp", filePath);
    if (!reply.isValid()) {
        qWarning() << "Failed to open file with registered application:" << reply.error().message();
    }
}

void MainWindow::showRegisteredApplications()
{
    // Получаем список зарегистрированных приложений
    QDBusReply<QStringList> reply = dbusInterface->call("GetRegisteredApplications");
    if (reply.isValid()) {
        QStringList applications = reply.value();

        // Очищаем текстовое поле перед выводом списка
        ui->textBrowser->clear();

        // Выводим список зарегистрированных приложений
        ui->textBrowser->append("Registered Applications:");
        for (const QString &app : applications) {
            ui->textBrowser->append("- " + app);
        }
    } else {
        qWarning() << "Failed to get registered applications:" << reply.error().message();
    }
}

void MainWindow::showRegisteredFormats()
{
    // Получаем список зарегистрированных форматов
    QDBusReply<QStringList> reply = dbusInterface->call("GetRegisteredFormats");
    if (reply.isValid()) {
        QStringList formats = reply.value();

        // Очищаем текстовое поле перед выводом списка
        ui->textBrowser->clear();

        // Выводим список зарегистрированных форматов
        ui->textBrowser->append("Registered Formats:");
        for (const QString &format : formats) {
            ui->textBrowser->append(format);
        }
    } else {
        qWarning() << "Failed to get registered formats:" << reply.error().message();
    }
}
