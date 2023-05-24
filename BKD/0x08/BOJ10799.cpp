#include<bits/stdc++.h>
using namespace std;

stack<char> s;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    char pre;
    for(auto x : str){
        if(x == '(')
            s.push(x);
        

        if(x == ')'){
            // ������ ���� ���ڰ� '(' ��� �������̹Ƿ�
            // ���ÿ� �ִ� '(' ������ŭ�� ���������� �ڸ��� �ȴ�
            // ���� ans�� ������ ũ�⸸ŭ �����ش�.
            if(pre == '('){
                s.pop();
                ans += s.size();
            }
            // ������ ���� ���ڰ� ')' ��� ���������� ���̹Ƿ�
            // ���������� �ڸ��� �������� ���������� �� �κ��� ����.
            // ���� ans�� 1��ŭ �����ش�.
            else if(pre == ')'){
                s.pop();
                ans++;
            }
        }
        pre = x;
    }

    cout << ans;
}