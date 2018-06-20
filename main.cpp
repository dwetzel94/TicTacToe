#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

char matrix[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
char playerChar = 'X';
int playerNumber = 1;

void DrawBoard()
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

void togglePlayerNumber()
{
    if(playerNumber == 1)
            playerNumber = 2;
    else
            playerNumber = 1;
}

void togglePlayerChar()
{
    if(playerChar == 'X')
        playerChar = 'O';
    else
        playerChar = 'X';
}

void Input()
{
    int input;
    cout << "Player " << playerNumber << " (" << playerChar << ") - type the number of the spot you want to insert your " << playerChar << ":";
    cin >> input;
    switch(input)
    {
    case 1:
        matrix[0][0] = playerChar;
        break;
    case 2:
        matrix[0][1] = playerChar;
        break;
    case 3:
        matrix[0][2] = playerChar;
        break;
    case 4:
        matrix[1][0] = playerChar;
        break;
    case 5:
        matrix[1][1] = playerChar;
        break;
    case 6:
        matrix[1][2] = playerChar;
        break;
    case 7:
        matrix[2][0] = playerChar;
        break;
    case 8:
        matrix[2][1] = playerChar;
        break;
    case 9:
        matrix[2][2] = playerChar;
        break;
    default:
        cout << "please choose a valid location";
    }
}

char Win()
{
    if(matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
        return 'X';
    
    if(matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if(matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
        return 'O';
    
    return '/';
}



int main()
{
    RenderWindow window(VideoMode(800, 800), "My First Tic Tac Toe Game, in SFML", Style::Close | Style::Titlebar | Style::Resize);
   
    DrawBoard();
    while(1)
    {
        Input();
        DrawBoard();
        
        if(Win() == 'X')
        {
            cout << "X wins" << endl;
            break;
        }
        else if(Win() == 'O')
        {
            cout << "O wins" << endl;
            break;
        }
        togglePlayerNumber();
        togglePlayerChar();
    }

    system("pause");
    return 0;


}
