#ifndef WEBSOCKETMANAGER_H
#define WEBSOCKETMANAGER_H

#include <QObject>
#include <QWebSocket>
#include <QMap>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include "entities/entities.h"

class WebSocketManager : public QObject
{
    Q_OBJECT
public:
    static WebSocketManager& instance();
    QWebSocket* socketForRoom(const QString& room, const QString& username);
    WebSocketManager(const WebSocketManager&) = delete; //delete copy ctor
    WebSocketManager& operator=(const WebSocketManager&) = delete; //delete assignment ctor

    static Message parseMessage(const QString& msg);

signals:
    void messageReceived(const QString& room, const QString& msg);

private slots:

private:
    explicit WebSocketManager(QObject *parent = nullptr);
    QMap<QString, QWebSocket*> sockets;
};

#endif