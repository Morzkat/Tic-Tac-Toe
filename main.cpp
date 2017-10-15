#include <iostream>

using namespace std;

int row;
int column;

bool noWinner = true;
bool timeOf = true;

char player;
char board[][3] = {
                        {'_','_','_'},
                        {'_','_','_'},
                        {'_','_','_'}
                    };

void createBoard()
{
    player = timeOf ? 'X' : '0';

    for (int i = 0; i < 3 ; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << "\t";
        }

        cout << endl;
    }
}
bool checkWinner ()
{
    //Check horizontal and vertical
    for (int i = 0; i < 3; ++i)
    {
        if  (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }

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

char play (int row, int column)
{
    board[row][column] = player;

    timeOf = !timeOf;

    bool winner = checkWinner();
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

bool checkMove(int row, int column)
{
    if(board[row][column] == '_')
    {
        return false;
    }

    return true;
}

void makeMove()
{
    cout << "Es el turno de " << player << endl;

    cout << "En que fila desea jugar: ";
    cin >> row;

    cout << "En que columna desea jugar: ";
    cin >> column;

    cout << endl;

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



