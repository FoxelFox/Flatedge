#include "console.h"


Console::Console(QQuickItem *parent) :
    QQuickItem(parent)
{
}

QString Console::text() const
{
    return m_text;
}

void Console::setText(const QString &text)
{
    m_text = text;
}

void Console::addLinetoLog(QString line)
{
    m_text = m_text + "\n" + line;
    emit textChanged();
}
