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