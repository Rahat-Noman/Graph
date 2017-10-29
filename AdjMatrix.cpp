//adj matrix diye adj list dekhaneo 
//level and shortest path dekhano


#include<bits/stdc++.h>
using namespace std;

#define MX 10000
int g[MX][MX],level[MX],path[MX],node,edge;
bool visited[MX];
queue<int>q;

void bfs(int s)
{
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = true;
        printf("%d -> ",s);
        for(int i=1; i<=node; i++)
        {
            if(visited[i]==false && g[s][i])
            {
                level[i] = level[s]+1;
                printf("%d ",i);
                q.push(i);
                visited[i] = true;
                path[i] = s;
            }
        }
        puts("");
    }
}

void shortest_path(int s)
{
    printf("Shortest path of %d : ",s);
    printf("%d ",s);
    while(path[s]!=-1)
    {
        printf("%d ",path[s]);
        s = path[s];
    }
    puts("");
}

int main()
{
    int i,x,y;
    scanf("%d %d",&node,&edge);
    for(i=0; i<=node; i++) visited[i] = false;
    for(i=0; i<edge; i++)
    {
        scanf("%d %d",&x,&y);
        g[x][y] = 1;
        g[y][x] = 1;
    }
    memset(path,-1,sizeof(path));
    printf("\nAdjacency list:\n");
    bfs(1);
    puts("");
    for(i=1; i<=node; i++) printf("Level of %d = %d\n",i,level[i]);
    puts("");
    for(i=1; i<=node; i++) shortest_path(i);
    puts("");
    return 0;
}

/*10 13
1 2
2 6
6 10
10 5
5 8
1 3
3 8
3 7
7 9
9 10
1 4
4 7
7 8*/
