#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<ll> room;
struct Order{
    ll d;
    int s;
    int t;
};
vector<Order> orders;
bool check(int mid){
    vector<ll> diff(n+1,0);
    for(int i=0;i<mid;i++){
        diff[orders[i].s-1]+=orders[i].d;
        diff[orders[i].t]-=orders[i].d;
    }
    ll current_book=0;
    for(int i=0;i<n;i++){
        current_book+=diff[i];
        if(current_book>room[i]){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    room.resize(n);
    for(int i=0;i<n;i++){
        cin>>room[i];
    }
    orders.resize(m);
    for(int i=0;i<m;i++){
        cin>>orders[i].d>>orders[i].s>>orders[i].t;
    }
    int lower_bound=0,upper_bound=m;
    int ans=0;
    if(check(m)){
        cout<<0;
        return 0;
    }
    while(lower_bound<=upper_bound){
        int mid=lower_bound+(upper_bound-lower_bound)/2;
        if(check(mid)){
            lower_bound=mid+1;
        }
        else{
            ans=mid;
            upper_bound=mid-1;
        }
    }
    cout<<-1<<endl<<ans;
    return 0;
}