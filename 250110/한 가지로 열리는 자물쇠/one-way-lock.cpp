#include <iostream>

using namespace std;

int N;
int a, b, c;

//1부터  N까지 중복해서 뽑아 총 3자리를 만들어야 하는 자물쇠
//특이해서 한 자리라도 주어지는 조합과 거리가 2 이내라면 열림

int main() {
    cin >> N;
    cin >> a >> b >> c;
    int total = N * N * N;
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(!(i <= a + 2 && i >= a - 2) && !(j <= b + 2 && j >= b - 2) && !(k <= c + 2 && k >= c - 2)){
                    cnt++;
                }
            }
        }    
    }

    cout << total - cnt;
    return 0;
}