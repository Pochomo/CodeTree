#include <iostream>
#include <algorithm>

using namespace std;

class Point{
    public:
        int x;
        int y;
        int distance;
        int num;
        Point(int x1 = 0, int y1 = 0, int num1 = 1)
        :x(x1), y(y1), num(num1){
            if(x < 0){
                x *= -1;
            }
            if(y < 0){
                y *= -1;
            }
            distance = x + y;
        }
};

bool cmp(const Point & x1, const Point & x2){
    return x1.distance < x2.distance;
}


int main() {
    int n;
    int x;
    int y;
    int *distance;
    cin >> n;
    Point pointArr[n];
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pointArr[i] = Point(x, y, i+1);
    }
    sort(pointArr, pointArr + n, cmp);
    for(int i = 0; i < n; i++){
        cout << pointArr[i].num << endl;
    }

    return 0;
}