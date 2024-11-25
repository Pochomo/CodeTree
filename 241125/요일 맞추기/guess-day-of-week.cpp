#include <iostream>
#include <string>
using namespace std;


int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calDate(int m1, int d1){
    int total_days = 0;
    for(int i = 1; i < m1; i++){
        total_days += num_of_days[i];
    }
    total_days += d1;
    
    return total_days;
}

int main() {

    int m1, d1, m2, d2;
    int num = 0;
    string date;
    cin >> m1 >> d1 >> m2 >> d2;

    num = (calDate(m2, d2) - calDate(m1, d1));

    if(num % 7 == 0){
        date = "Mon";
    }
    else if(num % 7 == 1 || num % 7 == -6){
        date = "Tue";
    }
    else if(num % 7 == 2 || num % 7 == -5){
        date = "Wed";
    }
    else if(num % 7 == 3 || num % 7 == -4){
        date = "Thu";
    }
    else if(num % 7 == 4 || num % 7 == -3){
        date = "Fri";
    }
    else if(num % 7 == 5 || num % 7 == -2){
        date = "Sat";
    }
    else if(num % 7 == 6 || num % 7 == -1){
        date = "Sun";
    }

    cout << date;

    return 0;
}

// 답지코드 날짜를 배열에 담아서 더 깔끔하게 만들었음.
// int main() {
//     // 변수 선언 및 입력
//     int m1, m2, d1, d2;
//     cin >> m1 >> d1 >> m2 >> d2;
    
//     // 두 날짜간의 차이가 몇 일인지를 구합니다.
//     int diff = NumOfDays(m2, d2) - NumOfDays(m1, d1);
    
//     // 음수인 경우에는, 양수로 넘겨 계산해주면 올바르게 계산이 됩니다. 
//     while(diff < 0)
//         diff += 7;
    
//     // 알맞은 요일의 이름을 출력합니다.
//     string day_of_week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
//     cout << day_of_week[diff % 7];
//     return 0;
// }