#include <iostream>
using namespace std;

char arrA[15][15] = {'0'};

int main() {
    int r, c;
    cin >> r >> c;
    
    // 격자 입력
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arrA[i][j];
        }
    }
    
    int result = 0;
    char start_Point = arrA[0][0];
    char end_Point = arrA[r-1][c-1];
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i > 0 && j > 0 && arrA[i][j] != start_Point) {
                for (int k = i + 1; k < r; k++) {
                    for (int l = j + 1; l < c; l++) {
                        if (arrA[k][l] != arrA[i][j] && 
                            arrA[k][l] != end_Point && 
                            k < r-1 && l < c-1) {
                            if (arrA[k][l] != arrA[i][j] && end_Point != arrA[k][l]) {
                                result++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}