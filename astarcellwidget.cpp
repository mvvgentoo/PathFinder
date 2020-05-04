#include "astarcellwidget.h"

AStarCellWidget::AStarCellWidget(QWidget *parent) :
  QWidget(parent)
{
  QWidget* Form = this;
#if 0
  Form->resize(358, 222);
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
  Form->setSizePolicy(sizePolicy);
  horizontalLayout = new QHBoxLayout(Form);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  gridLayout = new QGridLayout();
  gridLayout->setObjectName(QStringLiteral("gridLayout"));
  label_3 = new QLabel(Form);
  label_3->setObjectName(QStringLiteral("label_3"));
  QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
  sizePolicy1.setHorizontalStretch(0);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
  label_3->setSizePolicy(sizePolicy1);

  gridLayout->addWidget(label_3, 2, 0, 1, 1);

  verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

  gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

  verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

  gridLayout->addItem(verticalSpacer_5, 1, 2, 1, 1);

  label = new QLabel(Form);
  label->setObjectName(QStringLiteral("label"));
  label->setAutoFillBackground(false);
  label->setMargin(0);
  label->setIndent(-100);

  gridLayout->addWidget(label, 0, 0, 1, 1);

  label_4 = new QLabel(Form);
  label_4->setObjectName(QStringLiteral("label_4"));
  sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
  label_4->setSizePolicy(sizePolicy1);
  label_4->setMinimumSize(QSize(10, 10));
  label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

  gridLayout->addWidget(label_4, 2, 2, 1, 1);

  label_2 = new QLabel(Form);
  label_2->setObjectName(QStringLiteral("label_2"));
  sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
  label_2->setSizePolicy(sizePolicy1);
  label_2->setMinimumSize(QSize(10, 10));
  label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
  label_2->setIndent(-1);

  gridLayout->addWidget(label_2, 0, 2, 1, 1);

  horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  gridLayout->addItem(horizontalSpacer_5, 2, 1, 1, 1);

  horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


  horizontalLayout->addLayout(gridLayout);

  label->setText(QApplication::translate("Form", "F", nullptr));
  label_2->setText(QApplication::translate("Form", "G", nullptr));
  label_3->setText(QApplication::translate("Form", "H", nullptr));
  label_4->setText(QApplication::translate("Form", "O", nullptr));

#endif

  m_wgt.setupUi(Form);
  palette_1 = new QPalette(palette());

  // устанавливаем цвет фона
  palette_1->setColor(QPalette::Background, Qt::yellow);
  Form->setAutoFillBackground(true);
  Form->setPalette(*palette_1);
}

void AStarCellWidget::SetArrowValue(int value)
{
  m_wgt.ArrowLabel->setText(QString("\u2196"));
  m_wgt.ArrowLabel->setStyleSheet("QLabel {color : red; }");
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
  // устанавливаем цвет фона
  paletteForWidget.setColor(QPalette::Base, color);
  setPalette(paletteForWidget);
}

