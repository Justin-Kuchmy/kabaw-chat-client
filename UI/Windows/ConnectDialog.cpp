#include "include/Generated/ui_connectdialog.h"
#include "UI/ConnectDialog.h"
#include <iostream>


ConnectDialog::ConnectDialog(QWidget *parent): QDialog(parent), ui(new Ui::ConnectDialog)
{
    ui->setupUi(this); 
    connect(ui->connectButton, &QPushButton::clicked, this, &ConnectDialog::onConnectClicked);


}
void ConnectDialog::onConnectClicked()
{
    std::cerr << "ConnectDialog::onConnectClicked()" << std::endl;
    userName = ui->usernameText->toPlainText().toStdString();
    chatRoomName = ui->chatroomText->toPlainText().toStdString();

    accept();

}

void ConnectDialog::getConnectCruds()
{
    std::cout << "Trying to join "<< this->chatRoomName << " as "<< userName << std::endl;
}

ConnectDialog::~ConnectDialog(){delete ui;}