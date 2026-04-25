#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> primes;
vector<int> small_primes;
int ans=0;
void init_small_primes() {
    for (int i = 2; i <= 10000; i++) {
        bool is_p = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_p = false;
                break;
            }
        }
        if (is_p) {
            small_primes.push_back(i);
        }
    }
}
bool is_prime(int x){
    if(x<2) return false;
    for(int p : small_primes){
        if(p*p>x) break;
        if(x%p==0) return false;
    }
    return true;
}
vector<int> days={0,31,29,31,30,31,30,31,31,30,31,30,31};
void generate_primes(){
    for(int m=1;m<=12;m++){
        for(int d=1;d<=days[m];d++){
            int mmdd=m*100+d;
            if(is_prime(mmdd) && is_prime(d)){
                string s=to_string(mmdd);
                if(s.size()==3) s="0"+s;
                primes.push_back(s);
            }
        }
    }
}
bool match_mmdd(const string& entered, const string& generated){
    for(int i=0;i<4;i++){
        if(entered[i+4]!='-' && entered[i+4]!=generated[i]) return false;
    }
    return true;
}
bool is_leap_year(int year){
    return (year%4==0 && year%100!=0) || (year%400==0);
}
void dfs(int index,int current_year,const string& entered, const string& generated){
    if(index==4){
        if(current_year==0) return;
        int month=(generated[0]-'0')*10+(generated[1]-'0');
        int day=(generated[2]-'0')*10+(generated[3]-'0');
        if(month==2 && day==29 && !is_leap_year(current_year)) return;
        int full_date=current_year*10000 + month*100 + day;
        if(is_prime(full_date)){
            ans++;
        }
        return;
    }
    if(entered[index]!='-'){
        dfs(index+1,current_year*10 + (entered[index]-'0'),entered,generated);
    }
    else{
        for(int digit=0;digit<=9;digit++){
            dfs(index+1,current_year*10 + digit,entered,generated);
        }
    }
}

int main(){
    int n; cin>>n;
    vector<int> res;
    init_small_primes();
    generate_primes();
    while(n--){
        ans=0;
        string entered;
        cin>>entered;
        for(const string& prime: primes){
            if(match_mmdd(entered,prime)){
                dfs(0,0,entered,prime);
            }
        }
        res.push_back(ans);
    }
    for(int count: res){
        cout<<count<<endl;
    }
    return 0;
}