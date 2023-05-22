#include<bits/stdc++.h>
using namespace std;

vector<int> adj[505];
bool vis[505];

bool DFS(int node, int parentnode){
    vis[node] = true;
    for(int nxt : adj[node]) {
        if (!vis[nxt]){
            if(DFS(nxt, node))
                return true;
        }
        else if(parentnode != nxt)
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 1;

    while(true){
        int t = 0;
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 1; i <= 500; i++){
            adj[i].clear();
        }
        fill(vis+1, vis+501, false);

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				if (!DFS(i, -1)) 
                    t++;
			}
		}

        cout << "Case " << c++;
        if(t == 0){
            cout << ": No trees." << '\n';
        }
        else if(t == 1){
            cout << ": There is one tree." << '\n';
        }
        else{
            cout << ": A forest of " << t << " trees."<< '\n';            
        }
    }
}