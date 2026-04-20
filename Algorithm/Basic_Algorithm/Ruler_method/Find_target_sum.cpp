#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    vector<int> nums;
    while(n--){
        int num; cin>>num;
        nums.push_back(num);
    }
    int target; cin>>target;
    sort(nums.begin(),nums.end());
    int left=0,right=nums.size()-1;
    while(left<right){
        int sum=nums[left]+nums[right];
        if(sum>target){
            right--;
        }
        else if(sum<target){
            left++;
        }
        else{
            cout<<nums[left]<<"+"<<nums[right]<<"="<<target<<endl;
            right--;
            left++;
        }
    }
    return 0;
}