#include <iostream>
#include <climits>

using namespace std;

int n, m;
int a[201] = {};
bool wall[201] = {};
int ans = INT_MAX;

int calculate() {
    int max_num = INT_MIN;
    int current_sum = 0;
    
    for (int i = 1; i < 2 * n + 1; i += 2) {
        current_sum += a[i];
        if (wall[i+1]) {
            max_num = max(max_num, current_sum);
            current_sum = 0;
        }
    }

    return max_num;
}

void setwall(int start, int count){

    if (count == m-1) {
        int result = calculate();
        ans = min(ans, result);
        return;
    }

    for (int i = start; i < 2*n; i += 2) {
        if (!wall[i]) {
            wall[i] = true;
            setwall(i + 2, count + 1);
            wall[i] = false;
        }
    }

}

int main() {
    //숫자는 홀수 인덱스에 배치, 벽은 짝수 인덱스에 배치하는 방법
    cin >> n >> m;

    //n개의 숫자가 주어지면 숫자 사이에 칸막이를 m-1개 둔다.
    //m개의 구간으로 나눔 구간 합들 중 최댓값이 최소가 되게하는 프로그램
    for (int i = 1; i < 2 * n + 1; i += 2) {
        cin >> a[i];
    }

    wall[0] = true;
    wall[2*n] = true;
    
    //m-1개 두고 모든 경우의 수 따져서 계산
    for (int i = 0; i < 2 * n; i += 2) {
        setwall(i, 0);
    }

    cout << ans;

    return 0;
}