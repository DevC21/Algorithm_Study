#include<bits/stdc++.h>
using namespace std;

int burger[4] = {1, 2, 3, 1};

int solution(vector<int> ingredient) {
    int answer = 0;

    vector<int> ingr;
    for(auto x : ingredient){
        ingr.push_back(x);

        if(ingr.size() >= 4){
            int arr[4];
            for(int i = 0; i < 4; i++)
                arr[i] = ingr[ingr.size() - 4 + i];

            if(equal(arr, arr+4, burger)){
                for(int i = 0; i < 4; i++)
                    ingr.pop_back();
                answer++;
            }
        }
    }

    return answer;
}