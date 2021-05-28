#include <QtDebug>
#include <QTimer>
#include <QJsonDocument>

#include "checkupdate.h"
#include "filedownloader.h"

namespace  {
static const char UpdatesEndpoint[] = "http://127.0.0.1:8080/updates.json";
static const quint32 OneHour = 3600000;
}

CheckUpdate::CheckUpdate() {
    QTimer *timer = new QTimer(this);
    timer->setTimerType(Qt::VeryCoarseTimer);
    timer->start(2000);
    connect(timer, &QTimer::timeout, this, &CheckUpdate::startCheckUpdates);
}

CheckUpdate::~CheckUpdate(){}

void CheckUpdate::startCheckUpdates() {
    getJson();
}

void CheckUpdate::getJson()
{
    FileDownloader *fd = new FileDownloader(QUrl(UpdatesEndpoint), this);
    connect(fd, &FileDownloader::downloaded, this, &CheckUpdate::loadJson);
}

QJsonObject CheckUpdate::loadJson(QByteArray data)
{
  qDebug() << data;
}
