#include <iostream>
using namespace std;

int calculate(int arr[], int m){
    int sum = 0;
    while(m != 0){
        sum += arr[m-1];
        if(m % 2 == 0){
            m /= 2;
        }
        else if(m % 2 == 1){
            m -= 1;
        }
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    cout << calculate(arr, b);
    return 0;
}