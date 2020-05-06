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

enum class ToParentDirection
{
  North = 0,
  South,
  West,
  East,
  NorthWest,
  NorthEast,
  SouthWest,
  SouthEast,
  COUNT
};

class AStarCellWidget : public QWidget
{
  Q_OBJECT

  public:       

    AStarCellWidget(QWidget *parent = 0);
    void SetDistanceValue(int value);
    void SetHeurisiticValue(int value);
    void SetType(QString value);
    void SetColor(QColor color);
    void SetParentDirection(ToParentDirection value);

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


//    static constexpr ToParentArrows s_ToParentArrows =
//    {
//        "\u2191","\u2193", "\u2190", "\u2192",
//        "\u2196","\u2197", "\u2199", "\u2198",
//    };

    static QString GetParentDirection(ToParentDirection toParentDirection);
};

#endif
