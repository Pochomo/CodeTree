#include <iostream>
#include <climits>
using namespace std;

int N;
int x[100];
int y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++){
                double area = 0;
                area = ((x[i]*y[j] + x[j]*y[k] + x[k]*y[i]) - (x[j]*y[i] + x[k]*y[j] + x[i]*y[k]));
                area = abs(area);
                ans = max(area, ans);
            }            
        }
    }

    cout << ans;

    return 0;
}