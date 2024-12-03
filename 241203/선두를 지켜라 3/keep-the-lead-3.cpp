#include <iostream>
using namespace std;

int arrA[100000000] = {0};
int arrB[100000000] = {0};

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
    //bool check = true;
    for(int i = 0; i <= distance; i++){
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