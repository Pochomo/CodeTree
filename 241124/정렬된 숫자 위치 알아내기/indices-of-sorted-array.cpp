#include <iostream>
#include <algorithm>
using namespace std;

class Sorting{
    public:
        int num;
        int location;
        Sorting(int num1 = 0, int location1 = 1):num(num1), location(location1){}
};

bool cmp(const Sorting & x1, const Sorting & x2){
    if(x1.num == x2.num){
        return x1.location < x2.location;
    }
    return x1.num < x2.num;
}

int main() {
    int n;
    int element;
    int *result;
    cin >> n;
    Sorting sortingArr[n];
    result = new int[n];
    for(int i = 0; i < n; i++){
        cin >> element;
        sortingArr[i] = Sorting(element, i);
    }

    sort(sortingArr, sortingArr + n, cmp);

    for(int i = 0; i < n; i++){
        result[sortingArr[i].location] = i + 1;
    }
    
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    
    return 0;
}