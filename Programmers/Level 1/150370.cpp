#include<bits/stdc++.h>
using namespace std;

enum DATE{
    YEAR,
    MONTH,
    DAY
};

map<char, int> terms_m;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    vector<int> vec_today;
    string digit;
    for(auto x : today){
        if(isdigit(x))
            digit += x;
        else{
            if(!digit.empty()){
                vec_today.push_back(stoi(digit));
                digit = "";
            }
        }
    }
    vec_today.push_back(stoi(digit));

    for(auto x : terms){
        digit = "";
        for(auto s : x)
            if(isdigit(s))
                digit += s;
        terms_m[x[0]] = stoi(digit);
    }

    for(int i = 0; i < privacies.size(); i++){
        vector<int> vec_privacy;
        char term;
        string digit = "";
        for(auto x : privacies[i]){
            if(isdigit(x))
                digit += x;
            else{
                if(!digit.empty()){
                    vec_privacy.push_back(stoi(digit));
                    digit = "";
                }
            }
            if(isalpha(x))
                term = x;
        }
        
        vec_privacy[MONTH] = (vec_privacy[MONTH] + terms_m[term]);
        if(vec_privacy[MONTH] >= 12){
            vec_privacy[YEAR] += (vec_privacy[MONTH] / 12);
            vec_privacy[MONTH] %= 12;
            if(vec_privacy[MONTH] == YEAR){
                vec_privacy[MONTH] = 12;
                vec_privacy[YEAR]--;
            }
        }
        
        if(vec_privacy[YEAR] < vec_today[YEAR])
            answer.push_back(i + 1);
        else if(vec_privacy[YEAR] == vec_today[YEAR])
            if(vec_privacy[MONTH] < vec_today[MONTH])
                answer.push_back(i + 1);
            else if(vec_privacy[MONTH] == vec_today[MONTH])
                if(vec_privacy[DAY] <= vec_today[DAY])
                    answer.push_back(i + 1);
    }

    return answer;
}