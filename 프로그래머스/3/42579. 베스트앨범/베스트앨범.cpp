#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//장르별로 가장 많이 재생된 노래 "두 개"씩 모아 베스트 앨범 출시

//속한 노래가 많이 재생된 장르를 먼저 수록
//장르 내에서 많이 재생된 노래를 먼저 수록
//장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
//종류별로 최대 장르 구분, 내림차순 배열, 최대 2개씩 선택 후 vector answer에 push_back
class GenreSorter {
private:
    unordered_map<string, int>& totalPlays;

public:
    GenreSorter(unordered_map<string, int>& totalPlays) : totalPlays(totalPlays) {}

    bool operator()(const string& a, const string& b) {
        return totalPlays[a] > totalPlays[b];
    }
};

class SongSorter {
private:
    vector<int>& plays;

public:
    SongSorter(vector<int>& plays) : plays(plays) {}

    bool operator()(int a, int b) {
        if (plays[a] == plays[b]) return a < b;
        return plays[a] > plays[b];
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> totalPlays;
    unordered_map<string, vector<int>> songIndex;

    for (int i = 0; i < genres.size(); i++) {
        totalPlays[genres[i]] += plays[i];
        songIndex[genres[i]].push_back(i);
    }

    vector<string> sortedGenres;
    for (const auto& pair : totalPlays) {
        sortedGenres.push_back(pair.first);
    }
    
    sort(sortedGenres.begin(), sortedGenres.end(), GenreSorter(totalPlays));

    vector<int> answer;

    for (const string& genre : sortedGenres) {
        sort(songIndex[genre].begin(), songIndex[genre].end(), SongSorter(plays));

        for (int i = 0; i < min(2, (int)songIndex[genre].size()); i++) {
            answer.push_back(songIndex[genre][i]);
        }
    }


    return answer;
}
