#include<bits/stdc++.h>
using namespace std;

int n, ans = INT32_MAX, cnt = 0;
string st, ed, tmp;

void solve(bool first){
    tmp = st;
    cnt = 0;
    // ù��° ����ġ�� �۵��ϰ� ������ ���
    if(first == true){
        if(tmp[0] == '0') tmp[0] = '1';
        else tmp[0] = '0';
        if(tmp[1] == '0') tmp[1] = '1';
        else tmp[1] = '0';
        cnt++;
    }

    for(int i = 1; i < n; i++){
        if(tmp[i - 1] != ed[i - 1]){
            // i - 1��° �����ѱ�
            if(tmp[i - 1] == '0') tmp[i - 1] = '1';
            else tmp[i - 1] = '0';
            // i��° �����ѱ�
            if(tmp[i] == '0') tmp[i] = '1';
            else tmp[i] = '0';
            // i + 1��° �����ѱ�(n - 1��° ����ġ����)
            if(i < n - 1){
                if(tmp[i + 1] == '0') tmp[i + 1] = '1';
                else tmp[i + 1] = '0';
            }
            // ���� Ƚ�� ����
            cnt++;
        }
    }

    // ����� ��ǥ���� ������ ����
    if(tmp == ed)
        ans = min(ans, cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> st;
    cin >> ed;

    // �׳� ������ ���
    solve(false);
    // ù��° ����ġ�� �۵��ϰ� ������ ���
    solve(true);
    
    if(ans != INT32_MAX)
        cout << ans;
    else
        cout << -1;
}