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
//     int dis_min = INT_MAX;  // INT_MAX로 초기화 엄청 큰 숫자로 초기화 하면서 if(i==0) 쓸 필요 없어짐 필수 ! 
//     for(int i = 0; i < n; i++){
//          int distance = 0;
//         for(int j = 0; j < n; j++){
//             distance += arrA[j] * abs(j - i);
//     }
//     dis_min = min(dis_min, distance);  // min 함수 사용
// }

    cout << dis_min;

    return 0;
}