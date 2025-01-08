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
    int avg; 
    int num;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            //구간 별로 평균값 구하기
            num = 0;
            for(int k = i; k <= j; k++){
                num += arr[k];
            }
            if((num % (j - i + 1)) == 0){
                avg = (num / (j - i + 1));
                for(int z = i; z <= j; z++){
                    if(avg == arr[z]){
                        cnt++;
                        break;
                    }
                }
            }   
        }
    }

    cout << cnt;

    return 0;
}