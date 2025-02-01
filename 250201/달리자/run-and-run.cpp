#include <iostream>
#include <climits>

using namespace std;

int n;
int A[101];
int B[101];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    //n개의 집이 1차원 직선상에 놓여있음, x = 1부터 x = n 위치까지 일렬도 놓여있음.
    //각각의 집에는 Ai명의 사람이 들어있음 //가만히 있거나 현재집보다 x 값이 큰집으로 이동함
    //최종적으로 Bi 명의사람이 남아있음
    //이동 거리의 합 중 최소를 구하는 프로그램을 구하라
    int cnt = 0;
    int total_distance = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (A[i] - B[i]);
        total_distance += abs(cnt);
    }

    cout << total_distance;

    return 0;
}