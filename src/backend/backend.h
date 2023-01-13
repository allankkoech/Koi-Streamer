#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

    // Application general
    Q_PROPERTY(QString appName MEMBER m_name NOTIFY appNameChanged)
    Q_PROPERTY(QString appVersion MEMBER m_version NOTIFY versionChanged)
    Q_PROPERTY(int appVersionCode MEMBER m_versionCode NOTIFY versionCodeChanged)
    Q_PROPERTY(bool isPortrait MEMBER m_isPortrait NOTIFY portraitChanged)

    bool isPortrait() const;
    void setIsPortrait(bool newIsPortrait);

signals:

    void versionChanged();

    void versionCodeChanged();

    void portraitChanged();

    void appNameChanged();

private:

    QString m_version;
    int m_versionCode;
    bool m_isPortrait;
    QString m_name;
};

#endif // BACKEND_H
