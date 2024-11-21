#include <iostream>
#include <algorithm>
using namespace std;

int *arr;
int *result;
int n;

int main() {

    cin >> n;
    arr = new int[n];
    result = new int[n];
    int x = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i % 2 == 0){
            sort(arr, arr + i + 1);
            result[x] = arr[i/2];
            x++;
        }
    }

    for(int i = 0; i < n/2+1; i++){
        cout << result[i] << " ";
    }

    
    delete[] arr;
    delete[] result;
    return 0;
}