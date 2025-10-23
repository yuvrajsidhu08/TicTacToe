#include <iostream>
#include <cstring>
using namespace std;

// Resets the board
void resetboard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Displays the board and the score
void display(const char board[3][3], int x, int o, int t) {
    cout << "\n 123\n";
    for (int i = 0; i < 3; i++) {
        cout << (char)('a'+i);
        for (int j = 0; j < 3; j++)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "X:" << x << " O:" << o << " T:" << t << "\n\n";
}
// Checks if the player has won
char winner(const char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ') return board[i][0];
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ') return board[0][i];
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ') return board[0][0];
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ') return board[0][2];
    return ' ';
}

// Checks for a tie
bool tie(const char board[3][3]) {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (board[i][j]==' ') return false;
    return true;
}

int main() {
    char board[3][3];
    char m[3];
    char player = 'X';
    int x = 0, o = 0, t = 0;
    int r1, c1;

    // Start with an empty board
    resetboard(board);
    while (true) {

      // Shows the board and the scores
      display(board, x, o, t);
        cout << player << ": ";
        cin >> m;
        if (strlen(m)!=2) continue;
        r1 = m[0]-'a'; c1 = m[1]-'1';
        if (r1<0||r1>2||c1<0||c1>2||board[r1][c1]!=' ') continue;
        board[r1][c1]=player;

	// Checks for win and handles it
        char win = winner(board);
        if (win=='X') { x++; resetboard(board); player='X'; continue; }
        if (win=='O') { o++; resetboard(board); player='X'; continue; }
        if (tie(board)) { t++; resetboard(board); player='X'; continue; }
        player = (player=='X') ? 'O' : 'X';
    }
}
