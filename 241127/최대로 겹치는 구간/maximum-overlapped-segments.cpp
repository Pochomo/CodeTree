#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int arr[200] = {0};
int x1A[100] = {0};
int x2A[100] = {0};

int main() {
    int n; //n개의 줄에 걸쳐 (x1, x2) 공백 두고 출력
    int x1, x2;
    int min = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x1 >> x2;
        if(min > x1){
            min = x1;
        }
        x1A[i] = x1;
        x2A[i] = x2;
    }

    for(int i = 1; i <= n; i++){
        x1A[i] -= min; //OFFSET
        x2A[i] -= min;
    }
    
    int maxLocation = 1;
    for(int i = 1; i <= n; i++){
        for(int j = x1A[i]; j < x2A[i]; j++){
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