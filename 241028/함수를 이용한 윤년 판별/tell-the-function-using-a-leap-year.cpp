#include <iostream>
using namespace std;


bool cheakYear(int year){
    if(year % 4 == 0){
        return true;
    }
    else if(year % 100 == 0 && year % 400 != 0){
        return false;
    }
    else{
        return false;
    }
}

int main() {
    int year;
    cin >> year;
    if(cheakYear(year)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}