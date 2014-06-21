#ifndef CONSOLE_H
#define CONSOLE_H

#include <QQuickItem>

class Console : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit Console(QQuickItem *parent = 0);

    QString text() const;
    void setText(const QString &text);

signals:
    void textChanged();

public slots:
    void addLinetoLog(QString line);

private:
    QString m_text;
};

#endif // CONSOLE_H
