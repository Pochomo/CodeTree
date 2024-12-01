#include <iostream>
using namespace std;

int arrA[2000000] = {0};
int arrB[2000000] = {0};

void check(int full_time) {
    int cnt = 0;
    int prevLeader = 0;  //1: A선두, 2: B선두

    if(arrA[1] > arrB[1]){ prevLeader = 1; }
    else if(arrA[1] < arrB[1]) { prevLeader = 2; }

    for(int i = 2; i <= full_time; i++) {
        int currentLeader = 0;
        
        if(arrA[i] > arrB[i]){ 
            currentLeader = 1;
        }
        else if(arrA[i] < arrB[i]){
            currentLeader = 2;
        }
        if(prevLeader != currentLeader && prevLeader != 0) {
            cnt++;
        }

        prevLeader = currentLeader;
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