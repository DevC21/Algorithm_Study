#include<bits/stdc++.h>
using namespace std;

char List[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string Base_Convert(int num, int base){
    string s = "";

    if(num == 0)
        return "0";

    // 10진수를 초과해서 표현할 때 
    // 10 11 12 13 14 15이 아닌 A B C D E F로 표현하라고 제시 했으므로
    // 나머지 연산 결과를 List의 배열로 넘겨준다.
    while(num != 0){
        s += List[num % base];
        num /= base;
    }
    reverse(s.begin(), s.end());

    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string result = "";

    // 't'는 "튜브가 말해야 하는 숫자의 갯수"
    // 'm'은 "게임에 참가하는 인원 수"
    // 따라서 미리 t * m개의 숫자를 구해야 한다.
    for (int i = 0; i < t * m; i++) 
        result += Base_Convert(i, n);
    
    int cnt = 0;
    // i = 무지의 첫턴 
    // 미리 구한 숫자가 담긴 문자열의 길이 만큼 반복
    // 게임에 참가하는 인원 m턴 마다 무지의 턴이 돌아오기 때문에
    // i 증가식 : i += m 
    for (int i = p - 1; i < result.size(); i += m){
        answer += result[i];
        cnt++;
        // 숫자를 모두 찾았으면 break
        if(cnt >= t)
            break;
    }
    return answer;
}

int main(){
    string ans = solution(16, 16, 2, 1);

    return 0;
}