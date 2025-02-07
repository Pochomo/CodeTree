#include <iostream>
#include <algorithm>
using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    int max_x = max({x1, x2, a1, a2});
    int min_x = min({x1, x2, a1, a2});
    int max_y = max({y1, y2, b1, b2});
    int min_y = min({y1, y2, b1, b2});

    int make_sqare_x = max((max_x - min_x), (max_y - min_y));

    cout << make_sqare_x * make_sqare_x;

    return 0;
}