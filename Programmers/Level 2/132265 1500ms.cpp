#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    int slice_1[10'005];
    int slice_2[10'005];
    int max_value = 0;
    for(int i = 0; i < topping.size(); i++){
        slice_2[topping[i]]++;
        max_value = max(max_value, topping[i]);
    }
    
    for(int i = 0; i < topping.size(); i++){
        int cnt1 = 0;
        int cnt2 = 0;
        slice_1[topping[i]]++;
        slice_2[topping[i]]--;

        for(int i = 1; i <= max_value; i++){
            if(slice_1[i] > 0)
                cnt1++;
            if(slice_2[i] > 0)
                cnt2++;                
        }

        if(cnt1 == cnt2)
            answer++;
    }

    return answer;
}