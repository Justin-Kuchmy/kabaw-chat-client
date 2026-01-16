#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QWidget>
#include <QDialog>
#include "entities/entities.h"

namespace Ui
{
    class ConnectDialog;
};

class ConnectDialog: public QDialog
{
    Q_OBJECT
public:
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();
    ConnectDialog(const ConnectDialog&) = delete; //delete copy ctor
    ConnectDialog& operator=(const ConnectDialog&) = delete; //delete assignment ctor
    Cruds getConnectCruds();

private slots:
    void onConnectClicked();

private:
    Ui::ConnectDialog *ui;
    std::string userName{};
    std::string chatRoomName{};
};

#endif