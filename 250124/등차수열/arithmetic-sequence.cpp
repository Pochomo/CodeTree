#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int a[100];

int main() {
    cin >> n;

    //n개의 숫자 a1, a2 an 이 정의되면 자연수 k를 적절히 정의해 
    //1<= i < j <= n 이 등차수열 이루게 해라
    
    // 등차수열이란 aj - k = k - ai 이다.
    int maxN = INT_MIN;
    int minN = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxN = max(a[i], maxN);
        minN = min(a[i], minN);
    }

    //k를 맞게 설정하고 양 옆 숫자 a[i]에서 선정
    //k는 무조건 중간값
    //a[i]를 정렬하고 하나씩 골라서 그 사이에 값을 넣어서 등비인지 확인
    
    int ans = INT_MIN;
    for(int i = minN; i < maxN; i++){ //k가 될 수 있는 숫자들
        int cnt = 0;
        for(int j = 0; j < n; j++){
            for(int k = j+1; k < n; k++){        
                if(abs(a[j] - i) == abs(a[k] - i)){
                    cnt++;
                }
            } 
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}