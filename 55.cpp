#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student{
    char name[20];
    int height;
};
bool Cmp(Student s1,Student s2){
    if(s1.height!=s2.height){       //身高不相同，身高矮的在前
        return s1.height<s2.height;
    }
    else return strcmp(s1.name,s2.name)>0;//身高相同，比较名字，字典序大的在前
}
void output(Student s[],int begin,int end){//对每一排进行符合要求的排序并输出
    Student temp[end-begin+2];//注意此处数组的大小
    int m=(end-begin)/2+1;
    int count_left=0;       //左边到了第几个
    int count_right=0;      //右边到了第几个
    bool should_right=false;//是否该右边了
    for(int i=end;i>=begin;i--){
        if(i==end)  temp[m]=s[i];//先把最大值放在中间
        else{
            if(should_right){
                count_right++;
                temp[m+count_right]=s[i];
                should_right=false;
            }
            else{
                count_left--;
                temp[m+count_left]=s[i];
                should_right=true;
            }
        }
    }
    for(int i=m+count_left;i<=m+count_right;i++){
        if(i!=(m+count_left))   cout<<" ";
        cout<<temp[i].name;
    }
    cout<<endl;
}
int main(){
    int N,K;
    Student s[10005];
    cin>>N>>K;
    char name[20];
    int height;
    for(int i=1;i<=N;i++){  //为了每一排排序计算中间值的方便，从1开始
        cin>>s[i].name>>s[i].height;
    }
    sort(s+1,s+N+1,Cmp);
    int last=(K-1)*(N/K)+1;//计算出最后一排开始的元素
    output(s,last,N);
     for(int i=last-N/K;i>=1;i-=N/K)//输出除了最后一排的元素
        output(s,i,i+N/K-1);
    return 0;
}
