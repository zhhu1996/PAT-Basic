#include<iostream>
using namespace std;
//cin.getline读取字符串  并且只要求输出小写字母
int main()
{
    char m,s[1024];
    int maxcnt,cnt[128]={0};
    cin.getline(s,1024);
    m = 'a'; maxcnt = 0;
    for( int i=0; s[i]; i++ ){
        if( s[i]>='A'&&s[i]<='Z' ) s[i] += 32;
        if( s[i]>='a'&&s[i]<='z' ){
            cnt[int(s[i])]++;
            if( maxcnt<cnt[int(s[i])] ){
                maxcnt = cnt[int(s[i])]; m = s[i];
            }
            else if( maxcnt==cnt[int(s[i])]&&m>s[i] ){
                m = s[i];
            }
        }
        //cnt[int(s[i])]++;
    }
    cout<<m<<" "<<maxcnt;
}
