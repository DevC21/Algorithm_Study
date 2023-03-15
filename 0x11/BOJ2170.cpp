#include<bits/stdc++.h>
using namespace std;

pair<int, int> L[1000005];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> L[i].first >> L[i].second;
    }

    sort(L, L+n);

    int l = -(1e9+1); // -1,000,000,001
    int r = -(1e9+1);

    for(int i = 0; i < n; i++){
        // r = ���� ������ ������ �� L[i].first = �̹� ���� ���� ��
        // r < L[i].first ���� ������ ������ ���� �̹� ���� ���� ���� ������ �־ ��ĥ �� ����
        if(r < L[i].first){
            //���信 ���� ������ ���̸� ���ϰ� ���ο� ������ ����
            ans += r-l;

            l = L[i].first;
            r = L[i].second;
        }
        else{
            // ��ġ�°� ������ ��, ���� ������ ������ ���� Ȯ�� ���� �ϴٸ� Ȯ��
            r = max(r, L[i].second);
        }
    }
    ans += r-l;

    cout << ans;
}