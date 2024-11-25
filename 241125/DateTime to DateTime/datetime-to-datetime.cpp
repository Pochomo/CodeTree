#include <iostream>
using namespace std;

void calTime(int a, int b, int c){
    int fin_minute = 0;
    int day, hour, minute;
    day = 11;
    hour = 11;
    minute = 11;
    //일 시간 분을 전부 분으로 환산해서 그 차이 계산하면 됨. (답지 코드)
    //int diff = (a * 24 * 60 + b * 60 + c) - (11 * 24 * 60 + 11 * 60 + 11);
    while(true){
        if(a < day){
            fin_minute = -1;
            break;
        }
        if(day == a && hour == b && minute == c){
            break;
        }
        minute++;
        fin_minute++;
        if(minute == 60){
            hour++;
            minute = 0;
        }
        if(hour == 24){
            hour = 0;
            day++;
        }
    }

    cout << fin_minute;
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    calTime(a, b, c);

    return 0;
}