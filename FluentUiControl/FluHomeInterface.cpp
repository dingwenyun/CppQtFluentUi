#include "FluHomeInterface.h"
#include <QStyleOption>
#include <QPainter>

FluHomeInterface::FluHomeInterface(QWidget* parent /*= nullptr*/) : FluScrollArea(parent)
{
    m_view = new QWidget(this);
    m_bannerWidget = new FluBannerWidget(this);
    m_vLayout = new QVBoxLayout(m_view);
    m_view->setLayout(m_vLayout);


    __initWidget();

    __loadSamples();
}

void FluHomeInterface::__initWidget()
{
    m_view->setObjectName("view");
    setObjectName("homeInterface");

    //setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWidget(m_view);
    setWidgetResizable(true);

    m_vLayout->setSpacing(40);
    m_vLayout->addWidget(m_bannerWidget);
    m_vLayout->setAlignment(Qt::AlignTop);

    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluHomeInterface.qss");
    setStyleSheet(qss);
}

void FluHomeInterface::__loadSamples()
{
    m_basicInputView = new FluSampleCardView(m_view, "Basic input samples");
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/Button.png"), "Button", "A control that responds to user input and emit clicked signal.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/CheckBox.png"), "CheckBox", "A control that a user can select or clear.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/ComboBox.png"), "ComboBox", "A drop-down list of items a user can select from.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/DropDownButton.png"), "DropDownButton", "A button that displays a flyout of choices when clicked.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/HyperlinkButton.png"), "HyperlinkButton", "A button that appears as hyperlink text, and can navigate to a URI or handle a Click event.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/RadioButton.png"), "RadioButton", "A control that allows a user to select a single option from a group of options.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/Slider.png"), "Slider", "A control that lets the user select from a range of values by moving a Thumb control along a track.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/SplitButton.png"), "SplitButton", "A two-part button that displays a flyout when its secondary part is clicked.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/ToggleSwitch.png"), "SwitchButton", "A switch that can be toggled between 2 states.", "basicInputInterface", 0);
    m_basicInputView->addSampleCard(QPixmap("../res/imgs/ToggleButton.png"), "ToggleButton", "A button that can be switched between two states like a CheckBox.", "basicInputInterface", 0);
    
    
    m_dateTimeView = new FluSampleCardView(m_view, "Date and time samples");
    m_dateTimeView->addSampleCard(QPixmap("../res/imgs/CalendarDatePicker.png"), "CalendarPicker", "A control that lets a user pick a date value using a calendar.", "dateTimeInterface", 0);
    m_dateTimeView->addSampleCard(QPixmap("../res/imgs/DatePicker.png"), "DatePicker", "A control that lets a user pick a date value.", "dateTimeInterface", 0);
    m_dateTimeView->addSampleCard(QPixmap("../res/imgs/TimePicker.png"), "TimePicker", "A configurable control that lets a user pick a time value.", "dateTimeInterface", 0);




    m_vLayout->addWidget(m_basicInputView);
    m_vLayout->addWidget(m_dateTimeView);
}

void FluHomeInterface::paintEvent(QPaintEvent* event)
{
    QScrollArea::paintEvent(event);
}
