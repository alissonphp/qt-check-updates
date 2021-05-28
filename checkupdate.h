#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H

#include <QObject>
#include <QJsonObject>

class CheckUpdate : public QObject
{
    Q_OBJECT
public:
    explicit CheckUpdate();
    virtual ~CheckUpdate();
    void startCheckUpdates();

signals:
    void newUpdatesAvailable(bool available);

private:
    void getJson();
    QJsonObject loadJson(QByteArray data);

};

#endif // CHECKUPDATE_H
