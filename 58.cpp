#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
主要就是判断对错的函数难写。
每次都找到'('的位置
然后根据正确答案的长度将输入的数组复制到另外一个数组，
通过基于长度的字符串比较函数比较两个字符数组，计算得分。
基本上包括了重要的字符串函数，很锻炼基础的一道题
*/
struct wr{
    int it;
    int cnt;
}wrongcnt[100];
bool cmp( wr w1, wr w2 )
{
    bool ret;
    if( w1.cnt!=w2.cnt ) ret = w1.cnt>w2.cnt;
    else ret = w1.it<w2.it;
    return ret;
}
int main()
{
    int maxs,maxi,n,m,perscore[100]={0},choose[100]={0},sum[1000]={0};
    char rc[100][13],sc[1000],test[20];
    cin>>n>>m;
    for( int i=0; i<m; i++ ){
        cin>>perscore[i]>>choose[i];
        cin.get();
        cin.getline(rc[i],13);
    }
    char *p = sc;
    for( int i=0; i<n; i++ ){
        cin.getline(sc,1000);
        int k = 0, pt = 0;
        p = sc;
		while( k<m ){
        	p = strchr(p,'(');
        	strncpy(test,p+1,strlen(rc[k]));
        	//test[strlen(rc[k])] = '\0';
			if( strncmp(rc[k],test,strlen(rc[k]))==0 )
        	   sum[i] += perscore[k];
        	else{
				wrongcnt[k].it = k; wrongcnt[k].cnt++;
			}

        	p++; k++;
		}

    }
    sort(wrongcnt,wrongcnt+m,cmp);
    for( int i=0; i<n; i++ )
    	cout<<sum[i]<<endl;
    if( wrongcnt[0].cnt )
    {
        cout<<wrongcnt[0].cnt;
        for( int i=0; i<m; i++ ){
            if( wrongcnt[i].cnt==wrongcnt[0].cnt )
                cout<<" "<<wrongcnt[i].it+1;
        }
    }
    else
        cout<<"Too simple"<<endl;
}
