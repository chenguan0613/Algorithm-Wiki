#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    vector<int> res;
    while(n--){
        int N; cin>>N;
        int S; cin>>S;
        int nums[N],presum[N+1];
        presum[0]=0;
        for(int i=0;i<N;i++){
            cin>>nums[i];
        }
        for(int i=1;i<=N;i++){
            presum[i]=nums[i-1]+presum[i-1];
        }
        int left=0,right=1,len=INT_MAX;
        while(right<=N){
            int sum=presum[right]-presum[left];
            if(sum<S){
                right++;
            }
            else if(sum>S){
                len=min(len,right-left);
                left++;
            }
            else{
                len=min(len,right-left);
                right++;
                left++;
            }
        }
        res.push_back(len==INT_MAX ? 0 : len);
    }
    for(auto item : res){
        cout<<item<<endl;
    }
    return 0;
}