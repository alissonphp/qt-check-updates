#include "filedownloader.h"
#include <QtDebug>

FileDownloader::FileDownloader(QUrl url, QObject *parent)
    : QObject(parent) {

    connect(
                &m_manager
                , SIGNAL (finished(QNetworkReply*))
                , this
                , SLOT(fileDownloaded(QNetworkReply*))
            );
    QNetworkRequest request(url);
    m_manager.get(request);
}

FileDownloader::~FileDownloader(){};

void FileDownloader::fileDownloaded(QNetworkReply *reply) {
    m_data = reply->readAll();
    reply->deleteLater();
    emit downloaded(m_data);
}

QByteArray FileDownloader::downloadedData() const {
    return m_data;
}
