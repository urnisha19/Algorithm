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
            swap(str[start],str[i]);
        }
    }
}
int main()
{
    int i,N;
    scanf("%d",&N);
    char small_alpha;
    for(i=1; i<=N; i++)
    {
        small_alpha = i+ 96;
    }
    string str= ; //to take 1st N small alphabet in a string??
    int length = str.size();
    permutate(str, 0, length-1);
    return 0;
}

