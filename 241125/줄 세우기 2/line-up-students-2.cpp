#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1000

int n;

class People{
    public:
        int height;
        int weight;
        int number;
        People(int heightD = 0, int weightD = 1, int numberD = 0):
        height(heightD), weight(weightD), number(numberD){}

};

bool cmp(const People &a, const People &b){
    if(a.height == b.height){
        return a.weight > b.weight;
    }
    return a.height < b.height;
}

People Peoples[MAXN];

int main() {
    int height;
    int weight;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> height >> weight;
        Peoples[i] = People(height, weight, i+1);
    }

    sort(Peoples, Peoples + n, cmp);

    for(int i = 0; i < n; i++){
        cout << Peoples[i].height << " " << Peoples[i].weight << " " << Peoples[i].number;
        cout << endl;
    }

    return 0;
}