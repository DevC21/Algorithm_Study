#include<bits/stdc++.h>
using namespace std;

void Replace_Words(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    }
}

vector<string> s1;
vector<string> s2;

int solution(string str1, string str2) {
    int answer = 0;
    int Intersection = 0, Union = 0;

    Replace_Words(str1);
    Replace_Words(str2);

    for(int i = 0; i < str1.size() - 1; i++){
        if((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i + 1] >= 'a' && str1[i + 1] <= 'z')){
            string tmp = "";
            tmp += str1[i];
            tmp += str1[i + 1];
            s1.push_back(tmp);
        }
    }

    for(int i = 0; i < str2.size() - 1; i++){
        if((str2[i] >= 'a' && str2[i] <= 'z') && (str2[i + 1] >= 'a' && str2[i + 1] <= 'z')){
            string tmp = "";
            tmp += str2[i];
            tmp += str2[i + 1];
            s2.push_back(tmp);
        }
    }

    if(s1.empty() && s2.empty())
        return 65536;
    
    Union = s1.size() + s2.size();
    
    // 교집합 구하기
    if(s1.size() > s2.size()){
        for(int i = 0; i < s2.size(); i++){
            auto it = find(s1.begin(), s1.end(), s2[i]);
            if(it != s1.end()){
                Intersection++;
                s1.erase(it);
            }
        }
    }
    else{
        for(int i = 0; i < s1.size(); i++){
            auto it = find(s2.begin(), s2.end(), s1[i]);
            if(it != s2.end()){
                Intersection++;
                s2.erase(it);
            }
        }
    }
    
    // 전체 집합에서 교집합의 개수를 빼면 합집합의 개수가 나옴
    Union -= Intersection;
    
    if(Union == 0)
        return 65536;
        
    double tmp = (double)Intersection / (double)Union;
    
    return tmp * 65536;
}