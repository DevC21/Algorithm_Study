#include<bits/stdc++.h>
using namespace std;

string tmp;

vector<string> ans;

void delzero(){  
	if(tmp.size()){
		while(true){  
			if(tmp.size() && tmp.front() == '0') tmp.erase(tmp.begin()); 
			else break;
		}
		if(tmp.size() == 0) tmp = "0"; 
		ans.push_back(tmp);
		tmp = "";
	}
}

bool cmp(const string& s1, const string& s2){
    if(s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        tmp = "";

        for(int j = 0; j < str.size(); j++){
            if(str[j] < 'a')
                tmp += str[j];
            else delzero();
        }
        delzero();
    }

    sort(ans.begin(), ans.end(), cmp);

    for(auto x : ans) cout << x << '\n';
}
