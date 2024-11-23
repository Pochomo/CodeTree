#include <iostream>
#include <algorithm>

using namespace std;

int n;

class People{
    public:
        string name;
        int korean;
        int english;
        int math;
        People(string nameD = " ", int koreanD = 0, int englishD = 0, int mathD = 0)
        :name(nameD), korean(koreanD), english(englishD), math(mathD){}
};

bool cmp(const People &a, const People &b){
    return a.korean + a.english + a.math < b.korean + b.english + b.math;
}

int main() {
    string name;
    int korean;
    int english;
    int math;
    cin >> n;
    People Peoples[n];
    for(int i = 0; i < n; i++){
        cin >> name >> korean >> english >> math;
        Peoples[i] = People(name, korean, english, math);
    }

    sort(Peoples, Peoples + n, cmp);

    for(int i = 0; i < n; i++){
        cout << Peoples[i].name << " " << Peoples[i].korean << " " << Peoples[i].english << " ";
        cout << Peoples[i].math;
        cout << endl;
    }
    return 0;
}