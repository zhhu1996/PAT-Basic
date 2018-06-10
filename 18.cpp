#include<iostream>
using namespace std;
//1代表平局   //0代表胜   //2代表负
//只需要设一个表示甲战况的数组就可以根据对称性得到乙的战况
//不过输出胜率最大的字符还是需要另开一个二维数组记录的
//最后比较字母序大小可以根据下标映射到字符数组
int main()
{
    int wincnt[3],shape[2][3];
    int n;
    char c1,c2;
    char s[3]={'C','J','B'};
    cin>>n;
    for( int i=0; i<3; i++ ){
        wincnt[i] = 0;
    }
    for( int i=0; i<2; i++ )
        for( int j=0; j<3; j++ )
            shape[i][j] = 0;
    for( int i=0; i<n; i++ ){
        cin>>c1>>c2;
        if( c1=='C'&&c2=='C')   wincnt[1]++;
        if( c1=='C'&&c2=='J') { wincnt[0]++; shape[0][0]++; }
        if( c1=='C'&&c2=='B') { wincnt[2]++; shape[1][2]++; }
        if( c1=='J'&&c2=='C') { wincnt[2]++; shape[1][0]++; }
        if( c1=='J'&&c2=='J')   wincnt[1]++;
        if( c1=='J'&&c2=='B') { wincnt[0]++; shape[0][1]++; }
        if( c1=='B'&&c2=='C') { wincnt[0]++; shape[0][2]++; }
        if( c1=='B'&&c2=='J') { wincnt[2]++; shape[1][1]++; }
        if( c1=='B'&&c2=='B')   wincnt[1]++;
    }
    cout<<wincnt[0]<<" "<<wincnt[1]<<" "<<wincnt[2]<<endl;
    cout<<wincnt[2]<<" "<<wincnt[1]<<" "<<wincnt[0]<<endl;
    for( int i=0; i<2; i++ ){
        int maxs = 0;
        for( int j=0; j<3; j++ )
            if( shape[i][maxs]<shape[i][j] )
                maxs = j;
            else if( shape[i][maxs]==shape[i][j]&& s[maxs]>s[j] )
                maxs = j;
        if( i ) cout<<" ";
        cout<<s[maxs];
    }


}
