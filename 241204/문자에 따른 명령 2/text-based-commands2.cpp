#include <iostream>
#include <string>
using namespace std;

int dx[4] ={0};
int dy[4] ={0};


int main() {
    string direction;
    
    cin >> direction;
    int dir_num = 3; //북쪽
    for(int i = 0; i < (int)direction.size(); i++){
        if(direction[i] == 'L'){
            dir_num = (dir_num + 3) % 4;
        }
        else if(direction[i] == 'R'){
            dir_num = (dir_num + 1) % 4; 
        }
        if(direction[i] == 'F'){
            if(dir_num == 0){
                dx[dir_num]++;
            }
            else if(dir_num == 1){
                dy[dir_num]--;
            }
            else if(dir_num == 2){
                dx[dir_num]--;
            }
            else if(dir_num == 3){
                dy[dir_num]++;
            }
        }
    }
    
    cout << dx[dir_num] << " " << dy[dir_num];
    return 0;
}