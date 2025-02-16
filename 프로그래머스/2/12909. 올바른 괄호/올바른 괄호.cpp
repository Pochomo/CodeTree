#include <string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> twins;
    
    for(int i = 0; i < (int)s.length(); i++){
        twins.push(s[i]);
    }
    
    int count = 0;
    while(!twins.empty()){
        if(twins.front() == '('){
            count ++;
            twins.pop();
        }
        else{
            count--;
            twins.pop();
        }
        if(count < 0) return false;
    }
    
    if(count == 0) answer = true;
    else answer = false;
    
    return answer;
}