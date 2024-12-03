#include <iostream>
using namespace std;

int arrA[1000001] = {0};
int arrB[1000001] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    int v, t;
    int index = 1;
    int distance = 0;
    for(int i = 0; i < n; i ++){
        cin >> v >> t;
        for(int j = 0; j < t; j++){
            distance += v;
            arrA[index] += distance;
            index++;
            
        }
    }
    index = 1;
    distance = 0;
    for(int i = 0; i < n; i ++){
        cin >> v >> t;
        for(int j = 0; j < t; j++){
            distance += v;
            arrB[index] += distance;
            index++; 
        }
    }
    int cnt = 0;
    for(int i = 0; i <= 1000000; i++){
        if((arrA[i] != arrB[i] && arrA[i - 1] == arrB[i - 1])){
            if(arrA[i - 1] == arrB[i - 1] && (i-1) != 0){
                cnt = cnt + 1;
            }
            cnt ++;
        }
    }

    cout << cnt;
    return 0;
}