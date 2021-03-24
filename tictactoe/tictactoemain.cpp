#include "tictactoemain.h"
#include <QMessageBox>

tictactoemain::tictactoemain(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("My Tic Tac Toe Game");
    this->setFixedSize(350, 350);

    this->gameTable = new table();
    this->mainLayout = new QVBoxLayout();
    this->tableLayout = new QGridLayout();
    this->mainLayout->addLayout(tableLayout);

    this->newGameButton = new QPushButton("Play a New Game", this);
    this->mainLayout->addWidget(newGameButton);

    connect(newGameButton, SIGNAL(clicked()), this, SLOT(newGame()));

    this->newGameButton->setBaseSize(300, 80);
    this->mainLayout->addWidget(newGameButton);

    this->generateGameButtons();

    this->setLayout(mainLayout);

    connect(gameTable, SIGNAL(cellValueChanged(int, int, int)), this, SLOT(displayMove(int, int, int)));
    connect(gameTable, SIGNAL(gameWon(int)), this, SLOT(on_gameWon(int)));
    connect(gameTable, SIGNAL(gameDraw()), this, SLOT(on_gameDraw()));
}

void tictactoemain::generateGameButtons()
{
    this->tableButtons.resize(3);
    for(int x=0; x<3; x++)
    {
        this->tableButtons[x].resize(3);
        for(int y=0; y<3; y++)
        {
            this->tableButtons[x][y] = new QPushButton("", this);
            this->tableLayout->addWidget(this->tableButtons[x][y], x,y);
            this->tableButtons[x][y]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            this->tableButtons[x][y]->setFont( QFont( "lucida", 64));
            connect(this->tableButtons[x][y], SIGNAL(clicked()), this, SLOT(on_gameButtonClicked()));


        }
    }
}

void tictactoemain::newGame()
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            this->tableButtons[x][y]->setText("");
            this->tableButtons[x][y]->setEnabled(true);
        }
    }
}

void tictactoemain::on_gameButtonClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    int loc = this->tableLayout->indexOf(clickedButton);

    int x = loc/3;
    int y = loc%3;
    clickedButton->setEnabled(false);
    this->gameTable->makeMove(x, y);
}

void tictactoemain::displayMove(int x, int y, int playerSymbol)
{
    if(playerSymbol == 1)
    {
        this->tableButtons[x][y]->setText("X");
    }
    else
        this->tableButtons[x][y]->setText("O");
}

void tictactoemain::on_gameWon(int playerSymbol)
{
    QString w;
    if(playerSymbol == 1)
    {
        w = "X";
    }
    else
        w = "O";
    QMessageBox::information(this, "WINNER!! ", w + " has won the game!");
    this->gameTable->newGame();
    this->newGame();
}

void tictactoemain::on_gameDraw()
{
    QMessageBox::information(this, "DRAW", "No one wins");
    this->gameTable->newGame();
    this->newGame();
}
