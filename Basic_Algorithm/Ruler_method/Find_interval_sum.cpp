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
    int left=0,right=0,sum=nums[0];
    while(right<nums.size()){
        if(sum>target){
            sum-=nums[left++];
            //important
            if(left>right && left<nums.size()){
                sum=nums[left];
                right=left;
            }
        }
        else if(sum<target){
            right++;
            if(right<nums.size()){
                sum+=nums[right];
            }
        }
        else{
            cout<<"From "<<left<<" To "<<right<<endl;
            right++;
            if(right<nums.size()){
                sum+=nums[right];
            }
        }
    }
    return 0;
}