#include <iostream>
using namespace std;

int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
int arrA[50][50] = {0};
int n;

bool inRange(int x, int y) {
    return (0 < x && x <= n && 0 < y && y <= n);
}

int getdir(char a){
    if(a == 'R')
        return 0;
    else if(a == 'D')
        return 1;
    else if(a == 'U')
        return 2;
    else
        return 3;
}

int main() {
    int t;
    cin >> n >> t;
    int x, y;
    char d;
    cin >> x >> y >> d;
    int nx = x, ny = y;
    int dir = getdir(d);

    for(int k = 0; k < t; k++){
        nx = x + dx[dir], ny = y + dy[dir];
        if(!inRange(nx, ny)){
            dir = 3 - dir;
            continue;
        }
        x = nx;
        y = ny;
    }

    cout << x << " " << y;
    return 0;
}