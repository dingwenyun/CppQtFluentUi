class FluStrongBodyLabel : public FluLabelBase
{
  public:
    FluStrongBodyLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluStrongBodyLabel(QString text, QWidget* parent = nullptr) : FluStrongBodyLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(14, QFont::DemiBold);
    }
};