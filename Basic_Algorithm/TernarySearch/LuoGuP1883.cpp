#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double f(double x, int a, int b, int c){
    return a*x*x+b*x+c;
}
double get_max(const vector<vector<int>>& functions, double x){
    double res=-1e9;
    for(auto& function:functions){
        res=max(res,f(x,function[0],function[1],function[2]));
    }
    return res;
}
int main(){
    int T; cin>>T;
    vector<double> res;
    while(T--){
        int n; cin>>n;
        vector<vector<int>> functions(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>functions[i][0]>>functions[i][1]>>functions[i][2];
        }
        double lower_bound=0.0,upper_bound=1000.0;
        for(int i=0;i<100;i++){
            double mid1=lower_bound+(upper_bound-lower_bound)/3.0;
            double mid2=upper_bound-(upper_bound-lower_bound)/3.0;
            if(get_max(functions,mid1)<get_max(functions,mid2)){
                upper_bound=mid2;
            }
            else{
                lower_bound=mid1;
            }
        }
        res.push_back(get_max(functions,lower_bound));
    }
    for(auto num: res){
        cout<<fixed<<setprecision(4)<<num<<endl;
    }
    return 0;
}