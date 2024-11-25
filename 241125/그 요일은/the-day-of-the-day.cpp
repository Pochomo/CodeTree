#include <iostream>
#include <string>

using namespace std;


int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//string day_of_week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
string day_of_week[] = {"Sun", "Sat", "Fri", "Thu", "Wed", "Tue", "Mon"};
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
    int cnt = 0;
    string dateA;
    string dateB;
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> dateA;

    num = (calDate(m2, d2) - calDate(m1, d1));
    int temp = 0;
    for(int i = 0; i < 7; i++){
        if(dateA == day_of_week[i]){
            temp = i+1;
        }
    }

    num += temp;

    cout << num / 7;
    
    return 0;
}