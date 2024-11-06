#include <iostream>
using namespace std;

bool check(int month, int day){
    if(month == 2){
        if(day > 28){
            return false;
        }
        else{
            return true;
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day > 31){
            return false;
        }
        else{
            return true;
        }
    }
    else if(month == 2 || month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}

int main() {
    int month, day;
    cin >> month >> day;
    if(check(month, day)==true){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}