#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip> //소수점 첫째짜리 까지 표현하기 위해
 
using namespace std;

#define MAXN 1000


class People{
    public:
        string name;
        int height;
        float weight;
        People(string nameD = "" , int heightD = 0, float weightD = 1.0):name(nameD), 
        height(heightD), weight(weightD){}

};

bool cmp1(const People &a, const People &b){
    return a.name < b.name;
}

bool cmp2(const People &a, const People &b){
    return a.height > b.height;
}

People Peoples[MAXN];

int main() {
    string name;
    int height;
    float weight;

    for(int i = 0; i < 5; i++){
        cin >> name >> height >> weight;
        Peoples[i] = People(name, height, weight);
    }
    sort(Peoples, Peoples + 5, cmp1);
    cout << "name" << endl;
    for(int i = 0; i < 5; i++){
        cout << fixed << setprecision(1) << Peoples[i].name << " " << Peoples[i].height << " " << Peoples[i].weight;
        //소수점 첫째짜리 까지 표현하기 위해 fixed, setprecision(1) 사용
        cout << endl;
    }
    cout << endl;
    sort(Peoples, Peoples + 5, cmp2);
    cout << "height" << endl;
    for(int i = 0; i < 5; i++){
        cout << fixed << setprecision(1) << Peoples[i].name << " " << Peoples[i].height << " " << Peoples[i].weight;
        cout << endl;
    }

    return 0;
}