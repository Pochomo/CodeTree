#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = -1;
    int ans = -1;
    //3가지를 선택해서 carry가 발생하지 않으면서 나올 수 있는 최댓값
    int temp1, temp2, temp3;
    int check = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                temp1 = arr[i];
                temp2 = arr[j];
                temp3 = arr[k];
                while(temp1 > 0 || temp2 > 0 || temp3 > 0){
                    if((temp1 % 10 + temp2 % 10 + temp3 % 10) >= 10){
                        check = 1;
                        break;
                    }
                    else{
                        temp1 = temp1 / 10;
                        temp2 = temp2 / 10;
                        temp3 = temp3 / 10;
                    }
                }
                if(check == 1){
                    check = 0;
                    continue;
                }
                else{
                    num = arr[i] + arr[j] + arr[k];
                }
                //cout << num << " ";
                ans = max(num, ans);
                num = -1;
            }
        }
    }
    cout << ans;
    return 0;
}