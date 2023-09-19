#include<iostream>
#include<cstdio>
using namespace std;

int ans=0,N,M;

void dfs(int m,int leftv,int S,int last_r, int last_h)
{
    if(!m&&!leftv)
    {
        if(S>ans||!ans) ans=S;
        return;
    }
    if(ans&&S>=ans)return;
    int r,h,curV,curA;
    for(r=last_r-1;r>=m;r--)
    {
        for(h=last_h-1;h>=m;h--)
        {
            curV=r*r*h;
            curA=2*r*h;
            if(m==M)
            {
                curA+=r*r;
            }
            if(S+2*leftv/r>=ans&&ans)
            continue;
            dfs(m-1,leftv-curV,S+curA,r,h);
        }
    }
}
    int main()
    {
        cin>>N>>M;
        dfs(M,N,0,N+1,N+1);
        cout<<ans<<endl;   
    }