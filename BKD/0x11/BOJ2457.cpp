#include<bits/stdc++.h>
using namespace std;
#define bloom first
#define fall second

pair<int, int> flower[100005];

bool cmp(const pair<int, int> &a,const pair<int, int> &b){
    if(a.bloom != b.bloom){
        return a.bloom < b.bloom;
    }
    else{
        return a.fall > b.fall;
    }
}

// 조건 : 3월 1일에 지는 꽃 && 12월 1일에 피는 꽃 제외
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int bloomM;
        int bloomD;
        int fallM;
        int fallD;
        cin >> bloomM >> bloomD >> fallM >> fallD;

        flower[i].bloom = bloomM * 100 + bloomD;
        flower[i].fall = fallM * 100 + fallD;
    }

    sort(flower, flower+n, cmp);

    int endDay = 1201;
    int start = 301;
    int count = 0;
    int max = 0;
    int index = 0;
    
    while(start < endDay) {
        bool isFinded = false;	
        
        for(int i = index; i < n; i++) {
            if(flower[i].bloom > start) {	
                break;
            }
            
            if(max < flower[i].fall) {
                isFinded = true;
                max = flower[i].fall;
                index = i + 1;
            }
        }
        
        if(isFinded) {
            start = max;
            count++;
        }
        else {
            break;
        }
    }  

    if(max < endDay) {
        cout << 0;
    }
    else {
        cout << count;
    }

}