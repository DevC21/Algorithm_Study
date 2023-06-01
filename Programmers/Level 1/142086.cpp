#include<bits/stdc++.h>
using namespace std;

// Node ��� Struct�� ����� 
// �⺻���� -1�� ������ int�� �ʵ�� �д�.
struct Node {
    int value = -1;
};

// ������ ������ Node�� map���� ����ϸ�
// �ʱⰪ�� -1�� ������ map�� ������ �� �ִ�.
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