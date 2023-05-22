#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int indegree[1005];

map<string, int> p;
string NumToName[1005];

queue<int> q;
vector<int> result[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        NumToName[i] = name;
    }

    sort(NumToName, NumToName+n);

    for(int i = 0; i < n; i++){
        p[NumToName[i]] = i;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string x, y;
        cin >> x >> y;
        adj[p[y]].push_back(p[x]);
        indegree[p[x]]++;
    }

    vector<string> ancestor;

    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
            ancestor.push_back(NumToName[i]);
    }

    sort(ancestor.begin(), ancestor.end());

    cout << ancestor.size() << '\n';
    for(auto x : ancestor){
        cout << x << ' ';
    }
    cout << '\n';

    for(auto x : ancestor)
        q.push(p[x]);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]){
            if(indegree[nxt] != 0)
                indegree[nxt]--;
            if(indegree[nxt] == 0){
                q.push(nxt);
                result[cur].push_back(nxt);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << NumToName[i] << ' ';
        cout << result[i].size() << ' ';
        sort(result[i].begin(), result[i].end());
        for(auto c : result[i]){
            cout << NumToName[c] << ' ';
        }
        cout << '\n';
    }
}