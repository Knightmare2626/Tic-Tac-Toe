#include <iostream>
#include <vector>
#include <random>

// global variables
char winner = ' ';
const char PLAYER = 'X';
const char COMPUTER = 'O';


// checks the count of free spaces in grid(board)
int chkSpaces(std::vector <std::vector<char>> &ans)
{
    int freeSpaces = 9;
     for (int i = 0; i < ans.size();i++)
    {
        for (int j = 0; j < ans[0].size();j++)
        {
            if (ans[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

// prints the board
void dispGrid(std::vector <std::vector<char>> &ans)
{
    std::cout << "    |     |    \n";
    std::cout << ans[0][0] << "   |  " << ans[0][1] << "  |   " << ans[0][2] << std::endl;
    std::cout << "____|_____|_____\n";
    std::cout << "    |     |    \n";
    std::cout << ans[1][0] << "   |  " << ans[1][1] << "  |  " << ans[1][2] << std::endl;
    std::cout << "____|_____|_____\n";
    std::cout << "    |     |    \n";
    std::cout << ans[2][0] << "   |  " << ans[2][1] << "  |  " << ans[2][2] << std::endl;
    std::cout << "    |     |    \n";
}

// changes the values of board to spaces 
void ResetGrid(std::vector <std::vector<char>> &ans)
{
    for (int i = 0; i < ans.size();i++)
    {
        for (int j = 0; j < ans[0].size();j++)
        {
            ans[i][j] = ' ';
        }
    }
}

// player Move
void playerMove(std::vector <std::vector<char>> &ans)
{
    int x, y;
    do
    {
        std::cout << "Enter Row No. : ";
        std::cin >> x;
        x--;
        std::cout << "Enter Column No. : ";
        std::cin >> y;
        y--;

        if (ans[x][y] != ' ')
        {
            std::cout << "Currently Occupied position \n";
            continue; // continue to prevent the computer from making a move if the player's move is invalid
        }
        else 
        {
            ans[x][y] = PLAYER; 
            break; // this break statement actually stops the player from playing forever

        }
    } while (ans[x][y] != ' '); // loop will terminate when player has entered valid move
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        std::cout << " YOU WIN! \n";
    }
    else if (winner == COMPUTER)
    {
        std::cout << " Computer WON! \n";
    }
    else 
    {
        std::cout << "TIE! \n";
    }
}

void compMove(std::vector <std::vector<char>> &ans)
{
    int x, y;
    srand(time(0)); // seeding for random move
    if (chkSpaces(ans) > 0) // checks if game is over or not
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
            
        } while (ans[x][y] != ' ');
        
        ans[x][y] = COMPUTER;
    }
    else 
    {
        printWinner('T');
    }
}

const char chkWinner(std::vector <std::vector<char>> &ans)
{
    //check rows
    for (int i = 0; i < 3;i++)
    {
        if (ans[i][0] == ans[i][1] && ans[i][1] == ans[i][2])
        {
            return ans[i][0];
        }
    }

    //check columns
    for (int i = 0; i < 3;i++)
    {
        if (ans[0][i] == ans[1][i] && ans[1][i] == ans[2][i])
        {
            return ans[0][i];
        }
    }

    //check diagonals
    if (ans[0][0] == ans[1][1] && ans[1][1] == ans[2][2])
    {
        return ans[0][0];
    }
    if ( ans[0][2] == ans[1][1] && ans[1][1] == ans[2][0])
    {
        return ans[0][2];
    }

    return ' ';
}

char playGame(std::vector <std::vector<char>> ans)
{
    char response;

    winner = ' ';
    response = ' ';
    ResetGrid(ans);
    while (winner == ' ' && chkSpaces)
    {
        dispGrid(ans);

        playerMove(ans);
        compMove(ans);
        winner = chkWinner(ans);
        if (winner != ' ' || chkSpaces(ans) == 0)
        {
            break;
        }
    }

    dispGrid(ans);
    printWinner(winner);
    std::cout << "\n\tWould you like to play again? "; 
    std::cin >> response;
    response = toupper(response);

    return response;
}

int main()

{
    std::vector <std::vector<char>> ans = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    winner = ' ';
    char response;

    std::cout << "\n\n\t\t\tWelcome to TIC-TAC-TOE \n\n\n";
    std::cout << "\n-----------------------------------------------------------------------\n\n\n";
    do
    {
        response = playGame(ans);
        
    } while (response == 'Y');

    std::cout << "\n\n----------------------------------------------------------------------------\n";
    std::cout << "\n\n\t\t\tThank you for playing TIC-TAC-TOE\n\n\n";

    return 0;
}