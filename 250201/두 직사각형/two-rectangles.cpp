#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

//겹치는 경우는 매우 많기 때문에 겹치지 않는 경우로 생각
int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    bool check = true;
    if(x2 < a1) check = false;
    else if(a2 < x1) check = false;
    else if(b2 < y1) check = false;
    else if(b1 > y2) check = false; 
    
    if(check) cout << "overlapping";
    else if(!check) cout << "nonoverlapping";

    return 0;
}