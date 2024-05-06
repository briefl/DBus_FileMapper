#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDBus/QtDBus>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void registerApplication();
    void openWithRegisteredApp();
    void showRegisteredApplications();
    void showRegisteredFormats();

private:
    Ui::MainWindow *ui;
    QDBusInterface *dbusInterface;
};

#endif // MAINWINDOW_H
