#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX], q[MAX];
int front=-1,rear=-1;
void enqueue(int v){ q[++rear]=v; }
int dequeue(){ return q[++front]; }
int empty(){ return front==rear; }
void bfs(int s,int n){
    int i,v; visited[s]=1; enqueue(s);
    while(!empty()){
        v=dequeue(); printf("%d ",v);
        for(i=0;i<n;i++)
            if(adj[v][i] && !visited[i])
                visited[i]=1,enqueue(i);
    }
}
int main(){
    int n,i,j,s;
    printf("Vertices: "); scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&adj[i][j]);
    printf("Start: "); scanf("%d",&s);
    bfs(s,n);
}

