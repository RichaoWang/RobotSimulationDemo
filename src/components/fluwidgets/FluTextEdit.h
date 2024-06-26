#pragma once

#include <QTextEdit>
#include "components/fluwidgets/utils/FluUtils.h"
#include <QTextDocument>

class FluTextEdit : public QTextEdit
{
    Q_OBJECT
  public:
    FluTextEdit(QWidget* parent = nullptr) : QTextEdit(parent)
    {
        m_bAutoAdjustSize = false;

        connect(document(), &QTextDocument::contentsChanged, this, [=]() {
            if (!m_bAutoAdjustSize)
                return;

            setFixedHeight(this->document()->size().height() + 6);
        });
        FluStyleSheetUitls::setQssByFileName(":/stylesheet/light/FluTextEdit.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    bool getAutoAdjustSize()
    {
        return m_bAutoAdjustSize;
    }

    void setAutoAdjustSize(bool bAdjustSize)
    {
        m_bAutoAdjustSize = bAdjustSize;
        document()->contentsChanged();
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            FluStyleSheetUitls::setQssByFileName(":/stylesheet/light/FluTextEdit.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName(":/stylesheet/dark/FluTextEdit.qss", this);
        }
    }

  protected:
    bool m_bAutoAdjustSize;
};
