#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int area = brown + yellow;
    bool found = false;

    for(int i = brown / 2; i > 0; i--){
        for(int j = 1; j <= i; j++){
            if(i * j == area){
                if((i * 2 + (j - 2) * 2) == brown){
                    answer.push_back(i);
                    answer.push_back(j);
                    found = true;
                    break;
                }
            }
        }
        if(found)
            break;
    }

    return answer;
}

int main(){
    vector<int> ans = solution(10, 2);

    return 0;
}