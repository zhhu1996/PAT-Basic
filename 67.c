#include<stdio.h>
#include<string.h>
//有一个测试点始终过不了
int main()
{
    char r[24],t[1000];
    int n,i,cnt;
    scanf("%s %d\n",r,&n);
    i = cnt= 0;
    while(1)
    {
        gets(t);
        if( strcmp(t,"#") ) i++;
        else break;
        if( i<=n&&(!strcmp(r,t)) ){
            printf("Welcome in"); break;
        }
        else if( i<=n&&strcmp(r,t) ){
            printf("Wrong password: %s\n",t);
        if( i==n ){
            printf("Account locked"); break;
            }
        }
    }
    return 0;
}
/*通过版本
#include <iostream>
using namespace std;
int main() {
    string password, temp;
    int n, cnt = 0;
    cin >> password >> n;
    getchar();
    while(1) {
        getline(cin, temp);
        if (temp != "#") {
            cnt++;
        } else {
            break;
        }
        if (cnt <= n && temp == password) {
            cout << "Welcome in";
            break;
        } else if (cnt <= n && temp != password) {
            cout << "Wrong password: " << temp << endl;
            if (cnt == n) {
                cout << "Account locked";
                break;
            }
        }
    }
    return 0;
}
*/
