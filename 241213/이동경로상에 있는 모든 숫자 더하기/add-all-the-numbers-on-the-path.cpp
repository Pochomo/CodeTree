#include <iostream>
#include <string>
using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int arrA[100][100] = {0};

bool inRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    int n, t;
    string move;                                                                                                                                      
    cin >> n >> t;
    cin >> move;
    int direction = 0;
    int x = (n/2), y = (n/2);
    int nx = x, ny = y;
    int distance = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arrA[i][j];
        }
    }

    int sum = 0;
    sum += arrA[x][y];
    for(int i = 0; i < t; i++){
        if(move[i] == 'F'){
            nx = x + dx[direction]; 
            ny = y + dy[direction];
            if(inRange(nx, ny, n)){
                x = nx;
                y = ny;
                sum += arrA[x][y];
            }
        }
        else if(move[i] == 'R'){
            direction = (direction + 1) % 4;
        }
        else if(move[i] == 'L'){
            direction = (direction + 3) % 4;
        }
    }

    cout << sum;

    return 0;
}