#include<bits/stdc++.h>
using namespace std;

vector<string> ToJava(string s, string sep){
    vector<string> ret;
    int pos = 0;
    while(pos < s.size()){
        int nxt_pos = s.find(sep, pos);
        if(nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0){
            string tmp = s.substr(pos, nxt_pos - pos);
            if(pos != 0) tmp[0] = tmp[0] - 'a' + 'A';
            ret.push_back(tmp);
        }
        pos = nxt_pos + sep.size();
    }
    return ret;
}

void ToCpp(string& s){
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < 'a') {
			s.insert(i, "_");
			s[i+1] += ('a' - 'A');
			i++;
		}
	}	
}

// flag = 0 : 전부 소문자 flag = 1 : ToJava flag = 2 : ToC++ 
int flag;
vector<string> trans;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);


    string str;
    cin >> str;

    // 1. 첫 단어가 소문자가 아닌경우
    if(str[0] < 'a' || str[0] > 'z'){
        cout << "Error!";
        return 0;
    }
    // 2. 마지막 단어가 _인 경우
    else if(str[str.size() - 1] == '_'){
        cout << "Error!";
        return 0;
    }
    
    int underbarcnt = 0;
    for(auto x : str){
        if(x == '_'){
            underbarcnt++;
            // 3. _가 연속으로 나오는 경우
            if(underbarcnt > 1){
                cout << "Error!";
                return 0;
            }
            // 4. 대문자와 _가 혼합되어서 나오는 경우
            if(flag == 2){
                cout << "Error!";
                return 0;
            }
            flag = 1;
        }
        else if(x >= 'A' && x <= 'Z'){
            // 4. 대문자와 _가 혼합되어서 나오는 경우
            if(flag == 1){
                cout << "Error!";
                return 0;
            }
            flag = 2;
        }

        if(x != '_') underbarcnt = 0;
    }



    if(flag == 0){
        cout << str;
    }
    if(flag == 1){
        trans = ToJava(str, "_");
        for(auto x : trans){
            cout << x;
        }
    }
    else if(flag == 2){
        ToCpp(str);
        cout << str;
    }
}