#include<bits/stdc++.h>
using namespace std;

int m, n;
int a[101][10005];

void compress(int a[]) {
  vector<int> v(a, a+n);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
}

bool compare(int a[], int b[]) {
  for (int k = 0; k < n; k++)
    if (a[k] != b[k]) 
        return false;
  return true;
}

// 두 우주를 좌표 압축하였을 때 동일하면 균등한 우주이다.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
        compress(a[i]);
    }   

    int ans = 0;
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            ans += compare(a[i], a[j]);
    cout << ans;
}