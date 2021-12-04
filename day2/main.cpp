#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("file.txt");
char s[25];
int x, p1, p2, p3;
int main()
{
    while(fin.getline(s, 25))
    {
        if(s[0]=='f')
            p1+=(int)(s[8]-'0'), p2+=p3*(int)(s[8]-'0');
        else if(s[0]=='u')
            p3-=(int)(s[3]-'0');
        else if(s[0]=='d')
            p3+=(int)(s[5]-'0');
    }
    cout << p1 << " " << p2 << "\n";
    cout << p1*p2;
    return 0;
}
