#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> m;
    int k, l;

    cin >> k >> l;

    for(int i = 0; i < l; i++){
        string s;
        cin >> s;
        m[s] = i;
    }

    vector<pair<string, int>> v;
	for (auto& i : m)
		v.push_back(i);

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < min(k, (int)v.size()); i++)
		cout << v[i].first << '\n';
}