#include "CFloatInput.h"

CFloatInput::CFloatInput(const QString& labelText,
                         const QString& buttonText,
                         const double& min,
                         const double& max,
                         const double& step,
                         EEvent event,
                         const double& initValue) : mLabelPtr{new QLabel{labelText}},
                                                    mSpinBoxPtr{new QDoubleSpinBox},
                                                    mButtonPtr{new QPushButton{buttonText}}
{
    this->configureFrame();
    this->configureSpinBox(min, max, step, initValue);
    this->configureLayout();

    QObject::connect(mButtonPtr, &QPushButton::clicked,
                     this, [this, event]()
                    {
                        CMessage msg{event};
                        msg.setData<float>(static_cast<float>(mSpinBoxPtr->value()));
                        emit transmitMessageSignal(msg);
                    });
}
void CFloatInput::configureLayout()
{
    auto vLayout = new QVBoxLayout;
    auto layout = new QHBoxLayout;
    layout->addWidget(mLabelPtr);
    layout->addWidget(mSpinBoxPtr);
    vLayout->addLayout(layout);
    vLayout->addWidget(mButtonPtr);
    this->setLayout(vLayout);
}
void CFloatInput::configureFrame()
{
    this->setFrameStyle(QFrame::Box);
    QPalette palette;
    palette.setColor(QPalette::Foreground, Qt::black);
    this->setPalette(palette);
}
void CFloatInput::configureSpinBox(const double& min,
                                   const double& max,
                                   const double& step,
                                   const double& initValue)
{
    mSpinBoxPtr->setMinimum(min);
    mSpinBoxPtr->setMaximum(max);
    mSpinBoxPtr->setSingleStep(step);
    mSpinBoxPtr->setDecimals(4);
    mSpinBoxPtr->setValue(initValue);
}
