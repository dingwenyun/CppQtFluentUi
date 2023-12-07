#pragma once

#include "FluMaskDialog.h"
#include "FluUiMessBox.h"
#include "FluPushButton.h"
#include <QString>
#include "FluPrimaryPushButton.h"

class FluMessageBox : public FluMaskDialog
{
    Q_OBJECT
  public:
    FluMessageBox(QString title, QString content, QWidget* parent = nullptr);
    // parent为顶层窗口
    void setupUi(QString title, QString content, QWidget* parent);

    void __initWidget(QString title, QString content, QWidget* parent);

    void __initLayout();

    void __setQss();

    void __setConnect();

    void __onCancelButtonClicked()
    {
        reject();
        emit noSignal();
    }

    void __onYesButtonClicked()
    {
        accept();
        emit yesSignal();
    }

  signals:
    void yesSignal();
    void noSignal();

  protected:
    QLabel* m_titleLabel;
    QLabel* m_contentLabel;

    FluPrimaryPushButton* m_yesButton;
    FluPushButton* m_noButton;

    QVBoxLayout* m_vBoxLayout;
    QHBoxLayout* m_hBtnLayout;

  protected:
    //  bool eventFilter(QObject *obj, QEvent *event)
    //   {
    //       if (obj == window() && event->type() == QEvent::Resize)
    //       {
    //       }
    //   }
};
