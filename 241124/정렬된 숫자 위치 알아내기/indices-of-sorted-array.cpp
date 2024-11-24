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
    int *tempnum;
    int *result;
    cin >> n;
    Sorting sortingArr[n];
    tempnum = new int[n];
    result = new int[n];
    for(int i = 0; i < n; i++){
        cin >> element;
        sortingArr[i] = Sorting(element, i+1);
    }

    for(int i = 0; i < n; i++){
        tempnum[i] = sortingArr[i].num;
    }

    sort(sortingArr, sortingArr + n, cmp);


    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            if(tempnum[i] == sortingArr[j-1].num && i+1 == sortingArr[j-1].location){
                result[i] = j;
            }
        }
    }      

    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    
    return 0;
}