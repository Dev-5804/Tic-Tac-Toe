#include <iostream>
#include <ctime>

using namespace std;

void DrawBoard(char *spaces)
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void PlayerMove(char *spaces, char Player)
{
    int number;
    do
    {
        cout << "Enter a number between 1-9 to place marker : ";
        cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = Player;
            break;
        }
    } while (!number > 0 || !number < 8);
}

void ComputerMove(char *spaces, char Computer)
{
    int number;
    srand(time(0));
    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = Computer;
            break;
        }
    }
}

bool CheckWinner(char *spaces, char Player, char Computer)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        if (spaces[0] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[0] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if (spaces[3] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[3] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if (spaces[6] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[6] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if (spaces[0] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[0] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if (spaces[1] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[1] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if (spaces[2] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[2] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if (spaces[0] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[0] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        if (spaces[2] == Player)
        {
            cout << "YOU WON!" << endl;
        }
        else if (spaces[2] == Computer)
        {
            cout << "YOU LOSE!" << endl;
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool CheckTie(char *spaces, char Player, char Computer)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "It's a tie!" << endl;
    return true;
}

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char Player = 'X';
    char Computer = 'O';
    bool running = true;

    DrawBoard(spaces);

    while (running)
    {
        PlayerMove(spaces, Player);
        DrawBoard(spaces);
        ComputerMove(spaces, Computer);
        DrawBoard(spaces);
        if (CheckWinner(spaces, Player, Computer))
        {
            running = false;
            break;
        }
        else if (CheckTie(spaces, Player, Computer))
        {
            running = false;
            break;
        }
        cout << "Conputer thinking....." << endl;
    }
    return 0;
}