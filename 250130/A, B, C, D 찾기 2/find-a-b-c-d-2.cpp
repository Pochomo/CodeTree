#include <iostream>
#include <algorithm>

using namespace std;

int nums[15];


bool check(int a, int b, int c, int d) {
    int sums[15] = {a, b, c, d, a + b, b + c, c + d, d + a, a + c, b + d,
                    a + b + c, a + b + d, a + c + d, b + c + d, a + b + c + d};

    int found = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (nums[i] == sums[j]) {
                found++;
                break;
            }
        }
    }

    return found == 15;
}

int main() {
    for (int i = 0; i < 15; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + 15);
    int ans_a = nums[0]; //a는 고정됨
    int ans_b = nums[1]; //b까지 고정됨
    int ans_c = 0;
    int ans_d = 0;
    for (int c = ans_b; c <= 40; c++) { 
        for (int d = c; d <= 40; d++) {
            if (check(ans_a, ans_b, c, d)) { 
                ans_c = c;
                ans_d = d;
                cout << ans_a << " " << ans_b << " " << ans_c << " " << ans_d;
                return 0;
            }
        }
    }

    return 0;
}