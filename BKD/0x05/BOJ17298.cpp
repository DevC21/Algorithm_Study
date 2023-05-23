#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int a[1'000'005];
int ans[1'000'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    // 기본적인 아이디어는 6198번 옥상 정원 꾸미기와 동일하나
    // 0번 배열부터 시작하는게 아니라 마지막 배열부터 시작해야함
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty()){
            if(s.top() > a[i])
                break;
            s.pop();
        }
        
        // 마지막 배열부터 시작 하지만 
        // 0번 배열부터 오큰수를 출력해야 하기때문에
        // 결과를 ans 배열에 저장한다.
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();

        s.push(a[i]);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}