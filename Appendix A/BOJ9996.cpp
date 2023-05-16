#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string pattern;
    cin >> n >> pattern;
    int staridx = pattern.find('*');
    string front = pattern.substr(0, staridx);
    string rear = pattern.substr(staridx + 1, pattern.size() - staridx);

    while(n--){
        string file;
        cin >> file;

        if(front.size() + rear.size() > file.size()){
            cout << "NE" << '\n';
            continue;
        }

        // file.find(front)의 결과가 0번째 위치를 반환하지 않으면 패턴과 일치하지 않음
        if(file.find(front) != 0){
            cout << "NE" << '\n';
            continue;
        }

        // file.find(rear)를 뒤에서부터 rear의 길이 만큼 뺀 위치부터 
        // 수행 했을 때 찾지 못하면 패턴과 일치하지 않음
        if((file.find(rear, file.size() - rear.size()) == -1)){
            cout << "NE" << '\n';
            continue;
        }
        
        cout << "DA" << '\n';
    }
}