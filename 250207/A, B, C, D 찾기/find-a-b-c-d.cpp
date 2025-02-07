#include <iostream>
#include <algorithm>

using namespace std;

int arr[15];

int main() {
    for (int i = 0; i < 15; i++) {
        cin >> arr[i];
    }

    //A + B 가 최소 , A + C가 최대
    sort(arr, arr + 15);
    int A = arr[0];
    int B = arr[1];
    int C = arr[2];
    int D = arr[14] - (A + B + C);

    cout << A << " " << B << " " << C << " " << D;
    return 0;
}