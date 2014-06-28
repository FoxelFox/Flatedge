#include "console.h"
#include <iostream>


Console *Console::s_console = 0;

Console::Console(QQuickItem *parent) :
    QQuickItem(parent)
{
    // setup singelton
    if(s_console == 0)
        s_console = this;
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

void Console::sWrite(QString line)
{
    s_console->m_text = s_console->m_text + "\n" + line;
    emit s_console->textChanged();
}


void Console::sWriteError(QString line)
{
    // TODO: write with red color
    s_console->m_text = s_console->m_text + "\n" + line;
    std::cout << line.toStdString() << std::endl;
    emit s_console->textChanged();
}
