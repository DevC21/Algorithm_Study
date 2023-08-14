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

        // ���� �Է¹��� ��� cities�� ������ cache ũ�⺸�� ���� ���
        if(cache.size() < cacheSize){
            for(int j = 0; j < cache.size(); j++){
                if(cache[j] == cities[i]){
                    cacheHit = true;
                    idx = j;
                    break;
                }
            }
        }
        // ���� �Է¹��� ��� cities�� ������ cache ũ�⺸�� ���� ���
        else{
            for(int j = 0; j < cacheSize; j++){
                if(cache[j] == cities[i]){
                    cacheHit = true;
                    idx = j;
                    break;
                }
            }
        }

        // cacheHit�� ���
        if(cacheHit){
            // cache�� �ǵڿ� cities�� ���� �����ϰ� 
            cache.push_back(cities[i]);
            // ���� cities�� �ִ� �ڸ����� �����Ѵ�.
            cache.erase(cache.begin() + idx);
            answer += 1;
        }
        // cacheMiss�� ���
        else{
            // cache�� �ǵڿ� cities�� ���� �����ϰ� 
            cache.push_back(cities[i]);
            // ���� cache�� ũ�Ⱑ cache�� �ִ�ũ�⸦ �Ѿ��� ����
            // �� �տ� �ִ� cities�� �����Ѵ�. (���� ������ cache ����)
            if(cache.size() > cacheSize)
                cache.erase(cache.begin());
            answer += 5;
        }
    }

    return answer;
}