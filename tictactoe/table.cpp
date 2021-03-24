#include "table.h"

table::table(QWidget *parent) : QWidget(parent)
{

}

void table::newGame()
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            this->Player[x][y] =0;
        }
    }
    movecount = 0;
    currentPlayer = 1;
}

void table::makeMove(int x, int y)
{
    this->Player[x][y] = this->currentPlayer;
    this->movecount++;
    emit cellValueChanged(x, y, currentPlayer);
    this->currentPlayer = -this->currentPlayer;
    this->checkGameStatus();
}

void table::checkGameStatus()
{
    for(int i=0; i<3; i++)
    {
        int sum = 0;
        for(int j=0; j<3; j++)
        {
            sum += this->Player[i][j];
            if(sum == 3)
                emit gameWon(1);
            if(sum == -3)
                emit gameWon(-1);
        }
    }

    for(int j=0; j<3; j++)
    {
        int sum = 0;
        for(int i=0; i<3; i++)
        {
            sum += this->Player[i][j];
            if(sum == 3)
                emit gameWon(1);
            if(sum == -3)
                emit gameWon(-1);
        }
    }

    int sum = 0;
    for(int j=0; j<3; j++)
    {
        sum += this->Player[j][j];
        if(sum == 3)
            emit gameWon(1);
        if(sum == -3)
            emit gameWon(-1);
    }

    sum = 0;
    for(int j=0; j<3; j++)
        sum += this->Player[j][2-j];
    if(sum == 3)
        emit gameWon(1);
    if(sum == -3)
        emit gameWon(-1);

    if(movecount == 9)
    {
        emit gameDraw();
    }
}
