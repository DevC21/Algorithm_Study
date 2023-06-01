#include<bits/stdc++.h>
using namespace std;

// Node 라는 Struct를 만들고 
// 기본값을 -1로 가지는 int만 필드로 둔다.
struct Node {
    int value = -1;
};

// 위에서 정의한 Node를 map에서 사용하면
// 초기값을 -1로 가지는 map을 정의할 수 있다.
map<char, Node> pos;

vector<int> solution(string s) {
    vector<int> answer;

    for(int i = 0; i < s.size(); i++){
        if(pos[s[i]].value == -1){
            answer.push_back(-1);
            pos[s[i]].value = i;
        }
        else{
            answer.push_back(i - pos[s[i]].value);
            pos[s[i]].value = i;
        }
    }

    return answer;
}