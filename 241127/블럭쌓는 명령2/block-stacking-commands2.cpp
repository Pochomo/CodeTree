#include <iostream>
#include <algorithm>

using namespace std;

int arr[100] = {0};

int main() {
    int n, k; //n개의 배열 k개의 줄에 결쳐
    cin >> n >> k;
    int ai, bi;
    for(int i = 0; i < k; i++){
        cin >> ai >> bi;
        for(int j = ai - 1; j <= (bi - 1); j ++){
            arr[j] += 1;
        }
    }

    sort(arr, arr + n);

    cout << arr[n-1];
    
    return 0;
}