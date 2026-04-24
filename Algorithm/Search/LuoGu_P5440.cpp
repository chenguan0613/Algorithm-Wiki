#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> primes;
bool is_prime(int x){
    if(x<2) return false;
    int day=x%100,month=x/100;
    if(!(day>0 && day<=31)) return false;
    if(!(month>0 && month<=12)) return false;
    if(!(day==1 || day==3 || day==5 || day==7 || day==11 || day==13 || day==17 || day==19 || day==23 || day==29 || day==31)) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
void generate_primes(){
    for(int i=0;i<=9999;i++){
        if(is_prime(i)){
            string s=to_string(i);
            while(s.size()<4) s='0'+s;
            primes.push_back(s);
        }
    }
}

int main(){

    return 0;
}