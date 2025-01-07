#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, K;
int x[100];
char c[100];
int k[10000] = {0};
//N명의 사람들이 G, H의 알파벳 팻말을 들고있다.
//사진의 크기는 K, G가 찍히면 각각 1점, H가 찍히면 각각 2점

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> c[i];
    }

    //placed
    for( int i = 0; i < N; i++){
        if(c[i]=='G'){
            k[x[i]] = 1;
        }
        else if(c[i]=='H'){
            k[x[i]] = 2;
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < 10000-K; i++){
        int max_val = 0;
        for(int j = i; j <= i+K; j++){
            max_val += k[j];
        }
        ans = max(ans, max_val);
    }

    cout << ans;

    return 0;
}