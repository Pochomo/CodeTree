#include <iostream>
using namespace std;

int k, n;
int arr[10][20];

int main() {
    cin >> k >> n;
    
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            bool always_higher = true;

            for (int game = 0; game < k; game++) {
                int pos_i = -1, pos_j = -1;
                for (int pos = 0; pos < n; pos++) {
                    if (arr[game][pos] == i+1) pos_i = pos;
                    if (arr[game][pos] == j+1) pos_j = pos;
                }
                if (pos_i >= pos_j) {
                    always_higher = false;
                    break;
                }
            }
            if (always_higher) count++;
        }
    }
    
    cout << count << endl;
    return 0;
}