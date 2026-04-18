#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//LuoGuP3382
int N;
vector<double> a;
double f(double x){
    double s=0.0;
    //从后向前还原这个多项式函数
    for(int i=N;i>=0;i--){
        s=s*x+a[i];
    }
    return s;
}
int main(){
    double left,right;
    cin>>N>>left>>right;
    a.resize(N+1);
    for(int i=N;i>=0;i--){
        cin>>a[i];
    }
    while(right-left>1e-6){
        double k=(right-left)/3.0;
        double mid1=left+k;
        double mid2=right-k;
        if(f(mid1)>f(mid2)){
            right=mid2;
        }
        else{
            left=mid1;
        }
    }
    cout<<fixed<<setprecision(5)<<left;
    return 0;
}