#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int arrA[100][100] = {0};

bool inRange(int x, int y, int n, int m) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    int n, m;

    cin >> n >> m;

    int direction = 0;
    int x = 0, y = 0;
    int nx = 0, ny = 0;
    int distance = 1;
    for(int i = 0; i < n * m; i++){
            arrA[x][y] = distance++;

            nx = x + dx[direction]; 
            ny = y + dy[direction];

            if((!inRange(nx, ny, n, m)) || arrA[nx][ny] != 0){
                direction = (direction + 1) % 4;
                x = x + dx[direction]; 
                y = y + dy[direction];
                continue;
            }

            x = nx;
            y = ny;

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arrA[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}