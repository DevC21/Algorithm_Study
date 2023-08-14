#include<bits/stdc++.h>
using namespace std;

map<string, int> m_want;
map<string, int> m_discount;
bool chk;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;


    for(int i = 0; i < want.size(); i++)
        m_want[want[i]] = number[i];

    for(int i = 0; i < 10; i++)
            m_discount[discount[i]]++;

    for(int i = 0; i < discount.size() - 9; i++){
        chk = true;
        for(auto x : want){
            if(m_discount[x] < m_want[x]){
                chk = false;
                break;
            }
        }
        if(chk)
            answer++;

        if(i + 10 < discount.size()){
            m_discount[discount[i]]--;
            m_discount[discount[i + 10]]++;
        }
    }

    return answer;
}