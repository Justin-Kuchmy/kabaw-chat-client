#ifndef CHATROOMWIDGET_H
#define CHATROOMWIDGET_H

#include <QWidget>

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

private slots:
    void onSendClicked();
    void onJoinClicked();

private:
    Ui::ChatRoomWidget *ui;
};

#endif