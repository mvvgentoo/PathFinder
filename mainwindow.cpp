#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "astarcellwidget.h"
#include <qcombobox.h>

const QColor MainWindow::s_GroundColor = QColor(0,200,0);
const QColor MainWindow::s_WallColor = QColor(0,0,200);

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_Mask.resize(rows*cols, 0);

  setStyleSheet("QTableWidget {background-color: transparent; border: 5x solid qt::black};} ");
  ui->tableWidget->setColumnCount(cols);
  ui->tableWidget->setAutoFillBackground(false);
  ui->tableWidget->setShowGrid(true);
  ui->tableWidget->resize(rows*cellSize, cols * cellSize);
  ui->tableWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
  ui->tableWidget->setStyleSheet("QTableWidget::item{ background-color: rgb(255,255,0)}");

  for(int i = 0; i < cols; i++)
  {
    ui->tableWidget->setColumnWidth(i,cellSize);
  }

  for(int i = 0; i < rows; i++)
  {
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setRowHeight(i, cellSize);
    for(int j = 0; j < cols; j++)
    {
      AStarCellWidget* a = new AStarCellWidget(parent);

      a->SetDistanceValue(i*100);
      a->SetHeurisiticValue(j*100);
      a->SetColor(QColor(i * 50 % 255, ((i+j) * 55) % 255, ((i * j) * 30) % 255 ));
      a->resize(cellSize, cellSize);

      a->SetParentDirection(static_cast<ToParentDirection>(std::rand()%static_cast<int>(ToParentDirection::COUNT)));

      a->setAutoFillBackground(true);
      ui->tableWidget->setCellWidget(i, j, a);
    }
  }

  connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(cellClickedHandler(int, int)));
  connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::slotCustomMenuRequested);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::cellClickedHandler(int row, int col)
{
  bool mask = m_Mask[row * cols + col];
  mask ? slotSetGround() : slotSetWall();
}

void MainWindow::slotCustomMenuRequested(const QPoint& position)
{
  QMenu * menu = new QMenu(this);
  QAction * groundCell = new QAction(tr("Ground"), this);
  QAction * wallCell = new QAction(tr("Wall"), this);

  menu->addAction(groundCell);
  menu->addAction(wallCell);

  connect(groundCell, SIGNAL(triggered()), this, SLOT(slotSetGround()));
  connect(wallCell, SIGNAL(triggered()), this, SLOT(slotSetWall()));

  menu->popup(ui->tableWidget->viewport()->mapToGlobal(position));
}

void MainWindow::slotSetGround()
{
  if( auto cellWidget = GetCurrentCellWidget(); cellWidget.wgt != nullptr )
  {
    cellWidget.wgt->SetColor(s_GroundColor);
    cellWidget.wgt->SetType("G");
    m_Mask[cellWidget.row * cols + cellWidget.col] = 0;
  }
}

void MainWindow::slotSetWall()
{
  if( auto cellWidget = GetCurrentCellWidget(); cellWidget.wgt != nullptr )
  {
    cellWidget.wgt->SetColor(s_WallColor);
    cellWidget.wgt->SetType("W");
    m_Mask[cellWidget.row * cols + cellWidget.col] = 1;
  }
}

AStarCellWidget *MainWindow::GetCellWidget(int r, int c) const
{
  return dynamic_cast<AStarCellWidget*>(ui->tableWidget->cellWidget(r,c));
}

CurrentCellWidget MainWindow::GetCurrentCellWidget() const
{
  auto index = ui->tableWidget->selectionModel()->currentIndex();
  return CurrentCellWidget{GetCellWidget(index.row(),index.column()),index.row(),index.column() };
}
