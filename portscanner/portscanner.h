#ifndef PORTSCANNER_H
#define PORTSCANNER_H

#include "ui_portscanner.h"
#include <QTcpSocket>

#include <QWidget>

class Portscanner : public QWidget, private Ui::Portscanner
{
    Q_OBJECT

public:
    Portscanner(QWidget *parent = nullptr);
    ~Portscanner();
private slots:
    void on_goButton_clicked();
    void showConnected();

private:
    QTcpSocket* m_socket;
    int m_timeout;
    QString m_statustext;
};
#endif // PORTSCANNER_H
