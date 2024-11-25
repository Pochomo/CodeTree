#include <iostream>
using namespace std;

void calTime(int a, int b, int c, int d){
    int fin_time = 0;
    while(true){
        if(a == c && b == d){
            break;
        }
        b++;
        fin_time++;

        if(b == 60){
            a++;
            b = 0;
        }
    }
    cout << fin_time;
}

int main() {
    int a, b;
    int c, d;

    cin >> a >> b >> c >> d;
    
    calTime(a, b, c, d);


    return 0;
}