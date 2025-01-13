#include <iostream>
#include <climits>
using namespace std;

int ability[6];

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
    }

    //6명을 2명씩 3팀으로 배정, 능력 총합이 가장 큰 팀과 가장 작은  팀의 차이를 최소화할 때 차를 구하라
    int ans = INT_MAX;
    int sum1, sum2, sum3;
    int maxsum = INT_MIN;
    int minsum = INT_MAX;
    for (int i = 0; i < 6; i++) {
        for (int j = i+1; j < 6; j++) { //1팀선정
            if(j == i) continue;
            for (int k = 0; k < 6; k++) { //나머지 한팀 선정
                for(int q = k+1; q < 6; q++) {
                    if(k == j || k ==i || q == j || q == i) continue;
                    for(int z = 0; z < 6; z++) {
                        for(int c = z+1; c < 6; c++) {
                            if(c == j || c ==i || c == q || c == k || 
                            z == j || z == i || z == q  || z == k) continue;
                            int sum1 = ability[i] + ability[j];
                            int sum2 = ability[k] + ability[q];
                            int sum3 = ability[z] + ability[c];
                        
                            int maxsum = max(max(sum1, sum2), sum3);
                            int minsum = min(min(sum1, sum2), sum3);
                            ans = min(ans, maxsum - minsum);
                        }
                    }
                }
            } 
        }
    }

    cout << ans;

    return 0;
}