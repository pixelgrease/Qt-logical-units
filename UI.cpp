#include "UI.h"

const qreal DEFAULT_DPI = 96;

UI * UI::m_this = nullptr;

UI::UI(QObject *parent)
    : QObject(parent)
{
    // Specify the pixels per inch for display
    setDpi(DEFAULT_DPI);
}

// Return pointer to singleton instance for QML runtime
QObject *UI::singleton_instance(QQmlEngine *, QJSEngine *)
{
    if (!m_this)
        m_this = new UI();

    return m_this;
}

// Set the dpi for the current display and update conversion constants
void UI::setDpi(qreal dpi)
{
    if (m_dpi == dpi)
        return;

    // Update the dpi value and conversion constants
    m_dpi = dpi;
    m_pt = m_dpi / 72.0;
    m_mm = m_dpi / 25.4;
    m_cm = m_dpi / 2.54;
    m_in = m_dpi;

    emit dpiChanged(dpi);
}
