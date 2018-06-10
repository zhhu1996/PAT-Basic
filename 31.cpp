#include<iostream>
using namespace std;
//每一位数字与对应的权重加权求和后对11取余
int main()
{
    int sum,i,j,n,cnt,base[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char s[20],M[] = {'1','0','X','9','8','7','6','5','4','3','2'};
    cin>>n;
    cnt = 0;
    for( i=0; i<n; i++ )
    {
        sum = 0;
        cin>>s;
        for( j=0; j<17; j++ )
        {
            if( s[j]>='0'&&s[j]<='9' ) sum += (s[j]-'0')*base[j];
            else break;
        }
        if( j!=17 ){
            cout<<s<<endl; cnt++;
        }
        else if( s[17]!=M[sum%11] ){
            cout<<s<<endl; cnt++;
        }
    }
    if( !cnt )
        cout<<"All passed"<<endl;

}
