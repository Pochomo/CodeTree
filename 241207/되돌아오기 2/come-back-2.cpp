#include <iostream>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

//회전 시계방항
int main() {
    string order;
    cin >> order;
    int nx = 0, ny = 0;
    int x = 0, y = 0;
    int direction = 0;
    int cnt = 0;
    bool check = true;
    for(int i = 0; i < (int)order.size(); i++){
        if(order[i] == 'L'){
            direction = (direction + 3) % 4;
            cnt ++;
        }
        else if(order[i] == 'R'){
            direction = (direction + 1) % 4;
            cnt ++;
        }
        else if(order[i] == 'F'){
            nx = x + dx[direction];
            ny = y + dy[direction];
            cnt ++;
        }
        x = nx;
        y = ny;
        if(x == 0 && y == 0){
            check = false;
            cout << cnt;
        }
    }

    if(check){
        cout << -1;
    }


    return 0;
}