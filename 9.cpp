/*
cin.getline(str, len);
第一个参数str是用来存储输入行的数组名称，第二个参数len是要读取的字符数。
cin.get(str, len);
getline将丢弃换行符，而get()将换行符保留在输入序列里。
所以，再使用cin.get()输入多行数据时，中间可以使用get()消除换行符。
*/
#include<iostream>
using namespace std;
//可以利用cin读到空格停止的特性将单词直接存入数组中
//也可以getline读入所有字符，然后记录下其中空格的位置，反序输出
int main()
{
    char s[100][88];
    int i;
    i=0;
    while( cin>>s[i] ){
        i++;
    }
    i--;
    while( i>=0 ){
        cout<<s[i];
        if( i ) cout<<" ";
        i--;
    }
}
