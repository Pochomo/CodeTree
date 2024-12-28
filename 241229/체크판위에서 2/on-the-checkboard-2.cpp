#include <iostream>
using namespace std;

char arrA[15][15] = {'0'};

int main() {
    int r, c;
    cin >> r >> c;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arrA[i][j];
        }
    }
    
    int result = 0;
    char start_Point = arrA[0][0];
    char end_Point = arrA[r-1][c-1];
    
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if(arrA[i][j] == start_Point){
                continue;
            }
            for (int k = i + 1; k < r-1; k++) {
                for (int l = j + 1; l < c-1; l++){
                    
                    if (arrA[k][l] == arrA[i][j]) continue;

                    if (arrA[k][l] == end_Point) continue;
                    
                    result++;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}