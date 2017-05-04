#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "tictactoewidget.hpp"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void startNewGame();

private slots:
  void updateNameLabels();
  void haandleGameOver(TicTacToeWidget::Player winner);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
