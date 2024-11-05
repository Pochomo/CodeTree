#include <iostream>
using namespace std;

bool check(int a[], int b[], int n1, int n2){
    int j = 0;
    for(int i = 0; i < n1; i++){
        if(b[j] == a[i]){
            i++;
            for(int z = j; z < n2; z++){
                if(b[z] == a[i]){
                    i++;
                }
                else{
                    return 0;
                }
            }
            return 1;
        }
        else{
            j++;
        }
    }
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
    for (int i = 0; i < n1; i ++){
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