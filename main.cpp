#include <iostream>

using namespace std;
//rows and columns
int row;
int column;
//bool for now if there're winner
bool noWinner = true;

//check of a player made a move
bool timeOf = true;

//player
char player;

//board
char board[][3] = {
                        {'_','_','_'},
                        {'_','_','_'},
                        {'_','_','_'}
                    };


//void to create the board and show the board
void createBoard()
{
    //check which player'll play
    player = timeOf ? 'X' : '0';

    //loop for draw the board
    for (int i = 0; i < 3 ; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << "\t";
        }

        cout << endl;
    }
}

//bool check if are a winner
bool checkWinner ()
{
    //Check horizontal
    for (int i = 0; i < 3; ++i)
    {
        if  (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }

        //check vertical
        else if  (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    //Check diagonal left to right
    if(board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2] )
    {
        return true;
    }

    //Check diagonal right to left
    if(board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0] )
    {
        return true;
    }

    return false;
}

//check the board for now if there're a tie
bool checkDraw ()
{
    for (int i = 0; i < 3 ; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == '_')
            {
                return false;
            }
        }
    }

    return true;
}

//move of the player
char play (int row, int column)
{
    //make the move of the player (replace the character with the character of the player)
    board[row][column] = player;

    //change the player
    timeOf = !timeOf;

    //bool for now if there're a winner
    bool winner = checkWinner();
    //check if there're a tie
    bool draw = checkDraw();

    if (winner)
    {
        cout << "El ganador es el jugador: " << player << endl;
        createBoard();
        noWinner = false;
    }

    else if (draw)
    {
        cout << "El juego es un empate."<< endl;
        createBoard();
        noWinner = false;
    }
}

//check if the move of the user is valid
bool checkMove(int row, int column)
{
    if(board[row][column] == '_')
    {
        return false;
    }

    return true;
}

//void for the use made a move
void makeMove()
{
    cout << "Es el turno de " << player << endl;

    cout << "En que fila desea jugar: ";
    cin >> row;

    cout << "En que columna desea jugar: ";
    cin >> column;

    cout << endl;

    //check if the move is valid
    bool ok = checkMove(row, column);

    if (!ok)
    {
        play(row, column);
    }

    else
    {
        cout << "Debes jugar en otra posicion!, esa posicion esta ocupada!" << endl;
    }
}

int main()
{
    while(noWinner)
    {
        createBoard();
        makeMove();
    }
}



