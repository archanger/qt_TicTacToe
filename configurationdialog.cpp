#include "configurationdialog.hpp"
#include "ui_configurationdialog.h"

#include <QPushButton>

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ConfigurationDialog)
{
  ui->setupUi(this);
  updateOkButtonState();
}

ConfigurationDialog::~ConfigurationDialog()
{
  delete ui;
}

QString ConfigurationDialog::player1Name() const
{
  return ui->player1Name->text();
}

void ConfigurationDialog::setPlayer1Name(const QString& name)
{
  ui->player1Name->setText(name);
}

QString ConfigurationDialog::player2Name() const
{
  return ui->player2Name->text();
}

void ConfigurationDialog::setPlayer2Name(const QString& name)
{
  ui->player2Name->setText(name);
}

void ConfigurationDialog::updateOkButtonState()
{
  bool pl1NameEmpty = ui->player1Name->text().isEmpty();
  bool pl2NameEmpty = ui->player2Name->text().isEmpty();

  ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(pl1NameEmpty || pl2NameEmpty);
}
