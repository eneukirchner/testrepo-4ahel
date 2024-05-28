#include "portscanner.h"

Portscanner::Portscanner(QWidget *parent)
    : QWidget(parent),
      m_socket(new QTcpSocket(this)),
      m_timeout(1000)
{
    setupUi(this);
    connect(m_socket, &QTcpSocket::connected, this, &Portscanner::showConnected);
}

Portscanner::~Portscanner()
{
}

void Portscanner::on_goButton_clicked()
{
    statusLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
    m_statustext.clear();
    m_statustext = "Open Ports:  ";
    statusLabel->setText(m_statustext);

    QString host = hostnameEntry->text();
    QStringList portlist = portEntry->text().split(",");

    foreach (QString port, portlist) {
        m_socket->connectToHost(host, port.toInt());
        m_socket->waitForConnected(m_timeout);
    }
}
void Portscanner::showConnected()
{
    int port = m_socket->peerPort();
    qDebug() << port;
    m_statustext += QString::number(port) + " ";

    statusLabel->setStyleSheet(QString::fromUtf8("color: rgb(39, 173, 5);"));
    statusLabel->setText(m_statustext);
    m_socket->disconnectFromHost();
}


