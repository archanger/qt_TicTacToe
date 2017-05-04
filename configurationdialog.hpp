#ifndef CONFIGURATIONDIALOG_HPP
#define CONFIGURATIONDIALOG_HPP

#include <QDialog>

namespace Ui {
  class ConfigurationDialog;
}

class ConfigurationDialog : public QDialog
{
  Q_OBJECT
  Q_PROPERTY(QString player1Name READ player1Name WRITE setPlayer1Name)
  Q_PROPERTY(QString player2Name READ player2Name WRITE setPlayer2Name)

public:
  explicit ConfigurationDialog(QWidget *parent = nullptr);
  ~ConfigurationDialog();

  QString player1Name() const;
  void setPlayer1Name(const QString& name);
  QString player2Name() const;
  void setPlayer2Name(const QString& name);

public slots:
  void updateOkButtonState();

private:
  Ui::ConfigurationDialog *ui;
};

#endif // CONFIGURATIONDIALOG_HPP
