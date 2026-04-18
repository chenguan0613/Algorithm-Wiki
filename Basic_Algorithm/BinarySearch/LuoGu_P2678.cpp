#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int M,N;
ll L;
vector<ll> position;
bool check(int mid){
    int current_position=0, remove_count=0;
    for(ll pos:position){
        if(pos-current_position<mid){
            remove_count++;
            continue;
        }
        current_position=pos;
    }
    return remove_count<=M;
}
int main(){
    cin>>L>>N>>M;
    for(int i=0;i<N;i++){
        ll pos; cin>>pos;
        position.push_back(pos);
    }
    position.push_back(L);
    ll lower_bound=1,upper_bound=L;
    ll ans=upper_bound;
    while(lower_bound<=upper_bound){
        ll mid=lower_bound+(upper_bound-lower_bound)/2;
        if(check(mid)){
            ans=mid;
            lower_bound=mid+1;
        }
        else{
            upper_bound=mid-1;
        }
    }
    cout<<ans;
    return 0;
}