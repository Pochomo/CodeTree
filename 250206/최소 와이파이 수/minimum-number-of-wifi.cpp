#include <iostream>

using namespace std;

int n, m;
int arr[100];
bool wifi[100];
//모든 범위내에 1이고 wifi가 true여야함
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        wifi[i] = false;
    }

    //0, 1로만 이뤄진 n개의 숫자가 주어짐, x = 1인 위치부터 x = n인 위치까지 각 정수 지점 위치
    //에 사람들이 살고 있는지에 대한 여부를 나타냄. 1이면 사람 살고 O
    //와이파이는 거리 m 이내에 있는 사람이 사용 가능 어디든 설치 됨

    //최소 와이파이 수
    //m을 최대로 채우면서 설치하면 됨
    //m이 1 이면 1 3 5, 2면 2 6 10 3이면 3 8 //m*2 만큼 더해가면서 설치 흩어질때 최소 보장 안함

    int cnt = 0;
    int i = 0;
    while(i < n) {
        if(arr[i] == 0) {
            i++;
            continue;
        }

        int loc = i;
        while(loc < n && loc <= i + m) {
            loc++;
        }
        
        cnt++;

        int coverRight = (loc - 1) + m;

        i = coverRight + 1;
    }
    
    cout << cnt;
    return 0;
}
