#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

#define MAX_N 10

using namespace std;

int n = 10;

string board[MAX_N];

int main() {
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    int l_x = 0, l_y = 0, r_x = 0, r_y = 0, b_x = 0, b_y = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'L') {
                l_x = i; l_y = j;
            }
            if(board[i][j] == 'R') {
                r_x = i; r_y = j;
            }
            if(board[i][j] == 'B') {
                b_x = i; b_y = j;
            }
        }
    

    if(l_x != b_x && l_y != b_y) {
        cout << abs(l_x - b_x) + abs(l_y - b_y) - 1;
    }

    else if(l_y == b_y) {
        if(l_y == r_y && r_x >= min(b_x, l_x) && r_x <= max(b_x, l_x))
            cout << abs(l_x - b_x) + abs(l_y - b_y) + 1;
        else
            cout << abs(l_x - b_x) + abs(l_y - b_y) - 1;
    }

    else if(l_x == b_x) {
        if(l_x == r_x && r_y >= min(b_y, l_y) && r_y <= max(b_y, l_y))
            cout << abs(l_x - b_x) + abs(l_y - b_y) + 1;
        else
            cout << abs(l_x - b_x) + abs(l_y - b_y) - 1;
    }

    return 0;
}
