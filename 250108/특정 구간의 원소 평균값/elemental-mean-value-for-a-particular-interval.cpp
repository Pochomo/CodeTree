#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    float avg; 
    float num;
    for(int i = 0; i < n; i++){
        avg = 0;
        num = 0;
        for(int j = i; j <= n; j++){
            //구간 별로 평균값 구하기
            for(int k = i; k <= j; k++){
                num += arr[k];
            }
            avg = num / (abs(j - i + 1));
            for(int z = 0; z < n; z++){
                if(avg == (float)arr[z]){
                    cnt++;
                    break;
                }
            }   
        }
    }

    cout << cnt;

    return 0;
}