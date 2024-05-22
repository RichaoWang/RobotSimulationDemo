#ifndef ROBOTSIMULATION_HOMEWIDGET_H
#define ROBOTSIMULATION_HOMEWIDGET_H

#include <QLabel>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include "components/FluWidget.h"
#include "components/utils/FluUtils.h"
#include "components/FluVScrollView.h"
#include "components/FluSettingsSelectBox.h"
#include "components/FluSettingsLabelBox.h"
#include "components/FluIconButton.h"

class HomeWidget : public FluWidget {
Q_OBJECT
public:
    explicit HomeWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

public slots:

    void onThemeChanged() override;

protected:
    QVBoxLayout *m_mainLayout;

    QVBoxLayout *m_midLayout;

    QLabel *m_titleLabel;
//    QLabel *m_appBehaviorLabel;
    FluVScrollView *m_vScrollView;
public:
//    FluSettingsSelectBox *appThemeSelectBox;
};

#endif //ROBOTSIMULATION_HOMEWIDGET_H