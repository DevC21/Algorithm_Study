#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // �Է� �迭�� ���������� ����
    sort(phone_book.begin(), phone_book.end());

    // ���ڿ��� ���������� ������ ��� ���� �پ��ִ� ���ڿ������� 
    // ���غ��� ���ξ��� ��츦 ã�� �� �ִ�.
    for(int i = 0; i < phone_book.size() - 1; i++){
        string s = phone_book[i + 1].substr(0, phone_book[i].size());
        if(s == phone_book[i])
            return false;
    }

    return answer;
}

int main(){
    bool ans = solution({"119", "97674223", "1195524421"});

    return 0;
}