#include <iostream>

using namespace std;

int n;
char arr[26];
char alphabet[26];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    //순서대로 줄 세우기 위해서는 인접한 두 사람의 위치를 계속 바꾸는 행위만 가능
    for (int i =0; i < 26; i++) alphabet[i] = 'A' + i;

    //하나씩 맞춰나가자
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (alphabet[i] == arr[i]) continue;

        int find_index = -1; // 초기화 필수
        for (int k = 0; k < n; k++) {
            if (arr[k] == alphabet[i]) {
                find_index = k;
                break;
            }
        }
        if (find_index == -1) continue;

        int index = find_index;
        if (find_index > i) {
            while (index > i) {
                swap(arr[index], arr[index - 1]);
                index--;
                cnt++;
            }
        }
        else if (find_index < i) {
            while (index < i) {
                swap(arr[index], arr[index + 1]);
                index++;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
