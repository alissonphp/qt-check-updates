#include <QtDebug>
#include <QTimer>

#include "checkupdate.h"

namespace  {
static const char UpdatesEndpoint[] = "http://127.0.0.1:8080/updates.json";
static const quint32 OneHour = 3600000;
}

CheckUpdate::CheckUpdate() {
    QTimer *timer = new QTimer(this);
    timer->setTimerType(Qt::VeryCoarseTimer);
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &CheckUpdate::startCheckUpdates);
}

CheckUpdate::~CheckUpdate(){}

void CheckUpdate::startCheckUpdates() {
    qDebug() << "im here!";
}
