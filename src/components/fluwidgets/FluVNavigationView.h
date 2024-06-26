#pragma once

#include "components/fluwidgets/utils/FluIconUtils.h"
#include "components/fluwidgets/utils/FluLogUtils.h"
#include "components/fluwidgets/utils/FluUtils.h"
#include "components/fluwidgets/utils/FluStyleSheetUitls.h"
#include "FluDef.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QScrollArea>
#include <QStyleOption>
#include <QTransform>
#include <QVBoxLayout>
#include "FluWidget.h"
#include "FluVScrollView.h"

class FluVNavigationItem;
class FluVNavigationIconTextItem;
class FluVNavigationView : public FluWidget
{
    Q_OBJECT
  public:
    FluVNavigationView(QWidget *parent = nullptr);

    void addItemToTopLayout(QWidget *item);

    void addItemToMidLayout(QWidget *item);

    void addItemToBottomLayout(QWidget *item);

    void clearAllItemsSelectState();
    void updateAllItemsStyleSheet();

    void setLong(bool b)
    {
        m_bLong = b;
    }

    bool isLong()
    {
        return m_bLong;
    }

    std::vector<FluVNavigationItem *> getAllItems();

    FluVNavigationItem *getItemByKey(QString key);

    void paintEvent(QPaintEvent *event) override;

  public slots:
//    void onMenuItemClicked();
    void onThemeChanged()
    {
        // LOG_DEBUG << "called";
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            FluStyleSheetUitls::setQssByFileName(":/stylesheet/light/FluVNavigationView.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName(":/stylesheet/dark/FluVNavigationView.qss", this);
        }
    }

  public:
    QVBoxLayout *m_vLayout;

    QWidget *m_topWrapWidget;
    FluVScrollView *m_midVScrollView;
    QWidget *m_bottomWrapWidget;

    QVBoxLayout *m_vTopWrapLayout;
    QVBoxLayout *m_vBottomLayout;

    bool m_bLong;
};
