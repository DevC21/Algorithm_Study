#include<bits/stdc++.h>
using namespace std;

int n;
int r[100005];
int l[100005];
int p[100005];
bool vis[100005];
int cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        l[a] = b;
        r[a] = c;
        p[b] = a;
        p[c] = a;
    }

    p[1] = -1;
    
    int endpoint = 1;
    while (r[endpoint] != -1)
        endpoint = r[endpoint];

    int cur = 1;
    while(true){
        vis[cur] = true;
        cnt++;
        if (l[cur] != -1 && !vis[l[cur]])
            cur = l[cur];
        else if (r[cur] != -1 && !vis[r[cur]])
            cur = r[cur];
        else {
            if(cur == endpoint)
                break;
            else
                cur = p[cur];
        }
    }
    cout << cnt - 1;
}