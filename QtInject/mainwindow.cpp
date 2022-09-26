#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(WINDOWS_WIDGHT, WINDOWS_HEIGHT);
    this->setWindowTitle(WINDOWS_TITLE);

    this->injectWindow = new Inject(this);
    this->injectWindow->show();


}

MainWindow::~MainWindow()
{
}

