#include <iostream>

#define MAX_N 100
#define MAX_R 2000
#define OFFSET 1000

using namespace std;

int n;
int x1[MAX_N], x2[MAX_N];

int checked[MAX_R + 1];

int main() {
    
    cin >> n;
    
	int cur = 0;
	
    for(int i = 0; i < n; i++) {
		int distance;
		char direction;
        cin >> distance >> direction;
		
		if(direction == 'L') {
			x1[i] = cur - distance;
			x2[i] = cur;
			cur -= distance;
		}
		else {
			
			x1[i] = cur;
			x2[i] = cur + distance;
			cur += distance;
		}
        
        x1[i] += OFFSET;
        x2[i] += OFFSET;
    }
    

    for(int i = 0; i < n; i++)
        for(int j = x1[i]; j < x2[i]; j++)
            checked[j]++;
    
    int cnt = 0;
    for(int i = 0; i <= MAX_R; i++)
        if(checked[i] >= 2)
            cnt++;
    
    cout << cnt;
    return 0;
}