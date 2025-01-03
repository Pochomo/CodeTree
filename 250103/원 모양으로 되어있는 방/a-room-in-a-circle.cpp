#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int a[1003];
//모든 사람이 같은 방에서 시작함, 각 방에 정해진 인원이 들어가는데 최소의 값 구하기
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //a[i] 번째에는 i 번째 방에 몇명 들어가야하는지 있음.
    int ans = INT_MAX;
    int distance = 0;
    for(int i = 0; i < n; i++){ //1번 부터 n 번까지 누가 더 효율적인지
        int index = i;
        for(int j = 0; j < n; j++){ //j번째부터 n까지 반복후 비교
            distance += a[index % n] * j;
            index++;
        }
        ans = min(ans, distance);
        distance = 0;
    }

    cout << ans;
    

    return 0;
}