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

        // 스택에 있는 건물 중에, 현재 입력보다 높은 건물이 나올 때까지 pop한다.
        // 첫 번째 입력은 스택 s가 비어있기 때문에 건너뛰게 된다.
		while (!s.empty()){
			if (s.top() > input)
				break;
			s.pop();
		}

        // 위 과정을 통해 스택에 남아 있는 빌딩들은 
        // 현재 입력으로 받은 빌딩을 볼 수 있는 빌딩들이다.
        // 따라서 새로운 빌딩을 스택에 넣기 전에 스택의 사이즈를 정답에 더해준다.
		ans += (ll)s.size();
        
        // 스택에 새로운 건물을 넣어준다.
		s.push(input);
	}
    
    cout << ans;
}