/*使用一维数组*/
#include<algorithm>
#include<iostream>

using namespace std;

const int MAXN = 1005;
int v[MAXN];    // 体积
int w[MAXN];    // 价值 
int f[MAXN];  // f[j], j体积下的最大价值 

int main() 
{
    int n, m;   
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++) 
        for(int j = m; j >=v[i] ; j--)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }

    cout << f[m] << endl;

    return 0;
}

