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
    int time_t = 0;
    for(int i = 0; i < n; i ++){
        cin >> v >> t;
        for(int j = 0; j < t; j++){
            distance += v;
            arrA[index] += distance;
            index++;
            time_t++;
        }
    }
    index = 1;
    distance = 0;
    for(int i = 0; i < m; i ++){
        cin >> v >> t;
        for(int j = 0; j < t; j++){
            distance += v;
            arrB[index] += distance;
            index++; 
        }
    }

    int cnt = 0;
    bool check = true;
    bool d_check = true;
    for(int i = 1; i < time_t; i++){
        if(arrA[i] > arrB[i] && check == true){
            cnt ++;
            check = false;
            d_check = true;
        }
        else if(arrB[i] > arrA[i] && check == true){
            cnt ++;
            check = false;
            d_check = true;
        }
        else if(arrA[i] == arrB[i] && d_check == true){
            d_check = false;
            check = true;
            cnt ++;
        }

    }

    cout << cnt;
    return 0;
}