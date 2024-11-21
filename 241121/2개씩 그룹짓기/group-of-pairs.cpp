#include <iostream>
#include <algorithm>
using namespace std;

int *arr;

void printMax(int num){
    int sum = 0;
    sum = (arr[num-1] + arr[0]);
    for(int i = 1; i < num-1; i++){
        if(sum < (arr[num-(i+1)] + arr[i])){
            sum = (arr[num-(i+1)] + arr[i]);
        }
    }
    cout << sum;
}

int main() {
    int n;
    cin >> n;
    n *= 2;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    printMax(n);

    delete[] arr;
    return 0;
}