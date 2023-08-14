#include<bits/stdc++.h>
using namespace std;

void Replace_Words(vector<string> &cities){
    for(int i = 0; i < cities.size(); i++){
        for(int j = 0; j < cities[i].size(); j++){
            if(cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cities[i][j] = cities[i][j] - 'A' + 'a';
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if(cacheSize == 0)
        return cities.size() * 5;

    Replace_Words(cities);

    for(int i = 0; i < cities.size(); i++){
        bool cacheHit = false;
        int idx = 0;

        // 현재 입력받은 모든 cities의 종류가 cache 크기보다 적은 경우
        if(cache.size() < cacheSize){
            for(int j = 0; j < cache.size(); j++){
                if(cache[j] == cities[i]){
                    cacheHit = true;
                    idx = j;
                    break;
                }
            }
        }
        // 현재 입력받은 모든 cities의 종류가 cache 크기보다 많은 경우
        else{
            for(int j = 0; j < cacheSize; j++){
                if(cache[j] == cities[i]){
                    cacheHit = true;
                    idx = j;
                    break;
                }
            }
        }

        // cacheHit인 경우
        if(cacheHit){
            // cache의 맨뒤에 cities가 오게 갱신하고 
            cache.push_back(cities[i]);
            // 원래 cities가 있던 자리에서 삭제한다.
            cache.erase(cache.begin() + idx);
            answer += 1;
        }
        // cacheMiss인 경우
        else{
            // cache의 맨뒤에 cities가 오게 갱신하고 
            cache.push_back(cities[i]);
            // 현재 cache의 크기가 cache의 최대크기를 넘었을 때는
            // 맨 앞에 있는 cities를 삭제한다. (가장 오래된 cache 삭제)
            if(cache.size() > cacheSize)
                cache.erase(cache.begin());
            answer += 5;
        }
    }

    return answer;
}