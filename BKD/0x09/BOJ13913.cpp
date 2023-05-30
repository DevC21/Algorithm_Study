#include<bits/stdc++.h>
using namespace std;

int dist[100'005];
int pre[100'005];
int dx[3] = {1,-1,2};
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dist, dist+100'001, -1);
    queue<int> Q;
    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        auto cur = Q.front(); 
        Q.pop();
        if(cur == k){
            cout << dist[cur] << '\n';
            cout << cur;
            return 0;
        }
        for(int i = 0; i < 3; i++){
            int nx;
            if(i < 2)
                nx = cur + dx[i];
            else
                nx = cur * dx[i];
            if(nx < 0 || nx > 100'000) continue;
            if(dist[nx] >= 0) continue;
            if(nx == k){
                cout << dist[cur] + 1 << '\n';
                
                pre[nx] = cur;
                int a = nx;

                ans.push_back(nx);
                while(a != n){
                    ans.push_back(pre[a]);
                    a = pre[a];
                }

                reverse(ans.begin(), ans.end());
                for(auto x : ans)
                    cout << x << ' ';
                return 0;
            }
            dist[nx] = dist[cur] + 1;
            pre[nx] = cur;
            Q.push(nx);
        }
    }
}