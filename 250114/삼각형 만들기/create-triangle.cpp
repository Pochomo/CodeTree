#include <iostream>
#include <climits>
using namespace std;

int N;
long long x[100];
long long y[100];

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++){
                if((x[i] == x[j] || x[j] == x[k] || x[k] == x[i])){
                        if(y[i] == y[k] || y[j] == y[i] || y[k] == y[j]){
                        long long area = abs((x[i]*y[j] + x[j]*y[k] + x[k]*y[i]) - 
                                        (x[j]*y[i] + x[k]*y[j] + x[i]*y[k]));
                        ans = max(area, ans);
                    }
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}