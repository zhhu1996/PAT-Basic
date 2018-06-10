#include<iostream>
#include<cstring>
/*数组大小>10^5*/
using namespace std;
int main()
{
    char s[100100];
    int sum,cnt[2]={0};
    sum = 0;
    cin.getline(s,100100);
    for( int i=0; s[i]; i++ ){
        if( s[i]>='a'&&s[i]<='z' ) sum += s[i]-'a'+1;
        else if( s[i]>='A'&&s[i]<='Z' ) sum += s[i]-'A'+1;
    }
    while( sum ){
        cnt[sum%2]++;
        sum /= 2;
    }
    cout<<cnt[0]<<" "<<cnt[1];
}
