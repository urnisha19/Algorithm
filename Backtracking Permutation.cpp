#include <bits/stdc++.h>
using namespace std;
void permutate(string str,int start,int endd)
{
    if (start==endd)
        cout<<str<<endl;
    else
    {
        for (int i=start; i<=endd; i++)
        {
            swap(str[start],str[i]);
            permutate(str,start+1,endd);
            swap(str[start],str[i]);//bactracking
        }
    }
}
int main()
{
    int N;
    string str="abcdefghijklmnopqrstuwxyz";
    scanf("%d",&N);
    str.resize(N);
    permutate(str, 0, N-1);
    return 0;
}

