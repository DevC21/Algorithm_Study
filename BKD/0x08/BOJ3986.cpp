#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int count = 0;

    string s;

    cin >> n;

    for(int i = 0 ; i < n; i++){
        stack<char> cs;
        cin >> s;
        

        for(char c : s){
            if (!cs.empty()){
                if(cs.top() == c){
                    cs.pop();
                }            
                else{
                    cs.push(c);
                }
            }
            else{
                cs.push(c);
            }
        }

        if(cs.empty())
            count++;
    }

    std::cout << count;
}