#include "tictactoewidget.hpp"
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

TicTacToeWidget::Player checkWinCondition(int row, int column);

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
  : QWidget(parent)
{
  setupBoard();
}

TicTacToeWidget::~TicTacToeWidget()
{

}

void TicTacToeWidget::initNewGame()
{
  for (int i = 0; i < board.size(); ++i) {
    board.at(i)->setText(" ");
  }
}


void TicTacToeWidget::setupBoard() {
  QGridLayout* gridLayout = new QGridLayout;
  QSignalMapper* mapper = new QSignalMapper{this};
  for (int row = 0; row < 3; ++row) {
    for (int column = 0; column < 3; ++column) {
      QPushButton* button = new QPushButton{this};
      button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      button->setText("");
      gridLayout->addWidget(button, row, column);
      board.append(button);
      mapper->setMapping(button, board.count() - 1);
      connect(button, &QPushButton::clicked, mapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
    }
  }
  connect(mapper, static_cast<void(QSignalMapper::*)(int)>(&QSignalMapper::mapped), this, &TicTacToeWidget::handleButtonClick);
  setLayout(gridLayout);
}

TicTacToeWidget::Player TicTacToeWidget::currentPlayer() const
{
  return _currentPlayer;
}

void TicTacToeWidget::setCurrentPlayer(Player currentPlayer)
{
  if (_currentPlayer == currentPlayer)
    return;
  _currentPlayer = currentPlayer;
  emit currentPlayerChanged(currentPlayer);
}

void TicTacToeWidget::handleButtonClick(int index)
{
  if (index < 0 || index > board.size()) {
    return;
  }

  QPushButton* button = board.at(index);
  if (button->text() != " ") {
    return; //Invalid Move
  }

  button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
  Player winner = checkWinCondition(index / 3, index % 3);
  if (winner == Player::Invalid) {
    setCurrentPlayer(currentPlayer() == Player::Player1 ? Player::Player2 : Player::Player1);
  } else {
    emit gameOver(winner);
  }
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition(int row, int column) {

  QString current = board.at(row * 3 + column)->text();
  int count{0};

  for(int c = 0; c < 3; ++c) {
    if(board.at(row*3+c)->text() == current)
      ++count;
  }
  if(count == 3) return currentPlayer();
  count = 0;
  // check vertical sequence
  for(int r = 0; r < 3; ++r) {
    if(board.at(r*3+column)->text() == current)
      ++count;
  }
  if(count == 3) return currentPlayer();
  // if the move was done on diagonal, check the diagonal

  count = 0;
  if(row == column) {
    for(int c = 0; c < 3; ++c) {
      if(board.at(c*3+c)->text() == current)
        ++count;
    }
    if(count == 3) return currentPlayer();
  }
  count = 0;
  if(row + column == 2) {
    for(int c = 0; c < 3; ++c) {
      if(board.at((2-c)*3+c)->text() == current)
        ++count;
    }
    if(count == 3) return currentPlayer();
  }

  for (auto button : board) {
    if(button->text() == " ") {
      return Player::Invalid;
    }
  }

  return Player::Draw;
}
