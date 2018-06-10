#include<iostream>
using namespace std;
//最后一行没有空格
int main()
{
    int col,row;
    char c;
    cin>>col>>c;
    row = int(1.0*col/2+0.5);
    for( int i=1; i<=row; i++ ){
        for( int j=1; j<=col; j++ )
        {
            if( i==1||i==row )
                cout<<c;
            else{
                if( j==1||j==col )
                    cout<<c;
                else
                    cout<<" ";
            }
        }
        if( i!=row ) cout<<endl;
    }
}
