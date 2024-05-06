#ifndef FORMATMAPPER_H
#define FORMATMAPPER_H

#include <QObject>
#include <QMap>
#include <QDebug>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include <QStandardPaths>

class FormatMapper : public QObject
{
    Q_OBJECT

public:
    explicit FormatMapper(QObject *parent = nullptr);

public slots:
    void RegisterApplication(const QString &appName, const QStringList &supportedFormats);
    void OpenFileWithRegisteredApp(const QString &filePath);
    void RegisterDefaultApplication(const QString &format, const QString &defaultApp);
    QString GetDefaultApplication(const QString &extension);
    QStringList GetRegisteredApplications();
    QMap<QString, QStringList> GetRegisteredFormats();

private:
    QMap<QString, QStringList> registeredApplications;
    QMap<QString, QString> defaultApplications;
};

#endif // FORMATMAPPER_H
