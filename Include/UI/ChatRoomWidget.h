#ifndef CHATROOMWIDGET_H
#define CHATROOMWIDGET_H

#include <QWidget>
#include "entities/entities.h"
#include "networking/WebSocketManager.h"
#include <QListWidgetItem>

namespace Ui
{
    class ChatRoomWidget;
};

class ChatRoomWidget: public QWidget
{
    Q_OBJECT
public:
    explicit ChatRoomWidget(QWidget *parent = nullptr);
    ~ChatRoomWidget();
    ChatRoomWidget(const ChatRoomWidget&) = delete; //delete copy ctor
    ChatRoomWidget& operator=(const ChatRoomWidget&) = delete; //delete assignment ctor
    void addMessageToList(QString msg);
    void reloadChatRoom(QListWidgetItem *item);
    

private slots:
    void onMessgeBoxChanged(QString text);
    void onSendClicked();
    void onJoinClicked();

private:
    Ui::ChatRoomWidget *ui;
    QWebSocket* socket = nullptr;
    Cruds cruds{};
    QString message{};
};

#endif