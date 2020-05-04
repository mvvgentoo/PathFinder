#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

namespace Ui {
  class MainWindow;
}

class AStarCellWidget;

struct CurrentCellWidget
{
    AStarCellWidget* wgt;
    int row, col;
};

enum class CellType : char
{
  Ground = 0,
  Wall,
  Count
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private:
    Ui::MainWindow *ui;
    std::vector<bool> m_Mask;

    const static QColor s_GroundColor; // = QColor(0,200,0);
    const static QColor s_WallColor; // = QColor(0,0,200);

    constexpr static auto cellSize = 90;
    constexpr static auto rows = 5;
    constexpr static auto cols = 5;

  private slots:
    void cellClickedHandler(int row, int col);
    void slotCustomMenuRequested(const QPoint &position);
    void slotSetGround();
    void slotSetWall();

    AStarCellWidget *GetCellWidget(int r, int c) const;
    CurrentCellWidget GetCurrentCellWidget() const;
};

#endif // MAINWINDOW_H
