#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Game{
private:
    char board[8][9]{};
    int exe(int column, char pCH){
        int row;
        for (row = 6; row > 0; --row) {
            if(board[row][column] == 'O'){
                break;
            }
        }
        for (int i = 0; i <= row; ++i) {
            board[i][column] = pCH;
            _sleep(150);
            system("cls");
            board[i-1][column] = 'O';
            showBoard();
        }
        return checkWin(row, column, pCH);
    }
    int play(string player, char pCH){
        int column;
        cout << '\n' << player << ", choose a column ( 1 to 7 )(" << pCH << ") : ";
        cin >> column;
        return exe(column, pCH);
    }
    int BOT(char pCH){
        int column;
        int row;
        for (column = 1; column < 8; ++column) {
            for (row = 6; row > 0; --row) {
                if(board[row][column] == 'O'){
                    break;
                }
            }
            if(checkWin(row, column, pCH) == 1){
                return exe(column, pCH);
            }else if(checkWin(row, column, 'X') == 1){
                return exe(column, pCH);
            }
        }
        srand(time(0));
        column = rand()%7 + 1;
        return exe(column, pCH);
    }
    int checkWin(int row, int column, char pCH){
        int check = 0, n = 0;
        for (int i = 0; i < 4; ++i) {
            if (board[row + i][column] == pCH){
                n++;
            }
        }
        if (n == 4){
            check = 1;
        }
        //check in vertical
        n = 0;
        for (int i = 1; i < 5; ++i) {
            if (board[row][i] == pCH && board[row][i+1] == pCH && board[row][i+2] == pCH && board[row][i+3] == pCH){
                check = 1;
            }
        }
        //check in horizontal
        if (board[row+1][column+1] == pCH && board[row+2][column+2] == pCH && board[row+3][column+3] == pCH){
            n += 3;
        }else if (board[row+1][column+1] == pCH && board[row+2][column+2] == pCH){
            n += 2;
        }else if (board[row+1][column+1] == pCH){
            n += 1;
        }
        if (board[row-1][column-1] == pCH && board[row-2][column-2] == pCH && board[row-3][column-3] == pCH){
            n += 3;
        }else if (board[row-1][column-1] == pCH && board[row-2][column-2] == pCH){
            n += 2;
        }else if (board[row-1][column-1] == pCH){
            n += 1;
        }
        n++;
        if (n > 3){
            check = 1;
        }
        n = 0;
        if (board[row+1][column-1] == pCH && board[row+2][column-2] == pCH && board[row+3][column-3] == pCH){
            n += 3;
        }else if (board[row+1][column-1] == pCH && board[row+2][column-2] == pCH){
            n += 2;
        }else if (board[row+1][column-1] == pCH){
            n += 1;
        }
        if (board[row-1][column+1] == pCH && board[row-2][column+2] == pCH && board[row-3][column+3] == pCH){
            n += 3;
        }else if (board[row-1][column+1] == pCH && board[row-2][column+2] == pCH){
            n += 2;
        }else if (board[row-1][column+1] == pCH){
            n += 1;
        }
        n++;
        if (n > 3){
            check = 1;
        }
        return check;
    }
public:
    Game(){
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = 'O';
            }
        }
        for (int i = 0; i < 6; ++i) {
            board[i][0] = '|';
            board[i][8] = '|';
        }
        for (int i = 1; i < 8; ++i) {
            board[6][i] = '_';
        }

        board[7][1] = '1';
        board[7][2] = '2';
        board[7][3] = '3';
        board[7][4] = '4';
        board[7][5] = '5';
        board[7][6] = '6';
        board[7][7] = '7';

        board[6][0] = ' ';
        board[6][8] = ' ';
        board[7][0] = ' ';
        board[7][8] = ' ';
    }
    void showBoard(){
        cout << "\n";
        for (int i = 0; i < 8; ++i) {
            cout << "   ";
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    void PvP(){
        showBoard();
        for (int i = 0; i < 42; ++i) {
            if (i%2 == 0){
                if ( play("player1", 'X') == 1 ){
                    cout << "\nplayer1 win!\n";
                    break;
                }
            }else if (i%2 == 1){
                if ( play("player2", 'Z') == 1 ){
                    cout << "\nplayer2 win!\n";
                    break;
                }
            }
        }
        cout << "\nThe End ...";
    }
    void PvB(){
        showBoard();
        for (int i = 0; i < 42; ++i) {
            if (i%2 == 0){
                if ( play("player", 'X') == 1 ){
                    cout << "\nplayer1 win!\n";
                    break;
                }
            }else if (i%2 == 1){
                if ( BOT('Z') == 1 ){
                    cout << "\nBOT win!\n";
                    break;
                }
            }
        }
        cout << "\nThe End ...";
    }
};

int main() {

    char vs;
    Game g;
    cout << "play by player or BOT? (P&B) : ";
    cin >> vs;
    system("cls");
    if( vs == 'p' || vs == 'P' ){
        g.PvP();
    }else if( vs == 'b' || vs == 'B' ){
        g.PvB();
    }



    return 0;
}
