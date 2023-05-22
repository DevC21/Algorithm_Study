#include<bits/stdc++.h>
#include <sstream>
using namespace std;

bool errorflag;
bool reverseflag;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    int n;

    string p, arr;
    
    cin >> t;

    for(int i = 0; i < t; i++){
        deque<int> DQ;
        errorflag = false;
        reverseflag = false;

        cin >> p;
        cin >> n;

        cin >> arr;
        if(arr.length() > 2){
            arr = arr.substr(1, arr.length()-2);
            istringstream ss(arr);
            string num;
            int ssnum;

            while(getline(ss, num, ',')){
                stringstream ssInt(num);
                ssInt >> ssnum;
                DQ.push_back(ssnum);
            }
        }


        for(char c : p){
            if( c == 'R'){
                if(reverseflag != true)
                    reverseflag = true;
                else
                    reverseflag = false;
            }
            else if( c == 'D'){
                if(DQ.empty()){
                    errorflag = true;
                }
                else if(reverseflag != true){
                    DQ.pop_front();
                    n--;
                }
                else if(reverseflag == true){
                    DQ.pop_back();
                    n--;
                }
            }
        }

        if(!errorflag){
            std::cout << '[';
            for(int j = 0; j < n; j++){
                if(reverseflag != true){
                    if(j == n-1){
                        std::cout << DQ.front();
                        DQ.pop_front();
                    }
                    else{
                        std::cout << DQ.front() << ',';
                        DQ.pop_front();
                    }
                }
                else{
                    if(j == n-1){
                        std::cout << DQ.back();
                        DQ.pop_back();
                    }
                    else{
                        std::cout << DQ.back() << ',';
                        DQ.pop_back();
                    }
                }
            }
            std::cout << ']' << '\n';
        }
        else{
            std::cout << "error" << '\n';
        }
    }
}