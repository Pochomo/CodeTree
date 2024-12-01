#include <iostream>
using namespace std;

int arrA[2000000] = {0};
int arrB[2000000] = {0};

void check(int full_time){
    int cnt = 0;
    int index = 0;
    for(int i = 1; i <= full_time; i++){
        if((arrA[i] >= arrB[i] && arrA[i+1] < arrB[i+1]) ||
           (arrA[i] <= arrB[i] && arrA[i+1] > arrB[i+1])) {
            cnt++;
        }
    }  

    cout << cnt;
}

int main() {
    int n, m;
    int v, t;
    cin >> n >> m;
    int full_time = 0;
    int index = 1;
    int distance = 0;
    for(int i = 1; i <= n; i++){
        cin >> v >> t;
        for(int j = 1; j <= t; j++){
            distance += v;
            arrA[index] += distance;
            index++;
            full_time++;
        }
    }

    index = 1;
    distance = 0;
    for(int i = 1; i <= m; i++){
        cin >> v >> t;
        for(int j = 1; j <= t; j++){
            distance += v;
            arrB[index] += distance;
            index++;
        }
    }
    

    check(full_time);

    return 0;
}