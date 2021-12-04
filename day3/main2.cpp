#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("file.txt");
char s[1001], a[1001][1001], a1[1001][1001], a2[1001][1001];
int n, poz, m;
int main()
{
    while(fin.getline(s, 25))
        strcpy(a[n++], s);

    int l=strlen(a[0]);
    for(int i=0; i<n; i++)
        strcpy(a1[i], a[i]);

    m=n;
    for(int poz=0; poz<l; poz++)
    {
        int numberOf1 = 0, numberOf0 = 0;
        for(int i=0; i<m; i++)
        {
            if(a1[i][poz]=='1')
                numberOf1++;
            else
                numberOf0++;


            if(i==m-1)
            {
                int m2 = 0;
                if(numberOf0 > numberOf1)
                {
                    for(int j=0; j<m; j++)
                        if(a1[j][poz] == '0')
                            strcpy(a2[m2++], a1[j]);
                }
                else
                {
                    for(int j=0; j<m; j++)
                        if(a1[j][poz] == '1')
                            strcpy(a2[m2++], a1[j]);
                }
                m=m2;
                for(int i=0; i<m; i++)
                    strcpy(a1[i], a2[i]);
            }
        }
    }
    int generatorRating = 0, p=1;
    for(int i=strlen(a1[0])-1; i>=0; i--)
        generatorRating += (int)(a1[0][i]-'0')*p, p *= 2;



    for(int i=0; i<n; i++)
        strcpy(a1[i], a[i]);

    m=n;
    for(int poz=0; poz<l; poz++)
    {
        int numberOf1 = 0, numberOf0 = 0;
        for(int i=0; i<m; i++)
        {
            if(a1[i][poz]=='1')
                numberOf1++;
            else
                numberOf0++;


            if(i==m-1)
            {
                int m2 = 0;
                if(numberOf0 <= numberOf1)
                {
                    for(int j=0; j<m; j++)
                        if(a1[j][poz] == '0')
                            strcpy(a2[m2++], a1[j]);
                }
                else
                {
                    for(int j=0; j<m; j++)
                        if(a1[j][poz] == '1')
                            strcpy(a2[m2++], a1[j]);
                }
                m=m2;
                for(int i=0; i<m; i++)
                    strcpy(a1[i], a2[i]);
            }
        }
    }
    int scrubberRating = 0;
    p=1;
    for(int i=strlen(a1[0])-1; i>=0; i--)
        scrubberRating += (int)(a1[0][i]-'0')*p, p *= 2;
    cout << scrubberRating * generatorRating;
    return 0;
}
