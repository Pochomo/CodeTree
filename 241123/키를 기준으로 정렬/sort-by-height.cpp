#include <iostream>
#include <algorithm>

using namespace std;

int n;

class People{
    public:
        string name;
        int height;
        int weight;
        People(string nameD = " ", int heightD = 0, int weightD = 0):name(nameD), height(heightD), weight(weightD){}

};

bool cmp(const People &a, const People &b){
    return a.height < b.height;
}

int main() {
    string name;
    int height;
    int weight;
    cin >> n;
    People Peoples[n];
    for(int i = 0; i < n; i++){
        cin >> name >> height >> weight;
        Peoples[i] = People(name, height, weight);
    }

    sort(Peoples, Peoples + n, cmp);

    for(int i = 0; i < n; i++){
        cout << Peoples[i].name << " " << Peoples[i].height << " " << Peoples[i].weight;
        cout << endl;
    }
    return 0;
}