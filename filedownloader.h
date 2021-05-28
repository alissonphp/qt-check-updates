#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QUrl url, QObject *parent = nullptr) {}
    virtual ~FileDownloader() {}
    QByteArray downloadedData() const;

signals:
    void downloaded();
private slots:
    void fileDownloaded(QNetworkReply *reply);
private:
    QNetworkAccessManager manager;
    QByteArray data;
};

#endif // FILEDOWNLOADER_H
