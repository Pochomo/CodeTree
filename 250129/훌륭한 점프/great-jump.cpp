#include <iostream>
#include <climits>
using namespace std;

int n, k;
int arr[100];

int main() {
    //돌들이 1번부터 n번까지 순서대로 놓여져있음
    //1번에서 시작해서 거리 k이내로 점프하는 것을반복하여 n번에 도달할라할때 거쳐간 지점에 적혀있던 숫자들 중 최댓값이
    //최소가 되도록하는 프로그램
    //1번부터 시작해서 k 번 반복 후 가장 최고의 방법을 실행함
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max_num = arr[0];
    int ans = arr[0];     
    int curr_pos = 0;    
    
    while (curr_pos < n-1) {
        int next_pos = curr_pos;
        int min_max = INT_MAX;
        
        for (int j = 1; j <= k && curr_pos + j < n; j++) {
            int temp_max = max(max_num, arr[curr_pos + j]);
            if (temp_max < min_max) {
                min_max = temp_max;
                next_pos = curr_pos + j;
            }
        }
        
        curr_pos = next_pos;
        max_num = min_max;
        ans = min_max;
    }
    
    cout << ans;
    return 0;
}