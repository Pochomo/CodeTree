#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];
int b[100];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) { // 인덱스 0부터 사용
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n); 

    int first_element = b[0];
    int second_element = -1;

    for (int i = 1; i < n; i++) { 
        if (b[i] != first_element) { 
            second_element = b[i];
            break;
        }
    }

    if (second_element == -1) {
        cout << -1;
        return 0;
    }

    int index = -1;
    int cnt = 0;

    // 원래 배열에서 두 번째 최소값의 위치 찾기
    for (int i = 0; i < n; i++) {
        if (a[i] == second_element) {
            index = i + 1; // 문제에서 1-based index 요구
            cnt++;
        }
    }

    // 두 번째 최소값이 정확히 1개일 경우 index 출력, 그렇지 않으면 -1 출력
    if (cnt == 1) cout << index;
    else cout << -1;

    return 0;
}
