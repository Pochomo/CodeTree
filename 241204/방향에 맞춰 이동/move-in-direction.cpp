#include <iostream>
using namespace std;

char directionA[100];
int distanceA[1000];
int locationA[2];
int main() {
    int n;
    cin >> n;
    char direction;
    int distance;
    for(int i = 0; i < n; i++){
        cin >> direction >> distance;
        if(direction == 'N'){
            locationA[1] += distance;
        }
        else if(direction == 'S'){
            locationA[1] -= distance;
        }
        else if(direction == 'E'){
            locationA[0] += distance;   
        }
        else if(direction == 'W'){
            locationA[0] -= distance;
        }
    }
    for(int i = 0; i < 2; i ++){
            cout << locationA[i] << " ";

    }
    return 0;
}