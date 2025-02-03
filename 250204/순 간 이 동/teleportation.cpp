#include <iostream>
#include <climits>

using namespace std;

int a, b, x, y;

//최선의 가짓수를 따지는 문제는 모든 가짓수를 따지고 문제를 풀어야한다.
int main() {
    cin >> a >> b >> x >> y;

    //A->B , 한번 순간이동, x에서 y 혹은 y에서 x로 이동 가능.
    //이것을 효율적으로 이용하여 걷는 거리 최소한으로 하는 프로그램
    
    int ans = INT_MAX;
    for(int i = 0; i < 2; i++){
        int distance = 0;
        if(i == 0){
            distance += abs(a - x);
            distance += abs(y - b);
            ans = min(ans, distance);
        }
        else if(i == 1){
            distance += abs(a - y);
            distance += abs(x - b);
            ans = min(ans, distance);
        }
    }

    cout << ans;
    
    return 0;
}