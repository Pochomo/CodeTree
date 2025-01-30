#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int heights[1000];

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    //높이가 0부터 100, X만큼 올리거나 X만큼 깎을 때 가격은 X * X
    //가장 높은 언덕, 가장 낮은 언덕 높이차 17이하 되도록하는 최소비용
    sort(heights, heights + N);

    int ans = INT_MAX;
    for (int i = 0; i <= 100; i++) { //증가수치
        int cost = 0;
        for (int j = 0; j <= 100; j++) { //감소수치
            int min_height = heights[0];
            int max_height = heights[N-1];
            int diff = abs(max_height - min_height);
            max_height -= j;
            min_height += i;
            cost = (i * i) + (j * j);
            if(abs(max_height - min_height) <= 17) ans = min(cost, ans);
        }
        
    }

    cout << ans;

    return 0;   
}