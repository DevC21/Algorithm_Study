#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // 입력 배열을 사전순으로 정렬
    sort(phone_book.begin(), phone_book.end());

    // 문자열을 사전순으로 정렬한 경우 서로 붙어있는 문자열끼리만 
    // 비교해보면 접두어인 경우를 찾을 수 있다.
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