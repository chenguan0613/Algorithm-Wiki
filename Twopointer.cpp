#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    vector<string> res;
    while(n--){
        string s; cin>>s;
        int left=0,right=s.length()-1;
        bool check=true;
        while(left<=right){
            if(s[left++]!=s[right--]){
                check=false;
                break;
            }
        }
        if(check) res.push_back("yes");
        else res.push_back("no");
    }
    for(string ans:res){
        cout<<ans<<endl;
    }
    return 0;
}