#ifndef APPTHEME_H
#define APPTHEME_H

#include <QObject>

class AppTheme : public QObject
{
    Q_OBJECT
public:
    explicit AppTheme(QObject *parent = nullptr);

signals:

};

#endif // APPTHEME_H
