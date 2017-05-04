#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "configurationdialog.hpp"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->actionNewGame, &QAction::triggered, this, &MainWindow::startNewGame);
  connect(ui->actionQuit, &QAction::triggered, qApp, &QApplication::quit);
  connect(ui->gameBoard, &TicTacToeWidget::currentPlayerChanged, this, &MainWindow::updateNameLabels);
  connect(ui->gameBoard, &TicTacToeWidget::gameOver, this, &MainWindow::haandleGameOver);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::startNewGame()
{
  ConfigurationDialog dialog{this};
  if (dialog.exec() == QDialog::Rejected) {
    return;
  }

  ui->player1->setText(dialog.player1Name());
  ui->player2->setText(dialog.player2Name());
  ui->gameBoard->initNewGame();
  ui->gameBoard->setEnabled(true);

  updateNameLabels();
}

void MainWindow::updateNameLabels()
{
  QFont f = ui->player1->font();
  f.setBold(ui->gameBoard->currentPlayer() == TicTacToeWidget::Player::Player1);
  ui->player1->setFont(f);
  f.setBold(ui->gameBoard->currentPlayer() == TicTacToeWidget::Player::Player2);
  ui->player2->setFont(f);
}

void MainWindow::haandleGameOver(TicTacToeWidget::Player winner)
{
  ui->gameBoard->setEnabled(false);
  QString message;
  if (winner == TicTacToeWidget::Player::Draw) {
    message = "Ничья";
  } else {
    message = QString("%1 wins").arg(winner == TicTacToeWidget::Player::Player1 ?
                                       ui->player1->text() : ui->player2->text()
                                       );
  }

  QMessageBox::information(this, "Info", message);
}
