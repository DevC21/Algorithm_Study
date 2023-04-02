#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> db;
map<int, int> dict;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; 
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int p, l; 
        cin >> p >> l;

        db.insert({l, p});
        dict[p] = l;
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
        string cmd; 
        cin >> cmd;
    
        if(cmd == "add"){
            int p, l; 
            cin >> p >> l;
            db.insert({l, p});
            dict[p] = l;
        }else if(cmd == "recommend"){
            int x; 
            cin >> x;
            if(x == -1){    // ���� ���� ������ ��ȣ�� ���
                cout << (*db.begin()).second << "\n";
            }else{  // x == 1, ���� ����� ������ ��ȣ�� ���
                cout << (*prev(db.end())).second << "\n";
            }
        }else{  // cmd == "solved"
            int p; 
            cin >> p;
            db.erase({dict[p], p});
            dict.erase(p);
        }
    }
}