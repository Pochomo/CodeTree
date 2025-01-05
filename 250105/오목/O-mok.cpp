#include <iostream>

using namespace std;

int board[19][19];

bool inrange(int i, int j){
    return i < 19 && j < 19;
}

int main() {
    for (int i = 0; i < 19; i++){
        for (int j = 0; j < 19; j++){
            cin >> board[i][j];
        }
    }   
    //이긴 색 첫번째 줄에 출력, 
    //연속된 5개의 바둑알 중 가운데 위치한 바둑알 번호 출력

    int win = 0; //검 win 1 흰 win 2
    int middlei = 0, middlej = 0;
    int cnt = 0;
    for (int i = 0; i < 19; i++){
        for (int j = 0; j < 19; j++){
            if(board[i][j] == 1){
                cnt = 0;
                cnt++;
                if(inrange(i, j + cnt) && board[i][j + cnt] == 1){
                    cnt++;
                    while(cnt != 5){
                        if(inrange(i, j + cnt) && board[i][j + cnt] == 1){
                            cnt++;
                        }
                        else{
                            cnt = 0;
                            break;
                        }
                    }
                    if(cnt == 5){
                        middlei = i;
                        middlej = j + 2;
                    }
                }
                else if(inrange(i + cnt, j + cnt) && board[i + cnt][j + cnt] == 1){
                    cnt++;
                    while(cnt != 5){
                        if(inrange(i + cnt, j + cnt) && board[i + cnt][j + cnt] == 1){
                            cnt++;
                        }
                        else{
                            cnt = 0;
                            break;
                        }
                    }
                    if(cnt == 5){
                        middlei = i + 2;
                        middlej = j + 2;
                    }
                }
                else{
                    cnt = 0;
                    continue;
                }
                if(cnt == 5){
                    win = 1;
                }
            }

            if(board[i][j] == 2){
                cnt = 0;
                cnt++;
                if(inrange(i, j + cnt) && board[i][j + cnt] == 2){
                    cnt++;
                    while(cnt != 5){
                        if(inrange(i, j + cnt) && board[i][j + cnt] == 2){
                            cnt++;
                        }
                        else{
                            cnt = 0;
                            break;
                        }
                    }
                    if(cnt == 5){
                        middlei = i;
                        middlej = j + 2;
                    }
                }
                else if(inrange(i + cnt, j + cnt) && board[i + cnt][j + cnt] == 2){
                    cnt++;
                    while(cnt != 5){
                        if(inrange(i + cnt, j + cnt) && board[i + cnt][j + cnt] == 2){
                            cnt++;
                        }
                        else{
                            cnt = 0;
                            break;
                        }
                    }
                    if(cnt == 5){
                        middlei = i + 2;
                        middlej = j + 2;
                    }
                }
                else{
                    cnt = 0;
                    continue;
                }
                if(cnt == 5){
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