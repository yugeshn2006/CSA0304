#include <stdio.h>
#define INF 999
int main(){
    int n,i,j,u,v,min,mincost=0,visited[10]={0},cost[10][10];
    scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&cost[i][j]);
    visited[0]=1;
    for(i=0;i<n-1;i++){
        min=INF;
        for(u=0;u<n;u++) if(visited[u])
            for(v=0;v<n;v++) if(!visited[v] && cost[u][v]<min)
                min=cost[u][v], visited[v]=visited[v], u=u, v=v;
        visited[v]=1; mincost+=min;
        printf("Edge: %d-%d cost:%d\n",u,v,min);
    }
    printf("Min Cost: %d\n",mincost);
}

