#include <iostream>
#include <algorithm>

using namespace std;

int n;
int name = 1;
class People{
    public:
        int name;
        int height;
        int weight;
        People(int heightD = 0, int weightD = 0, int nameD = 0): 
        height(heightD), weight(weightD), name(nameD){

        }

};

bool cmp(const People &a, const People &b){
    if(a.height != b.height){
        return a.height > b.height;
    }
    if(a.weight != b.weight){
        return a.weight > b.weight;
    }
    return a.name < b.name;
}

int main() {
    int height;
    int weight;
    cin >> n;
    People Peoples[n];
    for(int i = 0; i < n; i++){
        cin >> height >> weight;
        Peoples[i] = People(height, weight, name);
        name++;
    }

    sort(Peoples, Peoples + n, cmp);

    for(int i = 0; i < n; i++){
        cout << Peoples[i].height << " " << Peoples[i].weight << " " << Peoples[i].name;
        cout << endl;
    }
    return 0;
}