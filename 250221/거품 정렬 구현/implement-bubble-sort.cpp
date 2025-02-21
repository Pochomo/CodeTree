#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

void BubbleSort() {
    bool sorted = true;

    do {
        sorted = true;
        for(int i = 0; i < n - 1; i++)
            if(arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;
            }
    } while(!sorted);
}

int main() {
    // 입력
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    BubbleSort();

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
