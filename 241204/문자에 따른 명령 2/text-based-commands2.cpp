#include <iostream>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    string direction;
    int x = 0;
    int y = 0;
    cin >> direction;
    int dir_num = 3; //북쪽
    for(int i = 0; i < (int)direction.size(); i++){
        if(direction[i] == 'L'){
            dir_num = (dir_num + 3) % 4;
        }
        else if(direction[i] == 'R'){
            dir_num = (dir_num + 1) % 4; 
        }
        else if(direction[i] == 'F'){
            x += dx[dir_num];
            y += dy[dir_num];
        }
    }
    
    cout << x << " " << y;

    return 0;
}