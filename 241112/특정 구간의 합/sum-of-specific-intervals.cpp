#include <iostream>
using namespace std;

int * arr;
int * result;
int cnt = 0;

void calculate(int a1, int a2) {
    int sum = 0;
    for (int i = (a1 - 1); i <= (a2 - 1); i++) {
        sum += arr[i];
    }
    result[cnt] = sum;
    cnt++;
}

int main() {
    int n, m, a1, a2;
    cin >> n >> m;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    result = new int [m];
    for (int j = 0; j < m; j++) {
        cin >> a1 >> a2;
        calculate(a1, a2);
    }
    for (int z = 0; z < m; z++) {
        cout << result[z] << endl;
    }
    return 0;
}