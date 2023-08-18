#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

// �ߺ��Ǵ� ���Ұ� ���� Ʃ���̹Ƿ�
// ���� �󵵰� ���� ���� ������� �����ϸ� ���� Ʃ���̴�.
map<int, int> m;

vector<int> solution(string s) {
    vector<int> answer;

    // ���ڿ� s���� ���ڸ� �̾Ƴ��� map�� ���� �󵵸� �����Ѵ�.
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

    // map�� vector�� �Ű� �����󵵸� ������������ �����Ѵ�.
    vector<pair<int,int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    for(auto x : vec)
        answer.push_back(x.first);

    return answer;
}