#ifndef APPTHEME_H
#define APPTHEME_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonArray>

#include "backend.h"


class AppTheme : public QObject
{
    Q_OBJECT
public:
    explicit AppTheme(Backend *backend, QObject *parent = nullptr);
    ~AppTheme();

    // Color Pallettes
    Q_PROPERTY(QString themeName READ themeName WRITE setThemeName NOTIFY themeNameChanged)
    Q_PROPERTY(QString backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QString foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)
    Q_PROPERTY(QString textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QString selectionBackgroud READ selectionBackgroud WRITE setSelectionBackgroud NOTIFY selectionBackgroudChanged)
    Q_PROPERTY(QString selectionForeground READ selectionForeground WRITE setSelectionForeground NOTIFY selectionForegroundChanged)
    Q_PROPERTY(QString buttonColor READ buttonColor WRITE setButtonColor NOTIFY buttonColorChanged)
    Q_PROPERTY(QString disabledColor READ disabledColor WRITE setDisabledColor NOTIFY disabledColorChanged)
    Q_PROPERTY(QString activeColor READ activeColor WRITE setActiveColor NOTIFY activeColorChanged)
    Q_PROPERTY(QString borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(QString highlightColor READ highlightColor WRITE setHighlightColor NOTIFY highlightColorChanged)
    Q_PROPERTY(QString accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)

    // Dimensions
    Q_PROPERTY(bool isLandscapeMode READ isLandscapeMode WRITE setIsLandscapeMode NOTIFY isLandscapeModeChanged)
    Q_PROPERTY(float screenWidth READ screenWidth WRITE setScreenWidth NOTIFY screenWidthChanged)
    Q_PROPERTY(float screenHeight READ screenHeight WRITE setScreenHeight NOTIFY screenHeightChanged)

    // Invokables
    /**
     * @brief setWindowDimensions
     * @param width Current width of the screen
     * @param height Current height of the screen
     */
    Q_INVOKABLE void setWindowDimensions(float width, float height);

    Q_INVOKABLE void selectThemePallette(const QString& palletteName);


    const QString &themeName() const;
    void setThemeName(const QString &newThemeName);

    const QString &backgroundColor() const;
    void setBackgroundColor(const QString &newBackgroundColor);

    const QString &foregroundColor() const;
    void setForegroundColor(const QString &newForegroundColor);

    const QString &textColor() const;
    void setTextColor(const QString &newTextColor);

    const QString &selectionBackgroud() const;
    void setSelectionBackgroud(const QString &newSelectionBackgroud);

    const QString &selectionForeground() const;
    void setSelectionForeground(const QString &newSelectionForeground);

    const QString &buttonColor() const;
    void setButtonColor(const QString &newButtonColor);

    const QString &disabledColor() const;
    void setDisabledColor(const QString &newDisabledColor);

    const QString &activeColor() const;
    void setActiveColor(const QString &newActiveColor);

    const QString &borderColor() const;
    void setBorderColor(const QString &newBorderColor);

    const QString &highlightColor() const;
    void setHighlightColor(const QString &newHighlightColor);

    const QString &accentColor() const;
    void setAccentColor(const QString &newAccentColor);

    bool isLandscapeMode() const;
    void setIsLandscapeMode(bool newIsLandscapeMode);

    float screenWidth() const;
    void setScreenWidth(float newScreenWidth);

    float screenHeight() const;
    void setScreenHeight(float newScreenHeight);

signals:

    void themeNameChanged();

    void backgroundColorChanged();

    void foregroundColorChanged();

    void textColorChanged();

    void selectionBackgroudChanged();

    void selectionForegroundChanged();

    void buttonColorChanged();

    void disabledColorChanged();

    void activeColorChanged();

    void borderColorChanged();

    void highlightColorChanged();

    void accentColorChanged();

    void isLandscapeModeChanged();

    void screenWidthChanged();

    void screenHeightChanged();

private:
    void loadThemes();

    QString m_themeName;
    QString m_backgroundColor;
    QString m_foregroundColor;
    QString m_textColor;
    QString m_selectionBackgroud;
    QString m_selectionForeground;
    QString m_buttonColor;
    QString m_disabledColor;
    QString m_activeColor;
    QString m_borderColor;
    QString m_highlightColor;
    QString m_accentColor;
    bool m_isLandscapeMode;
    float m_screenWidth;
    float m_screenHeight;

    QMap<QString, QJsonObject> m_pallettes;
    Backend *m_backend;
};

#endif // APPTHEME_H
