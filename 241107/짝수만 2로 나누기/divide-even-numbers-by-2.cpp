#include <iostream>
using namespace std;

void divide(int arr[], int cnt){
    int *x = arr;
    for(int i = 0; i < cnt; i++){
        if(*x % 2 == 0){
            *x = *x / 2;
            x++;
        }
        else{
            x++;
        }
    }
    for(int i = 0; i < cnt; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    divide(arr, n);

    return 0;
}