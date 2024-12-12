#include <iostream>
using namespace std;

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int arrA[100][100] = {0};

bool inRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    int n;

    cin >> n;

    int direction = 0;
    int x = (n/2), y = (n/2);
    int nx = x, ny = y;
    int distance = 1;
    int count = 0;
    int steps = 0;

    arrA[x][y] = 1;

    while (distance <= n*n) {
        for(int i = 0; i <= steps; i++) {
            x += dx[direction];
            y += dy[direction];
            arrA[x][y] = ++distance;
        }
        
        direction = (direction + 1) % 4;
        count++;
        
        if(count == 2) {
            steps++;
            count = 0;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arrA[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}