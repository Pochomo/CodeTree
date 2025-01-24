#include <iostream>
#include <climits>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];

int main() {
    cin >> N >> C >> G >> H;

    //데이터센터의 온도범위가 A가 선호하는 온도 Ta보다 낮으면 C만큼 일
    //Ta이상 Tb이하에 있다면 G만큼의 작업량
    //Tb보다 높으면 H만큼 작업량
    int minTa = 0;
    int maxTb = 0;
    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
        minTa = min(minTa, Ta[i]);
        maxTb = max(maxTb, Tb[i]);
    }
   
    //최소 ta 부터 최대 tb까지 비교
    int ans = INT_MIN;
    for (int j = minTa - 1; j <= maxTb + 1; j++) {
        int work = 0;
        for (int i = 0; i < N; i++) {
            if(j < Ta[i]){
                work += C;
            }
            else if(j >= Ta[i] && j <= Tb[i]){
                work += G;
            }
            else if(j > Tb[i]){
                work += H;
            }
        }
        ans = max(work, ans);
    }
    
    cout << ans;



    return 0;
}