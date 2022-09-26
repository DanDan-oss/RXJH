#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inject.h"

#define WINDOWS_HEIGHT 600
#define WINDOWS_WIDGHT 500
#define WINDOWS_TITLE "注入器\0"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Inject* injectWindow = nullptr;
};
#endif // MAINWINDOW_H
