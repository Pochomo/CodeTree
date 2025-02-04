#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];
int b[100];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n + 1);

    //두번쨰로 작은원소 2개나 없으면 -1출력
    int cnt = 0;
    int first_element = b[1];
    int second_element = 0;
    for (int i = 1; i <= n; i++) {
        if(b[1] != b[i]){ //무조건 달라야함
            second_element = b[i];
            break;
        }
    }

    int index = 0;
    for (int i = 1; i <= n; i++) {
        if(a[i] == second_element){
            index = i;
            cnt++;
        }
    }

    if(cnt == 1) cout << index;
    else cout << -1;
    return 0;
}