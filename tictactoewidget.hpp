#ifndef TICTACTOEWIDGET_HPP
#define TICTACTOEWIDGET_HPP

#include <QWidget>

class QPushButton;

class TicTacToeWidget : public QWidget
{
  Q_OBJECT
  Q_ENUMS(Player)
  Q_PROPERTY(Player currentPlayer READ currentPlayer WRITE setCurrentPlayer NOTIFY currentPlayerChanged)

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
  Player checkWinCondition(int row, int column);

private:
  QList<QPushButton*> board;
  Player _currentPlayer;
};

#endif // TICTACTOEWIDGET_HPP
