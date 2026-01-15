#include "UI/MainWindow.h"
#include <QApplication>
#include <QMenuBar>
#include <QFile>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("Kabaw Chat Client");
    resize(1200,700);

    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *fileMenu = menuBar->addMenu("&File");
    fileMenu->addAction("New");
    fileMenu->addAction("Open");
    fileMenu->addAction("Save");

    QAction *exitButton = fileMenu->addAction("Exit");

    QMenu *helpMenu = menuBar->addMenu("&Help");
    helpMenu->addAction("About");
    
    setMenuBar(menuBar);

    connect(exitButton, &QAction::triggered, this, [this]() {QApplication::quit();});
}

MainWindow::~MainWindow()
{

}