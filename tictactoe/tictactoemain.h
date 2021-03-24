#ifndef TICTACTOEMAIN_H
#define TICTACTOEMAIN_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include "table.h"

class tictactoemain : public QWidget
{
    Q_OBJECT
public:
    explicit tictactoemain (QWidget *parent = nullptr);
    QVBoxLayout* mainLayout;
    QGridLayout* tableLayout;
    QVector<QVector<QPushButton*>> tableButtons;
    QPushButton* newGameButton;
    table* gameTable;

void generateGameButtons();

public slots:
    void newGame();
    void on_gameButtonClicked();
    void displayMove(int x, int y, int playerSymbol);
    void on_gameWon(int winner);
    void on_gameDraw();
signals:


};

#endif // TICTACTOEMAIN_H
