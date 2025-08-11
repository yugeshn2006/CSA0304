#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX];
void dfs(int v,int n){
    int i; visited[v]=1; printf("%d ",v);
    for(i=0;i<n;i++) if(adj[v][i] && !visited[i]) dfs(i,n);
}
int main(){
    int n,i,j,s;
    scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&adj[i][j]);
    scanf("%d",&s);
    dfs(s,n);
}

