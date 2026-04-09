#include <iostream>
using namespace std;

int main()
{
    char board[3][3];   // array changed
	int menu;
    do {
        // menu
        cout << "\n===== TIC TAC TOE MENU =====\n";
        cout << "1. Play Game\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> menu;

        if (menu == 1)
        {
            // nested loops
            char ch = '1';
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    board[i][j] = ch++;
                }
            }

            int choice;
            char player = 'X';
            int moves = 0;
            bool win = false;

            cout << "\n===== TIC TAC TOE GAME =====\n";
            cout << "Player 1 = X\nPlayer 2 = O\n";

            while (win == false && moves < 9)
            {
            
                cout << "\nGame State: RUNNING\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << " ";
                    for (int j = 0; j < 3; j++)
                    {
                        cout << board[i][j];
                        if (j < 2) cout << " | ";
                    }
                    cout << endl;
                    if (i < 2) cout << "---|---|---\n";
                }
                cout << endl;

                cout << "Player " << player << ", enter box number: ";
                cin >> choice;

                int row = (choice - 1) / 3;
                int col = (choice - 1) % 3;

                
                if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
                {
                    cout << "Invalid move! Try again.\n";
                    continue;
                }

                board[row][col] = player;
                moves++;

                for (int i = 0; i < 3; i++)
                {
                    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                        (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                    {
                        win = true;
                    }
                }

                if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                    (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
                {
                    win = true;
                }

                if (!win)
                    player = (player == 'X') ? 'O' : 'X';
            }
            // board 
            cout << "\n===== FINAL BOARD =====\n";
            for (int i = 0; i < 3; i++)
            {
                cout << " ";
                for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j];
                    if (j < 2) cout << " | ";
                }
                cout << endl;
                if (i < 2) cout << "---|---|---\n";
            }

            if (win)
                cout << "\n Game State: WIN\nPlayer " << player << " wins! <3\n";
            else
                cout << "\n Game State: DRAW\nNo one wins. :(\n";
        }

    } while (menu != 2);

    cout << "Exiting game...\n";
    return 0;
}
