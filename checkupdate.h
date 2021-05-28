#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H

#include <QObject>
#include <QJsonDocument>

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
    QJsonDocument loadJson();
};

#endif // CHECKUPDATE_H
