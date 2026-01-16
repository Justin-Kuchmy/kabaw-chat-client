#ifndef CHATROOMWIDGET_H
#define CHATROOMWIDGET_H

#include <QWidget>
#include "entities/entities.h"
#include "networking/WebSocketManager.h"

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

private slots:
    void onSendClicked();
    void onJoinClicked();

private:
    Ui::ChatRoomWidget *ui;
    QWebSocket* socket = nullptr;
    Cruds cruds{};
};

#endif