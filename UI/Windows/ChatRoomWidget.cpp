#include "include/Generated/ui_chatroomwidget.h"
#include "UI/ChatRoomWidget.h"
#include <iostream>
#include "UI/ConnectDialog.h"

ChatRoomWidget::ChatRoomWidget(QWidget *parent): QWidget(parent), ui(new Ui::ChatRoomWidget)
{
    ui->setupUi(this);
    connect(ui->joinButton, &QPushButton::clicked, this, &ChatRoomWidget::onSendClicked);

}

void ChatRoomWidget::onSendClicked()
{
    std::cerr << "ChatRoomWidget::onSendClicked()" << std::endl;
    ConnectDialog *connect = new ConnectDialog{};
    if (connect && connect->exec() == QDialog::Accepted)
    {
        connect->getConnectCruds();
    }

}

ChatRoomWidget::~ChatRoomWidget(){delete ui;}