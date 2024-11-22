#include <iostream>

using namespace std;

class CodeScore{
    public:
        char cname;
        int score;
        CodeScore(char cname1 = ' ', int score1 = 0):cname(cname1), score(score1){}
        

        void printInfo(){
            cout << cname << " " << score;
        }
        
};

void sorting1(CodeScore& n1, int& min1);

int main() {
    char cname;
    int score;
    CodeScore CodeScoreArr[5]; //매개변수를 받지않는 CodeScore 생성자 사용
    for(int i = 0; i < 5; i++){
        cin >> cname >> score;
        CodeScoreArr[i] = CodeScore(cname, score);
    }
    int min1 = CodeScoreArr[0].score;

    //index로 접근해서 최소 값 찾기
    for(int i = 1; i < 5; i++){
        sorting1(CodeScoreArr[i], min1);
    }
    // int min_idx = 0;
    // for(int i = 1; i < MAX_N; i++) {
    //     if(users[min_idx].score > users[i].score)
    //         min_idx = i;
    // }
    //index로 접근했으면 아래와 같은 for문 안 써도됨
    for(int i = 0; i < 5; i++){
        if(CodeScoreArr[i].score == min1){
            CodeScoreArr[i].printInfo();
        }
    }
    
    return 0;
}

void sorting1(CodeScore& n1, int& min1){
    if(min1 > n1.score){
        min1 = n1.score;
    }
}