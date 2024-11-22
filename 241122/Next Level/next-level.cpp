#include <iostream>
#include <string>

using namespace std;

class Info{
    public:
        string iD1;        
        int level;
        Info(const string iD2 = "codetree", int level1 = 10):iD1(iD2), level(level1){
        }
};

int main(){
    string iD3;
    int level;

    Info ac;
    cin >> iD3 >> level;
    Info ax(iD3, level);

    cout << "user " << ac.iD1 << " lv " << ac.level << endl;
    cout << "user " << ax.iD1 << " lv " << ax.level << endl;

    return 0;
}