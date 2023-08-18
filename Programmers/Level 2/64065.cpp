#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

// 중복되는 원소가 없는 튜플이므로
// 출현 빈도가 높은 원소 순서대로 나열하면 원본 튜플이다.
map<int, int> m;

vector<int> solution(string s) {
    vector<int> answer;

    // 문자열 s에서 숫자만 뽑아내고 map에 출현 빈도를 저장한다.
    string s_num = "";
    for(auto x : s){
        if(isdigit(x)){
            s_num += x;
        }
        else if(!isdigit(x) && s_num != ""){
            m[stoi(s_num)]++;
            s_num = "";
        }
    }

    // map을 vector로 옮겨 출현빈도를 내림차순으로 정렬한다.
    vector<pair<int,int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    for(auto x : vec)
        answer.push_back(x.first);

    return answer;
}