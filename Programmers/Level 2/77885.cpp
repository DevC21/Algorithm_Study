#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 2�������� ��ȯ�Ҷ�
// ���� �����ʿ� ó������ ������ 0�� 1���� �ٲٰ�
// �� �ٷ� ������ �ڸ��� 0���� �ٲٸ� ���ǿ� �����ϴ� ���� �ȴ�.

// ���ǿ� �����ϴ� �� f(n)�� �־��� �� n�� 2�� ������鼭 ���� ó�� ������ 0�� �ڸ��� i�� ����
// f(n) = n + 2^(i+1) - n^i�� �ȴ�
// �̶�, ¦���� �׻� �� ������ ��Ʈ�� 0�̹Ƿ� n���� 1�� ���� ���̴�.

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;

    ll tmp;
    int cnt;

    for(int i = 0; i < numbers.size(); i++){
        tmp = numbers[i];
        cnt = 0;
        if(numbers[i] % 2 == 0){
            answer.push_back(tmp + 1);
            continue;
        }

        while(tmp > 0){
            if(tmp % 2 == 0)
                break;
            tmp /= 2;
            cnt++;
        }

        tmp = numbers[i] + pow(2, cnt) - pow(2, cnt - 1);
        answer.push_back(tmp);
    }

    return answer;
}

int main(){
    vector<ll> ans = solution({2, 7});

    return 0;
}
