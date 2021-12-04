#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("file.txt");
char s[25];
int a[25], l;
int main()
{
    while(fin.getline(s, 25))
    {
        l=strlen(s);
        for(int i=0; i<l; i++)
            if(s[i]=='0')
                a[i]-=1;
            else
                a[i]+=1;
    }

    for(int i=0; i<l; i++)
        if(a[i]<0)
            s[i] = '0';
        else
            s[i] = '1';

    int gamma=0, epsilon=0, p=1;
    for(int i=l-1; i>=0; i--)
    {
        if(s[i]=='1')
            gamma += p;
        else
            epsilon += p;
        p = p*2;
    }
    cout << gamma * epsilon;

    return 0;
}
