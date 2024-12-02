#include <iostream>
#include <algorithm>
using namespace std;

int arrA[1000001];
int arrB[1000001];

void check(int full_time) {
    // 10 11에 겹치는 경우, 13일때 a는 0(이전위치가)이고 b는 3임
    int cnt = 0;
    //겹치는 지점을 따질 필요가 없음
    //  int double_check = 1; // 연속으로 겹치는 경우 차단     
    // for(int i = 1; i <= full_time; i++) {         
    //     if(arrA[i] == arrB[i] && double_check != 2){             
    //         double_check = 2;             
    //         cnt++;         
    //     }         
    //     else if(arrA[i] != arrB[i]){             
    //         double_check = 1;         
    //     }     
    // } 
    //처음에 위와같은 방법으로 생각했지만 1 1 2 3 3, 1 1 2 3 3 일때 세는 수가 다름
    //연속으로 겹치는 경우 문제가 발생     
    for(int i = 1; i <= full_time; i++) {
        if(arrA[i] == arrB[i] && arrA[i-1] != arrB[i-1]){
            cnt++;
        }
    }

    cout << cnt;
}


int main() {
    int n, m, t;
    char d;
    int full_time = 0;
    int index = 1;
    int distance = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> t >> d;
        if(d == 'L'){
            for(int j = 1; j <= t; j++){
                distance--;
                arrA[index] += distance;
                index++;
                full_time++;
            }
        }
        if(d == 'R'){
            for(int j = 1; j <= t; j++){
                distance++;
                arrA[index] += distance;
                index++;
                full_time++;
            }
        }
    }
    for(int i = full_time; i <= 1000000; i++){
        arrA[i] = arrA[full_time];
    }
    index = 1;
    distance = 0;
    int max_N = full_time;
    full_time = 0;
    for(int i = 1; i <= m; i++){
        cin >> t >> d;
        if(d == 'L'){
            for(int j = 1; j <= t; j++){
                distance--;
                arrB[index] += distance;
                index++;
                full_time++;

            }
        }
        if(d == 'R'){
            for(int j = 1; j <= t; j++){
                distance++;
                arrB[index] += distance;
                index++;
                full_time++;
            }
        }
    }

    for(int i = full_time; i <= 1000000; i++){
        arrB[i] = arrB[full_time];
    }

    max_N = max(max_N, full_time);

    check(max_N);

    return 0;
}