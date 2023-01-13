#include "backend.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Backend::Backend(QObject *parent)
    : QObject{parent}
{
    QFile configFile;
    configFile.setFileName(":/src/frontend/Config.json");
    configFile.open(QIODevice::ReadOnly);
    auto data = configFile.readAll();

    QJsonDocument config = QJsonDocument::fromJson(data.data());
    config.fromJson(data.data());

    QJsonObject configs = config.object();

    m_name = configs["appName"].toString();
    m_version = configs["appVersion"].toString();
    m_versionCode = configs["appVersionCode"].toInt();
}

