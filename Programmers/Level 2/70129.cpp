#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int cnt = 0;
    int purgedzero = 0;
    while(s != "1"){
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '0')
                purgedzero++;
        s = regex_replace(s, regex("0"), "");
        
        int size = s.size();
        s = "";
        while(size != 0){
            s.insert(0, to_string(size % 2));
            size /= 2;
        }
        cnt++;
    }

    answer.push_back(cnt);
    answer.push_back(purgedzero);
    return answer;
}