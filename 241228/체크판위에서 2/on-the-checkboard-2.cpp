#include <iostream>
#include <algorithm>
using namespace std;

char arrA[20][20] = {'0'};



int main() {
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arrA[i][j];
        }
    }

    int cnt = 0;
    int result = 0;
    char start_Point = arrA[0][0];
    char end_Point = arrA[c-1][r-1];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(arrA[i][j] == start_Point){
                continue;
            }
            for (int k = i + 1; k < r-1; k++) {
                for (int l = j + 1; l < c-1; l++){
                    
                    if (arrA[i][j] == arrA[k][l]) continue;

                    if (arrA[k][l] == end_Point) continue;
                    
                    result++;
                }
            }
        }
    }


    cout << result;

    return 0;
}