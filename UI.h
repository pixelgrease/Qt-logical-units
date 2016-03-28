#ifndef UI_H
#define UI_H

#include <QObject>

class QQmlEngine;
class QJSEngine;

class UI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal dpi READ dpi WRITE setDpi NOTIFY dpiChanged)
    Q_PROPERTY(qreal pt READ pt NOTIFY dpiChanged)
    Q_PROPERTY(qreal mm READ mm NOTIFY dpiChanged)
    Q_PROPERTY(qreal cm READ cm NOTIFY dpiChanged)
    Q_PROPERTY(qreal in READ in NOTIFY dpiChanged)

public:
    explicit UI(QObject *parent = 0);
    static QObject *singleton_instance(QQmlEngine *, QJSEngine *);

    qreal dpi() const { return m_dpi; }
    qreal pt() const  { return m_pt; }
    qreal mm() const  { return m_mm; }
    qreal cm() const  { return m_cm; }
    qreal in() const  { return m_in; }

signals:
    void dpiChanged(qreal dpi);

public slots:

    void setDpi(qreal dpi);

private:
    static UI *m_this;
    qreal m_dpi;
    qreal m_pt;
    qreal m_mm;
    qreal m_cm;
    qreal m_in;
};

#endif // UI_H
