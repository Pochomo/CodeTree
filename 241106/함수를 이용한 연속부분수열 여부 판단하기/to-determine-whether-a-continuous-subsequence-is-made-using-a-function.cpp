#include <iostream>
using namespace std;

bool check(int a[], int b[], int n1, int n2){
    for(int i = 0; i <= n1-n2; i++){
        if(b[0] == a[i]){
            int n = i + 1;
            for(int z = 1; z < n2; z++){
                if(b[z] != a[n]){
                    return 0;
                }
                n++;
            }
            return 1;
        }
    }
    return 0;
}


int main() {
    int n1, n2, a, b;
    cin >> n1 >> n2;
    int A[n1];
    int B[n2];
    for (int i = 0; i < n1; i ++){
        cin >> a;
        A[i] = a;
    }
    for (int i = 0; i < n2; i ++){
        cin >> b;
        B[i] = b;
    }
    if(check(A, B, n1, n2) == true){
        cout << "Yes";
    }   
    else {
        cout << "No";
    }
    return 0;
}