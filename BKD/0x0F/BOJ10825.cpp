#include<bits/stdc++.h>
using namespace std;
#define ko get<0>
#define en get<1>
#define math get<2>
#define name get<3>

vector<tuple<int, int, int, string>> student;

bool func_sort(const tuple<int, int, int, string> &a,tuple<int, int, int, string> &b){
    // 국어 점수가 감소하는 순서로 == 국어 점수가 큰 순서
    if(ko(a) != ko(b)){
        return ko(a) > ko(b);
    }
    // 영어 점수가 증가하는 순서로 == 영어 점수가 작은 순서
    else if(en(a) != en(b)){
        return en(a) < en(b);
    }
    // 수학 점수가 감소하는 순서로 == 수학 점수가 큰 순서
    else if(math(a) != math(b)){
        return math(a) > math(b);
    }
    // 사전 순으로 증가하는 순서로 == 이름의 각 알파벳이 먼저 나오는 순서
    return name(a) < name(b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int kor, eng, mat;
        cin >> s >> kor >> eng >> mat;
        student.push_back({kor, eng, mat, s});
    }

    sort(student.begin(), student.end(), func_sort);

    for(int i = 0; i < n; i++){
        cout << name(student[i]) << '\n';
    }

}