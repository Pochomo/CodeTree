#include <iostream>

using namespace std;

int n;
int a[10], b[10], c[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    //서로 다른 숫자 세자리
    //A가 1에서 9까지의 서로 다른 숫자 세 개로 구성된 세 자리 수를 마음속으로 생각
    //B는 1에서 9까지의 서로 다른 숫자 세 개로 구성된 세 자리 수를 A에게 묻는다.
    //B가 말한 세 자리 수에 있는 숫자들 중 
    //하나가 A가 생각한 세 자리 숫의 동일한 자리에 위치하면 1번 카운트 증가
    //있긴한데 다른 자리번 2번 카운트 증가
    //결론 적으로 A가 생각하는 숫자를 맞추는 게임
    //a[i] = B가 생각한숫자, b[i] = 1번 카운트, c[i] = 2번 카운트
    int cnt = 0;
    //1부터 9까지 모든 경우의 수 들 중 맞는 것만 cnt ++
    //111이 조건들을 만족하냐? 만족하면 cnt++ 111(A) 랑 B[i]랑 비교해서 카운팅, 카운팅이 맞나
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i == j) continue;
            for(int k = 1; k <= 9; k++){
                if(j == k) continue;
                int correct = 0;
                int index = 0;
                while(index != n){
                    int cnt1 = 0;
                    int cnt2 = 0;
                    int num = a[index];

                    int a100 = num/100;
                    int a10 = (num/10)%10;
                    int a1 = num%10;
                    //cnt가 올라간 자리 수는 고려할 필요 없음
                    if(a100 == i) cnt1++;
                    else if(a100 == j || a100 == k) cnt2 ++;
                    if(a10 == j) cnt1++;
                    else if(a10 == i || a10 == k) cnt2 ++;
                    if(a1 == k) cnt1++;
                    else if(a1 == j || a1 == i) cnt2 ++;
                    if(cnt1 == b[index] && cnt2 == c[index]){
                        correct++; //모든 경우의 수가 다 맞아야함.
                    }
                    index++;
                }
                if(correct == n){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}