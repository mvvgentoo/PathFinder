#ifndef ASTARCELLWIDGET_H
#define ASTARCELLWIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "ui_astarcellwidget.h"

class AStarCellWidget : public QWidget
{
    Q_OBJECT

  public:
    AStarCellWidget(QWidget *parent = 0);
    void SetDistanceValue(int value);
    void SetHeurisiticValue(int value);
    void SetType(QString value);
    void SetColor(QColor color);
    void SetArrowValue(int value);

  private:

    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_5;

    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;    

    QPalette* palette_1;

    Ui::AStarCellWidget m_wgt;
};

#endif
