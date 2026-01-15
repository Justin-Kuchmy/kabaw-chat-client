#include "include/Generated/ui_chatroomwidget.h"
#include "UI/ChatRoomWidget.h"
#include <iostream>
#include "UI/ConnectDialog.h"

ChatRoomWidget::ChatRoomWidget(QWidget *parent): QWidget(parent), ui(new Ui::ChatRoomWidget)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &ChatRoomWidget::onSendClicked);
    connect(ui->joinButton, &QPushButton::clicked, this, &ChatRoomWidget::onJoinClicked);

}

void ChatRoomWidget::onSendClicked()
{


}

void ChatRoomWidget::onJoinClicked()
{
    ConnectDialog *connect = new ConnectDialog{};
    if (connect && connect->exec() == QDialog::Accepted)
    {
        connect->getConnectCruds();
    }

}

ChatRoomWidget::~ChatRoomWidget(){delete ui;}