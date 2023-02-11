#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;

    int n, m;
    int count = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        DQ.push_back(i+1);
    }

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin();
        while(DQ.front() != t){
            if( idx < DQ.size() - idx){
                    DQ.push_back(DQ.front());
                    DQ.pop_front();
                    count++;
            }
            else{
                    DQ.push_front(DQ.back());
                    DQ.pop_back();
                    count++;
            }
        }
        DQ.pop_front();
    }

    cout << count;
}