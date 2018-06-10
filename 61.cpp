#include<iostream>
using namespace std;
int main()
{
    int n,m,perscore[100],right[100],test[100],sum[100]={0};
    cin>>n>>m;
    for( int i=0; i<m; i++ )
        cin>>perscore[i];
    for( int i=0; i<m; i++ )
        cin>>right[i];
    for( int i=0; i<n; i++ ){
        for( int j=0; j<m; j++ ){
            cin>>test[j];
            if( test[j]==right[j] ) sum[i] += perscore[j];
        }
        cout<<sum[i]<<endl;
    }
}
