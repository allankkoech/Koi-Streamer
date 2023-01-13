#include "apptheme.h"

AppTheme::AppTheme(Backend *backend, QObject *parent)
    : QObject{parent}, m_backend(backend)
{
    // Load available themes
    loadThemes();

    // [TODO] Connect to backend settings load

}

AppTheme::~AppTheme()
{
    delete m_backend;
}

void AppTheme::setWindowDimensions(float width, float height)
{
    // Window in landscape mode if width > height
    // else portrait
    setIsLandscapeMode(width > height);

    // Update dimensions
    setScreenWidth(width);
    setScreenHeight(height);
}

void AppTheme::selectThemePallette(const QString &palletteName)
{
    qDebug() << palletteName << m_pallettes.size();

    if(m_pallettes.size() == 0)
        return;

    auto pallette = m_pallettes[palletteName];

    qDebug() << pallette["background"].toString();

    setThemeName(palletteName);
    setBackgroundColor(pallette["background"].toString());
    setForegroundColor(pallette["foreground"].toString());
    setTextColor(pallette["text"].toString());
    setSelectionBackgroud(pallette["selectionBackground"].toString());
    setSelectionForeground(pallette["selectionForeground"].toString());
    setButtonColor(pallette["buttons"].toString());
    setDisabledColor(pallette["disabled"].toString());
    setActiveColor(pallette["active"].toString());
    setBorderColor(pallette["border"].toString());
    setHighlightColor(pallette["highlight"].toString());
    setAccentColor(pallette["accent"].toString());
}

const QString &AppTheme::themeName() const
{
    return m_themeName;
}

void AppTheme::setThemeName(const QString &newThemeName)
{
    if (m_themeName == newThemeName)
        return;
    m_themeName = newThemeName;
    emit themeNameChanged();
}

const QString &AppTheme::backgroundColor() const
{
    return m_backgroundColor;
}

void AppTheme::setBackgroundColor(const QString &newBackgroundColor)
{
    if (m_backgroundColor == newBackgroundColor)
        return;
    m_backgroundColor = newBackgroundColor;
    emit backgroundColorChanged();
}

const QString &AppTheme::foregroundColor() const
{
    return m_foregroundColor;
}

void AppTheme::setForegroundColor(const QString &newForegroundColor)
{
    if (m_foregroundColor == newForegroundColor)
        return;
    m_foregroundColor = newForegroundColor;
    emit foregroundColorChanged();
}

const QString &AppTheme::textColor() const
{
    return m_textColor;
}

void AppTheme::setTextColor(const QString &newTextColor)
{
    if (m_textColor == newTextColor)
        return;
    m_textColor = newTextColor;
    emit textColorChanged();
}

const QString &AppTheme::selectionBackgroud() const
{
    return m_selectionBackgroud;
}

void AppTheme::setSelectionBackgroud(const QString &newSelectionBackgroud)
{
    if (m_selectionBackgroud == newSelectionBackgroud)
        return;
    m_selectionBackgroud = newSelectionBackgroud;
    emit selectionBackgroudChanged();
}

const QString &AppTheme::selectionForeground() const
{
    return m_selectionForeground;
}

void AppTheme::setSelectionForeground(const QString &newSelectionForeground)
{
    if (m_selectionForeground == newSelectionForeground)
        return;
    m_selectionForeground = newSelectionForeground;
    emit selectionForegroundChanged();
}

const QString &AppTheme::buttonColor() const
{
    return m_buttonColor;
}

void AppTheme::setButtonColor(const QString &newButtonColor)
{
    if (m_buttonColor == newButtonColor)
        return;
    m_buttonColor = newButtonColor;
    emit buttonColorChanged();
}

const QString &AppTheme::disabledColor() const
{
    return m_disabledColor;
}

void AppTheme::setDisabledColor(const QString &newDisabledColor)
{
    if (m_disabledColor == newDisabledColor)
        return;
    m_disabledColor = newDisabledColor;
    emit disabledColorChanged();
}

const QString &AppTheme::activeColor() const
{
    return m_activeColor;
}

void AppTheme::setActiveColor(const QString &newActiveColor)
{
    if (m_activeColor == newActiveColor)
        return;
    m_activeColor = newActiveColor;
    emit activeColorChanged();
}

const QString &AppTheme::borderColor() const
{
    return m_borderColor;
}

void AppTheme::setBorderColor(const QString &newBorderColor)
{
    if (m_borderColor == newBorderColor)
        return;
    m_borderColor = newBorderColor;
    emit borderColorChanged();
}

const QString &AppTheme::highlightColor() const
{
    return m_highlightColor;
}

void AppTheme::setHighlightColor(const QString &newHighlightColor)
{
    if (m_highlightColor == newHighlightColor)
        return;
    m_highlightColor = newHighlightColor;
    emit highlightColorChanged();
}

const QString &AppTheme::accentColor() const
{
    return m_accentColor;
}

void AppTheme::setAccentColor(const QString &newAccentColor)
{
    if (m_accentColor == newAccentColor)
        return;
    m_accentColor = newAccentColor;
    emit accentColorChanged();
}

bool AppTheme::isLandscapeMode() const
{
    return m_isLandscapeMode;
}

void AppTheme::setIsLandscapeMode(bool newIsLandscapeMode)
{
    if (m_isLandscapeMode == newIsLandscapeMode)
        return;
    m_isLandscapeMode = newIsLandscapeMode;
    emit isLandscapeModeChanged();
}

float AppTheme::screenWidth() const
{
    return m_screenWidth;
}

void AppTheme::setScreenWidth(float newScreenWidth)
{
    if (qFuzzyCompare(m_screenWidth, newScreenWidth))
        return;
    m_screenWidth = newScreenWidth;
    emit screenWidthChanged();
}

float AppTheme::screenHeight() const
{
    return m_screenHeight;
}

void AppTheme::setScreenHeight(float newScreenHeight)
{
    if (qFuzzyCompare(m_screenHeight, newScreenHeight))
        return;
    m_screenHeight = newScreenHeight;
    emit screenHeightChanged();
}

void AppTheme::loadThemes()
{
    QFile themeFile;
    themeFile.setFileName(":/src/frontend/Theme.json");
    themeFile.open(QIODevice::ReadOnly);
    auto data = themeFile.readAll();

    // Create JSON Object
    QJsonDocument themeDoc = QJsonDocument::fromJson(data.data());
    QJsonObject themeObj = themeDoc.object();
    QJsonArray pallette = themeObj["pallette"].toArray();

    // qDebug() << themeDoc;
    m_pallettes.clear();

    for(const auto &pal : pallette) {
        QJsonObject palObj = pal.toObject();
        QString name = palObj["name"].toString();
        QJsonObject style = palObj["style"].toObject();

        // qDebug() << name << style;

        m_pallettes[name] = style;
    }

    selectThemePallette(pallette[0].toObject()["name"].toString());
}
