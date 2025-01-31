#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, k;
int arr[100];

int calculate(int start, int end){
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] < start){
            cost += abs(start - arr[i]);
        }
        else if(arr[i] > end){
            cost += abs(end - arr[i]);
        }
        else cost += 0;
    }
    return cost;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //n개의 수가 주어졌을 때, 각각의 수에 변화를 적절하게 주어, 최종적으로 나오는 수들 중 최대 최소간의 
    //최대 최소 차가 k 이하 되게끔

    //a가 b로 바뀌는데 드는 비용 abs(a-b)
    //범위를 k로 잡고 하면 된다.
    int ans = INT_MAX;
    for (int i = 1; i <= 10000; i++) { //[1, 3] 이내로 , [2, 4] 이내로 
        ans = min(ans, calculate(i, i + k));
    }

    cout << ans;

    return 0;
}