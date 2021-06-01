#include <QtDebug>
#include <QTimer>
#include <QJsonDocument>

#include "checkupdate.h"
#include "filedownloader.h"

namespace  {
static const char UpdatesEndpoint[] = "http://127.0.0.1:8080/updates.json";
static const quint32 OneHour = 1000;
}

class CheckUpdatePrivate {
public:
    QTimer *m_checkUpdatesTimer = nullptr;
};

CheckUpdate::CheckUpdate()
    : d(new CheckUpdatePrivate)
{
    d->m_checkUpdatesTimer = new QTimer(this);
    d->m_checkUpdatesTimer->setTimerType(Qt::VeryCoarseTimer);
    d->m_checkUpdatesTimer->start(OneHour);
    connect(
                d->m_checkUpdatesTimer
                , &QTimer::timeout
                , this
                , &CheckUpdate::startCheckUpdates
                );
}

CheckUpdate::~CheckUpdate(){
    delete d;
}

void CheckUpdate::startCheckUpdates() {
    m_fileDownloader = new FileDownloader(QUrl(UpdatesEndpoint), this);
    connect(m_fileDownloader, &FileDownloader::downloaded, this, &CheckUpdate::getJsonFromServer);
}

void CheckUpdate::getJsonFromServer()
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(m_fileDownloader->downloadedData());
    setParsedJson(jsonDocument);
}

void CheckUpdate::setParsedJson(QJsonDocument json)
{
    m_json = json.object();
    QString current {"2.0.9-4"};
    QString checking = getParsedJson()["kernel"].toObject()["interfaces"].toObject()["version"].toString();
    if( current != checking) {
        qDebug() << "checking kernel :: interfaces :: version "<< current << QDateTime::currentDateTime().toString() << "NEW VERSION FOUND" << checking;
    } else {
        qDebug() << "checking kernel :: interfaces :: version "<< current << QDateTime::currentDateTime().toString() << "no updates found";
    }
}

QJsonObject CheckUpdate::getParsedJson()
{
    return m_json;
}
