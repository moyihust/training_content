#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN=301;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
bool visited[MAXN][MAXN];
struct Node
{
    int x,y,step;
    Node(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
};

int L;
int bfs(int sx,int sy,int ex,int ey)
{
    memset(visited,0,sizeof(visited));
    queue<Node> q;
    q.push(Node(sx,sy,0));
    visited[sx][sy]=true;
    while(!q.empty())
    {
        Node node=q.front();
        q.pop();
        if(node.x==ex&&node.y==ey)
            return node.step;
        for(int i=0;i<8;i++)
        {
            int nx=node.x+dx[i];
            int ny=node.y+dy[i];
            if(nx>=0&&nx<L&&ny>=0&&ny<L&&!visited[nx][ny])
            {
                q.push(Node(nx,ny,node.step+1));
                visited[nx][ny]=true;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>L;
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        cout<<bfs(sx,sy,ex,ey)<<endl;
    }
}