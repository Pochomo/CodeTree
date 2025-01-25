#include <iostream>
#include <climits>

using namespace std;

int n;
int h[100];

int main() {
    cin >> n;

    //빙산 덩어리의 최대 개수 구하라
    //덩어리를 나누는 기준 
    //경계선 위로 안튀아 나오면 따로 봐야됨
    int maxH = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        maxH = max(h[i], maxH);
    }

    int ans = INT_MIN;
    for (int i = 1; i < maxH; i++) { //해수면 경계
        int cnt = 0; //덩어리 갯수
        bool isLoaf = false;
        for (int  j = 0; j < n; j++) {
            if(!isLoaf && i < h[j]){
                cnt++;
                isLoaf = true;
            }
            else if(isLoaf && i < h[j]){
                isLoaf = true;
            }
            else if(isLoaf && i >= h[j]){
                isLoaf = false;
            }
        }
        ans = max(cnt, ans);
    }
    
    cout << ans;

    return 0;
}