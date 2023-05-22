#include<bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> s;
ll ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

	for (int i = 0; i < n; i++){
        int input;
		cin >> input;

        // ���ÿ� �ִ� �ǹ� �߿�, ���� �Էº��� ���� �ǹ��� ���� ������ pop�Ѵ�.
        // ù ��° �Է��� ���� s�� ����ֱ� ������ �ǳʶٰ� �ȴ�.
		while (!s.empty()){
			if (s.top() > input)
				break;
			s.pop();
		}

        // �� ������ ���� ���ÿ� ���� �ִ� �������� 
        // ���� �Է����� ���� ������ �� �� �ִ� �������̴�.
        // ���� ���ο� ������ ���ÿ� �ֱ� ���� ������ ����� ���信 �����ش�.
		ans += (ll)s.size();
        
        // ���ÿ� ���ο� �ǹ��� �־��ش�.
		s.push(input);
	}
    
    cout << ans;
}