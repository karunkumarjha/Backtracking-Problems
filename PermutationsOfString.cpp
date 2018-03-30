#include<bits/stdc++.h>
using namespace std;
void swap(char *ch1, char *ch2)
{
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}
void permute(char *s, int i, int n)
{
    static int counter;

    int j;
    if(i==n)
    {
        counter++;
        cout<<counter<<" "<<s<<"\n";
    }
    else
    {
        for(j = i; j <= n;j++)
        {
            swap((s+i),(s+j));
            permute(s,i+1,n);
            swap((s+i),(s+j));
        }
    }
}

int main()
{
    char str[10];
    cout<<"Enter a string: ";
    cin>>str;
    int n = strlen(str);
    permute(str,0,n-1);
    return 0;
}
