#include <iostream>
using namespace std;

int n;
int arrA[10000][10000];

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    cin >> n;

    int distance;
    char direction;
    int OFFSET = 1000;
    int x = OFFSET, y = OFFSET;
    int nx = x, ny = y;
    int cnt = 0;
    bool check = false;
    arrA[1000][1000] = 0;

    for(int i = 0; i < n; i++){
        cin >> direction >> distance;
        for(int j = 0; j < distance; j++){
            if(direction == 'N'){
                nx = x + dx[3];
                ny = y + dy[3];
            }
            else if(direction == 'S'){
                nx = x + dx[1];
                ny = y + dy[1];
            }
            else if(direction == 'W'){
                ny = y + dy[2];
                nx = x + dx[2];                
            }
            else if(direction == 'E'){
                nx = x + dx[0];
                ny = y + dy[0];
            }
            cnt++;
            x = nx;
            y = ny;
            arrA[x][y] = cnt;
            if(x == 1000 && y == 1000){
                check = true;
                cout << cnt;
            }
        }
        if(check){
            break;
        }
    }

    if(!check){
        cout << -1;
    }    

    return 0;
}