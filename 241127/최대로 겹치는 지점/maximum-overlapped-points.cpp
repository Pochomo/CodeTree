#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int arr[100] = {0};
int x1A[100] = {0};
int x2A[100] = {0};

int main() {
    int n; //n개의 배열 k개의 줄에 결쳐
    cin >> n;
    int x1, x2;

    for(int i = 1; i <= n; i++){
        cin >> x1 >> x2;
        x1A[i] = x1;
        x2A[i] = x2;
    }

    int maxLocation = 1;
    for(int i = 1; i <= n; i++){
        for(int j = x1A[i]; j <= x2A[i]; j++){
            if(maxLocation < x2A[i]){
                maxLocation = x2A[i];
            }
            arr[j] += 1;
        }
    }

    sort(arr, arr + maxLocation + 1, greater<int>());

    cout << arr[0];
    
    return 0;
}