#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end()); //min힙 생성 begin end 로 초기화
    int mix_count = 0;

    while (minHeap.size() > 1 && minHeap.top() < K) {
        int least_spicy = minHeap.top();
        minHeap.pop();
        int second_least_spicy = minHeap.top();
        minHeap.pop();

        int new_scoville = least_spicy + (second_least_spicy * 2);
        minHeap.push(new_scoville);
        mix_count++;
    }
    
    if(!(minHeap.top() >= K)) mix_count = -1;

    return mix_count;
}
