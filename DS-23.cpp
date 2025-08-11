#include <stdio.h>
#define INF 999
int main(){
    int n,i,j,u,min,dist[10],vis[10],cost[10][10];
    scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&cost[i][j]);
    for(i=0;i<n;i++) dist[i]=INF,vis[i]=0;
    dist[0]=0;
    for(i=0;i<n;i++){
        min=INF;
        for(j=0;j<n;j++) if(!vis[j] && dist[j]<min) min=dist[u=j];
        vis[u]=1;
        for(j=0;j<n;j++)
            if(!vis[j] && dist[u]+cost[u][j]<dist[j])
                dist[j]=dist[u]+cost[u][j];
    }
    for(i=0;i<n;i++) printf("0->%d:%d\n",i,dist[i]);
}

