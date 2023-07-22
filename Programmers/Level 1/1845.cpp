#include<bits/stdc++.h>
using namespace std;

set<int> pokemon;

int solution(vector<int> nums){
    int answer = 0;

    for(int x : nums)
        pokemon.insert(x);

    int size = pokemon.size();
    int maxsel = nums.size() / 2;
    if(size < maxsel)
        answer = size;
    else
        answer = maxsel;

    return answer;
}