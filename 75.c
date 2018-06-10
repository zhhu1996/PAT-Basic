#include<stdio.h>
struct linkNode{
    int addr;
    int data;
    int next;
}LNode[100086],LN1[100086],LN2[100086],LN3[100086];

int main()
{
    int faddr,n,k,p1,p2,p3;
    int taddr,tdata,tnext;
    scanf("%d %d %d",&faddr,&n,&k);
    p1 = p2 = p3 = 0;
    for( int i=0; i<n; i++ ){
        scanf("%d %d %d",&taddr,&tdata,&tnext);
        LNode[taddr].data = tdata;
        LNode[taddr].addr = taddr;
        LNode[taddr].next = tnext;
    }
    while( faddr!=-1 ){
        if( LNode[faddr].data<0 )
        {
            LN1[p1].addr = faddr;
            LN1[p1].data = LNode[faddr].data;
            LN1[p1].next = LNode[faddr].next;
            if( p1>0 ) LN1[p1-1].next = LN1[p1].addr;
            //printf("%d %d\n",LN1[p1-1].addr,LN1[p1].addr);
            p1++;
        }
        else if( LNode[faddr].data>=0 && LNode[faddr].data<=k ){
            LN2[p2].addr = faddr;
            LN2[p2].data = LNode[faddr].data;
            LN2[p2].next = LNode[faddr].next;
            if( p2>0 ) LN2[p2-1].next = LN2[p2].addr;
            //printf("%d %d\n",LN2[p2-1].addr,LN2[p2].addr);
            p2++;
        }
        else{
            LN3[p3].addr = faddr;
            LN3[p3].data = LNode[faddr].data;
            LN3[p3].next = LNode[faddr].next;
            if( p3>0 ) LN3[p3-1].next = LN3[p3].addr;
            //printf("%d %d\n",LN3[p3-1].addr,LN3[p3].addr);
            p3++;
        }
        faddr = LNode[faddr].next;
    }
    if( p1>0 ) LN1[p1-1].next = LN2[0].addr;
    if( p2>0 ) LN2[p2-1].next = LN3[0].addr;
    if( p3>0 ) LN3[p3-1].next = -1;
    for( int i=0; i<p1; i++ )
        printf("%05d %d %05d\n",LN1[i].addr,LN1[i].data,LN1[i].next);
    for( int i=0; i<p2; i++ )
        printf("%05d %d %05d\n",LN2[i].addr,LN2[i].data,LN2[i].next);
    for( int i=0; i<p3-1; i++ )
        printf("%05d %d %05d\n",LN3[i].addr,LN3[i].data,LN3[i].next);
    if( p3>0 )
        printf("%05d %d %d\n",LN3[p3-1].addr,LN3[p3-1].data,LN3[p3-1].next);
}
