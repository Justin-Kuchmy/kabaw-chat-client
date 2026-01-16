#include <QApplication>
#include <string>
#include <iostream>
#include "UI/MainWindow.h"


#include <QWebSocket>
#include <QTimer>
#include "networking/WebSocketManager.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    WebSocketManager::instance();
    MainWindow window;
    window.show();
    
    return app.exec();
}
