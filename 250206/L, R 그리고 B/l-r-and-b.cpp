#include <iostream>

using namespace std;

char board[10][10];
int location_L_x, location_L_y, location_B_x, location_B_y;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                location_L_x = j;
                location_L_y = i;
            } else if (board[i][j] == 'B') {
                location_B_x = j;
                location_B_y = i;
            }
        }
    }

    int distance = abs(location_L_x - location_B_x) + abs(location_L_y - location_B_y) - 1;
    bool obstacle = false;

    if (location_L_y == location_B_y) {
        int min_x = min(location_L_x, location_B_x);
        int max_x = max(location_L_x, location_B_x);

        for (int x = min_x + 1; x < max_x; x++) {
            if (board[location_L_y][x] == 'R') {
                obstacle = true;
                break;
            }
        }
    }
    else if (location_L_x == location_B_x) {
        int min_y = min(location_L_y, location_B_y);
        int max_y = max(location_L_y, location_B_y);

        for (int y = min_y + 1; y < max_y; y++) {
            if (board[y][location_L_x] == 'R') {
                obstacle = true;
                break;
            }
        }
    }
    else {
        int min_x = min(location_L_x, location_B_x);
        int max_x = max(location_L_x, location_B_x);
        int min_y = min(location_L_y, location_B_y);
        int max_y = max(location_L_y, location_B_y);

        for (int x = min_x + 1; x < max_x; x++) {
            if (board[min_y][x] == 'R' || board[max_y][x] == 'R') {
                obstacle = true;
                break;
            }
        }
        for (int y = min_y + 1; y < max_y; y++) {
            if (board[y][min_x] == 'R' || board[y][max_x] == 'R') {
                obstacle = true;
                break;
            }
        }
    }

    if (obstacle) {
        distance += 2;
    }

    cout << distance << endl;

    return 0;
}
