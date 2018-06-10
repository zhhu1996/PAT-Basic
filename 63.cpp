#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int n,a[10008][2];
    double maxt,t;
    cin>>n;
    maxt = t = 0.0;
    for( int i=0; i<n; i++ ){
        for( int j=0; j<2; j++ )
            cin>>a[i][j];
        t = sqrt(1.0*(a[i][0]*a[i][0]+a[i][1]*a[i][1]));
        if( maxt<t ) maxt = t;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<maxt;
}
