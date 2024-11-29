#include <iostream>
using namespace std;

int x1A[10];
int x2A[10];
int y1A[10];
int y2A[10];

int result[200][200];

int main() {
    int n;
    cin >> n;
    int OFFSET = 100;
    int x1, x2, y1, y2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x1A[i] = x1 + OFFSET;
        x2A[i] = x2 + OFFSET;        
        y1A[i] = y1 + OFFSET;
        y2A[i] = y2 + OFFSET;
        if(i % 2 == 0){
            for(int k = x1A[i]; k < x2A[i]; k++){
                for(int j = y1A[i]; j < y2A[i]; j++){
                    result[k][j] = 1;
                }
            }
        }
        if(i % 2 == 1){
            for(int k = x1A[i]; k < x2A[i]; k++){
                for(int j = y1A[i]; j < y2A[i]; j++){
                    result[k][j] = 2;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            if(result[i][j] == 2){
                cnt ++;
            }
        }
    }
    
    cout << cnt;
    return 0;
}