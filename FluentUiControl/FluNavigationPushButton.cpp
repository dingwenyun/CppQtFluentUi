#include "FluNavigationPushButton.h"

FluNavigationPushButton::FluNavigationPushButton(QPixmap icon, QString text, bool bSelectable, QWidget* parent /*= nullptr*/) : FluNavigationWidget(bSelectable, parent)
{
    m_icon = icon;
    m_text = text;
    // setFont(this);
}
