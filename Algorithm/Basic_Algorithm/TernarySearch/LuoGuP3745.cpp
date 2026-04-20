#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll A,B,C,n,m;
vector<ll> wish_time,plan_time;
ll S(ll x){
    ll res=0;
    for(auto time : wish_time){
        if(time>=x) continue;
        res+=(x-time)*C;
    }
    return res;
}
ll T(ll x){
    ll res=0;
    ll S1=0,S2=0;
    for(auto time: plan_time){
        if(time>x){
            S1+=time-x;
        }
        else{
            S2+=x-time;
        }
    }
    if(A>=B){
        return B*S1;
    }
    else{
        if(S2>=S1){
            return S1*A;
        }
        else{
            return S2*A+(S1-S2)*B;
        }
    }
}
ll F(ll x){
    return S(x)+T(x);
}
int main(){
    cin>>A>>B>>C;
    cin>>n>>m;
    wish_time.resize(n);
    plan_time.resize(m);
    ll max_plan=0;
    for(ll i=0;i<n;i++){
        cin>>wish_time[i];
    }
    for(ll i=0;i<m;i++){
        cin>>plan_time[i];
        max_plan=max(max_plan,plan_time[i]);
    }
    ll lower_bound=0,upper_bound=max_plan;
    while(upper_bound-lower_bound>2){
        ll m1=lower_bound+(upper_bound-lower_bound)/3;
        ll m2=upper_bound-(upper_bound-lower_bound)/3;
        if(F(m1)<F(m2)){
            upper_bound=m2;
        }
        else{
            lower_bound=m1;
        }
    }
    ll res=F(lower_bound);
    for(ll i=lower_bound+1;i<=upper_bound;i++){
        res=min(res,F(i));
    }
    cout<<res;
    return 0;
}