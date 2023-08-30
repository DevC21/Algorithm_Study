#include<bits/stdc++.h>
using namespace std;

char List[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string Base_Convert(int num, int base){
    string s = "";

    if(num == 0)
        return "0";

    // 10������ �ʰ��ؼ� ǥ���� �� 
    // 10 11 12 13 14 15�� �ƴ� A B C D E F�� ǥ���϶�� ���� �����Ƿ�
    // ������ ���� ����� List�� �迭�� �Ѱ��ش�.
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

    // 't'�� "Ʃ�갡 ���ؾ� �ϴ� ������ ����"
    // 'm'�� "���ӿ� �����ϴ� �ο� ��"
    // ���� �̸� t * m���� ���ڸ� ���ؾ� �Ѵ�.
    for (int i = 0; i < t * m; i++) 
        result += Base_Convert(i, n);
    
    int cnt = 0;
    // i = ������ ù�� 
    // �̸� ���� ���ڰ� ��� ���ڿ��� ���� ��ŭ �ݺ�
    // ���ӿ� �����ϴ� �ο� m�� ���� ������ ���� ���ƿ��� ������
    // i ������ : i += m 
    for (int i = p - 1; i < result.size(); i += m){
        answer += result[i];
        cnt++;
        // ���ڸ� ��� ã������ break
        if(cnt >= t)
            break;
    }
    return answer;
}

int main(){
    string ans = solution(16, 16, 2, 1);

    return 0;
}