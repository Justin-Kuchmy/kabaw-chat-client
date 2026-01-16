#include "networking/WebSocketManager.h"



WebSocketManager& WebSocketManager::instance()
{
    static WebSocketManager instance;
    return instance;
}

WebSocketManager::WebSocketManager(QObject *parent): QObject(parent)
{

}



QWebSocket* WebSocketManager::socketForRoom(const QString& room, const QString& username)
{
    if (sockets.contains(room))
    {
        return sockets[room];
    }

    QWebSocket* socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
    sockets[room] = socket;

    
    connect(socket, &QWebSocket::connected, this, [room]() {
        qDebug() << "Connected to room:" << room;
    });

    connect(socket, &QWebSocket::disconnected, this, [room]() {
        qDebug() << "Disconnected from room:" << room;
    });

    connect(socket, &QWebSocket::textMessageReceived, this, [this, room](const QString& msg) {
        emit messageReceived(room, msg);
    });

    QString url = QString("ws://192.168.0.5:8080/ws?username=%1&channel=%2").arg(username, room);

    socket->open(QUrl(url));
    return socket;
}













Message WebSocketManager::parseMessage(const QString& msg)
{
    Message m;

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError || !doc.isObject())
    {
        qWarning() << "Failed to parse JSON:" << parseError.errorString();
        return m; 
    }

    QJsonObject obj = doc.object();
    m.type = obj.value("type").toString().toStdString();
    m.username = obj.value("username").toString().toStdString();
    m.user_id = obj.value("user_id").toString().toStdString();
    m.content = obj.value("content").toString().toStdString();
    m.timestamp = obj.value("timestamp").toString().toStdString();
    m.channel = obj.value("channel").toString().toStdString();

    return m;
}
