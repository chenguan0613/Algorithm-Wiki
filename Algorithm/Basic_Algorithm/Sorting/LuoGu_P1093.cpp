#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    vector<vector<int>> nums(n, vector<int>(5));
    for(int i=0; i<n; i++){
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
        nums[i][3] = nums[i][0]+nums[i][1]+nums[i][2];
        nums[i][4] = i+1;
    }
    sort(nums.begin(),nums.end(),[](const vector<int>& a, const vector<int>& b){
        if(a[3]!=b[3]) return a[3]>b[3];
        else if(a[0]!=b[0]) return a[0]>b[0];
        else return a[4]<b[4];
    });
    for(int i=0; i<5; i++){
        cout<<nums[i][4]<<" "<<nums[i][3]<<endl;
    }
    return 0;
}