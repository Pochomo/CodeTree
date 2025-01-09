#include <iostream>
#include <climits>

using namespace std;

int N, H, T;
int arr[100];

int main() {
    cin >> N >> H >> T;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    //N개의 밭의 높낮이, 높이 올릴때 , 낮출때 비용 1
    //최소 T번 이상 H높이로 나오게끔 하고자함.
    //T개를 잡고 T개에서 모두 3 만들면 됨, 만드는데 얼마나 연산 많이했는지 count
    int ans = INT_MAX;
    for(int i = 0; i <= N-T; i++){
        int cost = 0;
        int cnt = 0;
        //int cal = 0;
        for(int j = i; j < i+T; j++){
            int temp = arr[j];
            if(temp == 3){
                cnt++;
            }  
            else if(temp != 3){
                while(temp != 3){
                    if(temp > 3){
                        cost++;
                        temp--;
                    }
                    else if(temp < 3){
                        cost++;
                        temp++;
                    }
                }
                cnt++;
            }

        }
        //cout << cost;
        ans = min(ans , cost);
    }

    cout << ans;

    return 0;
}