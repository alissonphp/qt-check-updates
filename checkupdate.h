#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H

#include <QObject>
#include <QJsonObject>

#include "filedownloader.h"

class CheckUpdatePrivate;

class CheckUpdate final : public QObject
{
    Q_OBJECT
public:
    explicit CheckUpdate();
    virtual ~CheckUpdate();
    void startCheckUpdates();
    void setParsedJson(QJsonDocument json);
    QJsonObject getParsedJson();

signals:
    void newUpdatesAvailable(bool available);

private:
    void getJsonFromServer();
    CheckUpdatePrivate *d;
    FileDownloader *m_fileDownloader;
    QJsonObject m_json;
};

#endif // CHECKUPDATE_H
