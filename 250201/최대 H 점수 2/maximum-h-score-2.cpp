#include <iostream>
#include <climits>

using namespace std;

int N, L;
int a[100];
int cal[100];
int ans = INT_MIN;

void calculate(int start, int count){
   if(count == L) {
       int num;
       for (num = 1; num <= 100; num++) {
           int cnt = 0;
           for (int j = 0; j < N; j++) {
               if(cal[j] >= num) cnt++;
           }
           if(cnt >= num) ans = max(num, ans);
       }
       return;
   }
   for(int i = start; i < N; i++){
       cal[i]++;
       calculate(i + 1, count + 1);
       cal[i]--;
   }
}

int main() {
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        cal[i] = a[i];
    }

    //N개의 숫자가 주어지고, 그 중 최대 L개의 서로 다른 원소의 값을 1씩 올려 H 점수를 최대로 만드는 프로그램

    calculate(0, 0);

    cout << ans;

    return 0;
}