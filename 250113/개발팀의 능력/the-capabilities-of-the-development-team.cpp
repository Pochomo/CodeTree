#include <iostream>
#include <climits>

using namespace std;

int ability[5];

int main() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        cin >> ability[i];
        total += ability[i];
    }

    int ans = INT_MAX;
    int sum1, sum2, sum3;
    int maxsum = INT_MIN;
    int minsum = INT_MAX;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) { //1팀선정
            if(j == i) {continue;}
            for (int k = 0; k < 5; k++) { //나머지 한팀 선정
                for(int q = 0; q < 5; q++) {
                    if(k == j || k ==i || q == j || q == i || q == k) {continue;}
                    int sum1 = ability[i] + ability[j];
                    int sum2 = ability[k] + ability[q];
                    int sum3 = total - (sum1 + sum2);
                    
                    int maxsum = max(max(sum1, sum2), sum3);
                    int minsum = min(min(sum1, sum2), sum3);
                    if(sum1 != sum2 && sum2 != sum3 && sum1 != sum3){
                        ans = min(ans, maxsum - minsum);
                    }
                }
            }
        }
    } 

    if(ans != INT_MAX) cout << ans;
    else cout << -1;

    return 0;
}