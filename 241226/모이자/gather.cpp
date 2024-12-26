#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int arrA[100];

int main() {
    int n, a;
    cin >> n;
    int dis_min = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        arrA[i] = a;
    }
    int distance = dis_min;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            distance += arrA[j] * abs(j - i);
        }
        if(i == 0){
                dis_min = distance;
        }
        if(distance < dis_min){
            dis_min = distance;
        }
        distance = 0;
    }

    cout << dis_min;

    return 0;
}