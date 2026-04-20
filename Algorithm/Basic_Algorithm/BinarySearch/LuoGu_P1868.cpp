#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct interval{
    int x;
    int y;
    int len;
};
bool cmp(const interval& a,const interval& b){
    if(a.y!=b.y){
        return a.y<b.y;
    }
    return a.x<b.x;
}
int main(){
    int N; cin>>N;
    vector<interval> intervals(N);
    for(int i=0;i<N;i++){
        cin>>intervals[i].x>>intervals[i].y;
        intervals[i].len=intervals[i].y-intervals[i].x+1;
    }
    sort(intervals.begin(),intervals.end(),cmp);
    vector<int> ends(N,0);
    for(int i=0;i<N;i++){
        ends[i]=intervals[i].y;
    }
    vector<int> dp(N,0);
    dp[0]=intervals[0].len;
    for(int i=1;i<N;i++){
        int current_start=intervals[i].x;
        int current_len=intervals[i].len;
        auto pos=lower_bound(ends.begin(),ends.begin()+i,current_start);
        int index=pos-ends.begin();
        int j=index-1;
        int take_profit=current_len;
        if(j >= 0){
            take_profit+=dp[j];
        }
        dp[i]=max(dp[i - 1], take_profit);
    }
    cout <<dp[N-1]<< "\n";
    return 0;
}