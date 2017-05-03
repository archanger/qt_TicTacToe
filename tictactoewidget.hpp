#ifndef TICTACTOEWIDGET_HPP
#define TICTACTOEWIDGET_HPP

#include <QWidget>

class QPushButton;

class TicTacToeWidget : public QWidget
{
  Q_OBJECT

public:
  enum class Player {
    Invalid, Player1, Player2, Draw
  };

public:
  TicTacToeWidget(QWidget *parent = 0);
  ~TicTacToeWidget();

  void initNewGame();

  Player currentPlayer() const;
  void setCurrentPlayer(Player currentPlayer);

public slots:
  void handleButtonClick(int index);

signals:
  void currentPlayerChanged(Player player);
  void gameOver(Player player);

private:
  void setupBoard();

private:
  QList<QPushButton*> board;
  Player _currentPlayer;
};

#endif // TICTACTOEWIDGET_HPP
