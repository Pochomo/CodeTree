#include <iostream>

using namespace std;

int a, b, c, d;
bool cleaned[100];
int main() {
    cin >> a >> b;
    cin >> c >> d;

    //A는 x = a구역에서 x = b구역이내 청소

    int cnt = 0;
    for(int i = a; i < b; i++){
        cleaned[i] = true;
        cnt++;
    }
    for(int i = c; i < d; i++){
        if(cleaned[i] == true) continue;
        else cnt++;
    }

    cout << cnt;


    return 0;
}