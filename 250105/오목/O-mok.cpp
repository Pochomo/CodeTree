#include <iostream>
using namespace std;

int board[19][19];

bool inrange(int i, int j){
    return i < 19 && j < 19 && i > 0 && j > 0;
}

int main() {
    // 입력
    for (int i = 0; i < 19; i++){
        for (int j = 0; j < 19; j++){
            cin >> board[i][j];
        }
    }
    
    int win = 0; // 검 win 1 흰 win 2
    int middlei = 0, middlej = 0;
    int cnt = 0;
    
    for (int i = 0; i < 19; i++){
        for (int j = 0; j < 19; j++){
            // 검은 돌 체크
            if(board[i][j] == 1){
                // 가로 방향 체크
                cnt = 1;
                while(inrange(i, j + cnt) && board[i][j + cnt] == 1){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i;
                    middlej = j + 2;
                    win = 1;
                }
                
                // 세로 방향 체크
                cnt = 1;
                while(inrange(i + cnt, j) && board[i + cnt][j] == 1){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i + 2;
                    middlej = j;
                    win = 1;
                }
                
                // 대각선 방향 체크
                cnt = 1;
                while(inrange(i + cnt, j + cnt) && board[i + cnt][j + cnt] == 1){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i + 2;
                    middlej = j + 2;
                    win = 1;
                }
                
                // 반대 대각선 방향 체크
                cnt = 1;
                while(inrange(i + cnt, j - cnt) && board[i + cnt][j - cnt] == 1){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i + 2;
                    middlej = j - 2;
                    win = 1;
                }
            }
            
            // 흰 돌 체크
            if(board[i][j] == 2){
                // 가로 방향 체크
                cnt = 1;
                while(inrange(i, j + cnt) && board[i][j + cnt] == 2){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i;
                    middlej = j + 2;
                    win = 2;
                }
                
                // 세로 방향 체크
                cnt = 1;
                while(inrange(i + cnt, j) && board[i + cnt][j] == 2){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i + 2;
                    middlej = j;
                    win = 2;
                }
                
                // 대각선 방향 체크
                cnt = 1;
                while(inrange(i + cnt, j + cnt) && board[i + cnt][j + cnt] == 2){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i + 2;
                    middlej = j + 2;
                    win = 2;
                }
                
                // 반대 대각선 방향 체크
                cnt = 1;
                while(inrange(i + cnt, j - cnt) && board[i + cnt][j - cnt] == 2){
                    cnt++;
                }
                if(cnt == 5){
                    middlei = i + 2;
                    middlej = j - 2;
                    win = 2;
                }
            }
        }
    }
    
    cout << win << endl;
    if(win != 0){
        cout << middlei + 1 << " " << middlej + 1;
    }
    
    return 0;
}