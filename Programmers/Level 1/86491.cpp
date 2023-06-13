#include<bits/stdc++.h>
using namespace std;

//해설 및 증명 참고 사이트 : https://readable-ko.site/168
int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int maxlen = 0;
    int minlen = 0;
    for(int i = 0; i < sizes.size(); i++){
        // w는 각 명함의 길이 중 긴 쪽으로
        // h는 각 명함의 길이 중 짧은 쪽으로
        int w = max(sizes[i][0], sizes[i][1]);
        int h = min(sizes[i][0], sizes[i][1]);

        // 긴 쪽의 최고 값, 짧은 쪽의 최고 값
        maxlen = max(w, maxlen);
        minlen = max(h, minlen);
    }

    answer = maxlen * minlen;
    return answer;
}