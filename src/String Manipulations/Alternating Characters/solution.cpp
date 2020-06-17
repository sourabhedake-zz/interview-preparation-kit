#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        int cnt=0;
        int start=0;
        if(s[0]=='B') start=1;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='A' && start==0) cnt++;
            else if(s[i] == 'A' && start==1) start=0;
            else if(s[i] == 'B' && start==0) start=1;
            else cnt++;
        }
        cout<<cnt<<endl;
            
    }
    return 0;
}
