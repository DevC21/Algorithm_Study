#include<bits/stdc++.h>
using namespace std;

int n, m;
int s[21];
bool chk[2'000'001];

//  �� ���� ���� ������ ������ ������ �����ϴ� ������� ��� �κ� ������ ���� �̾Ƴ���.
void func(int cur, int sum){
    chk[sum] = true;
    if(cur == n) return;

    func(cur + 1, sum);
    func(cur + 1, sum + s[cur]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    func(0, 0);

    int ans = 1;
    while(chk[ans]) ans++;

    cout << ans;
    return 0;
}