#include<iostream>
using namespace std;
//过滤掉这六个字母以外的字符   只要有字符个数不为0那么就继续输出
int main()
{
    char str[10086],c[6]={'P','A','T','e','s','t'};
    int character[6]={0};
    cin>>str;
    for( int i=0; str[i]; i++ ){
        switch(str[i]){
        case 'P': character[0]++; break;
        case 'A': character[1]++; break;
        case 'T': character[2]++; break;
        case 'e': character[3]++; break;
        case 's': character[4]++; break;
        case 't': character[5]++; break;
        default: break;
        }
    }
    while( character[0]||character[1]||character[2]||character[3]||character[4]||character[5] ){
        for( int i=0; i<6; i++ ){
            if( character[i] ){
                cout<<c[i]; character[i]--;
            }
        }
    }

}
