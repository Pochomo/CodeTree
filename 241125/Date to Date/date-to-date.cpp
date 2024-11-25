#include <iostream>
using namespace std;

int main() {
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int time = 0;

    while(true){
        if(m1 == m2 && d1 == d2){
            time++;
            break;
        }
        time++;
        d1++;
        if(d1 > num_of_days[m1]){
            m1++;
            d1 = 1; 
        }
    }
    cout << time;

    return 0;   
}