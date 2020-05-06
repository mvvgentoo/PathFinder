#include "astarcellwidget.h"

struct ToParentArrows
{
    static constexpr union
    {
        const char* Directions[static_cast<int>(ToParentDirection::COUNT)];
        struct
        {
            const char* North;
            const char* South;
            const char* West;
            const char* East;
            const char* NorthWest;
            const char* NorthEast;
            const char* SouthWest;
            const char* SouthEast;
        };
    } data =
    {
        "\u2191", "\u2193", "\u2190", "\u2192",
        "\u2196", "\u2197", "\u2199", "\u2198"
    };

    static const char* GetParentDirection(ToParentDirection toParentDirection);
};

const char* ToParentArrows::GetParentDirection(ToParentDirection toParentDirection)
{
  return data.Directions[static_cast<int>(toParentDirection)];
}

AStarCellWidget::AStarCellWidget(QWidget *parent) :
  QWidget(parent)
{
  m_wgt.setupUi(this);
  this->setAutoFillBackground(true);
}

void AStarCellWidget::SetParentDirection(ToParentDirection value)
{
  m_wgt.ArrowLabel->setText(GetParentDirection(value));
  m_wgt.ArrowLabel->setStyleSheet("QLabel {color : red; }");
}

QString AStarCellWidget::GetParentDirection(ToParentDirection toParentDirection)
{
  return QString(ToParentArrows::GetParentDirection(toParentDirection));
}

void AStarCellWidget::SetDistanceValue(int value)
{
  m_wgt.label_2->setText(QString::number(value));
}

void AStarCellWidget::SetHeurisiticValue(int value)
{
  m_wgt.label_3->setText(QString::number(value));
}

void AStarCellWidget::SetType(QString value)
{
  m_wgt.label_4->setText(value);
}

void AStarCellWidget::SetColor(QColor color)
{
  auto paletteForWidget = QPalette(palette());  
  paletteForWidget.setColor(QPalette::Base, color);
  setPalette(paletteForWidget);
}




