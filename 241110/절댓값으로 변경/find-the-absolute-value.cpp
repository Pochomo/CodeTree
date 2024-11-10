#include <iostream>
using namespace std;

void change(int a[], int num){
    for(int i = 0; i < num; i++){
        if(a[i] < 0){
            a[i] = (-a[i]);
        }
    }
}

int main() {
    int num;
    cin >> num;
    int a[num];
    for(int i = 0; i < num; i++){
        cin >> a[i];
    }
    change(a, num);

    for(int i = 0; i < num; i++){
        cout << a[i] << " ";
    }

    return 0;
}