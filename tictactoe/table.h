#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QWidget>

class table: public QWidget
{
    Q_OBJECT

    int Player[3][3];
    int movecount= 0 ;
    int currentPlayer = 1;
public:
    explicit table(QWidget *parent = nullptr);
    void newGame();
    void makeMove(int x, int y);
    void checkGameStatus();
signals:
    void gameDraw();
    void gameWon(int winner);
    void cellValueChanged(int x, int y, int playerSymbol);
};

#endif // TABLE_H
