#include <iostream>
#include <algorithm>

using namespace std;

int arrA[1000];
int resultP[1000] = {0};
int resultN[1000] = {0};

int main() {
    int n, num;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        arrA[i] = num;
    }

    int positive = 0;
    int negative = 0;
    int max1 = 0;
    for(int i = 0; i < n; i++){
        if((i == 0 && arrA[0] < 0) || (arrA[i] < 0) ){
            negative++;
            positive = 0;
        }
        else if((i == 0 && arrA[0] > 0) || (arrA[i] > 0)){
            positive++;
            negative = 0;
        }
        max1 = max(max1, positive);
        max1 = max(max1, negative);
    }

    cout << max1;

    return 0;
}