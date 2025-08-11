#include <stdio.h>
#define INF 999
int parent[10];
int find(int i){ while(parent[i]) i=parent[i]; return i; }
int uni(int i,int j){ if(i!=j){ parent[j]=i; return 1; } return 0; }
int main(){
    int n,cost[10][10],i,j,min,u,v,mincost=0,ne=1;
    scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&cost[i][j]);
    while(ne < n){
        min=INF;
        for(i=0;i<n;i++) for(j=0;j<n;j++)
            if(cost[i][j]<min){ min=cost[i][j]; u=i; v=j; }
        if(uni(find(u),find(v))){
            printf("Edge %d: %d-%d cost:%d\n",ne++,u,v,min);
            mincost+=min;
        }
        cost[u][v]=cost[v][u]=INF;
    }
    printf("Min Cost: %d\n",mincost);
}

