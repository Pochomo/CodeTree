#include <iostream>
#include <algorithm>

using namespace std;

int arr[7];

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    //A + B 가 최소 , A + C가 최대
    sort(arr, arr + 7);
    int A = arr[0];
    int B = arr[1];
    int C = arr[6] - (A + B);

    cout << A << " " << B << " " << C;

    return 0;
}