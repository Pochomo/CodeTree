#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100];
int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int min_diff = INT_MAX;
    for(int i = 0; i < n; i++) {
        arr[i] *= 2;
    
        for(int j = 0; j < n; j++) {
            int remaining_arr[n-1] = {};
            int cnt = 0;
            for(int k = 0; k < n; k++)
                if(k != j)
                    remaining_arr[cnt++] = arr[k];
    
            int sum_diff = 0;
            for(int k = 0; k < n - 2; k++)
                sum_diff += abs(remaining_arr[k + 1] - remaining_arr[k]);

            min_diff = min(min_diff, sum_diff);
        }
    
        arr[i] /= 2;
    }
    
    cout << min_diff;
    
    return 0;
}
