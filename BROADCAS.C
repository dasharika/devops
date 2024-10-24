#include<stdio.h>
#include<stdlib.h>
#define MAX_HOSTS 100
#define QUEUE_SIZE 100
int queue[QUEUE_SIZE];
int front=0,rear=0;
void enqueue(int v){
if(rear==QUEUE_SIZE){
printf("Queue overflow\n");
return;
}
queue[rear++]=v;
}
int dequeue(){
if(front==rear){
printf("Queue underflow\n");
return -1;
}
return queue[front++];
}
int isEmpty() {
return front==rear;
}
void bfs(int adjMatrix[MAX_HOSTS][MAX_HOSTS],int numHosts,int start){
int visited[MAX_HOSTS]={0};
int i;
enqueue(start);
visited[start]=1;
printf("Broadcast Tree(BFS order):\n");
while(!isEmpty()){
int currentHost=dequeue();
printf("Host %d\n",currentHost);
for(i=0;i<numHosts;i++){
if(adjMatrix[currentHost][i]==1&&!visited[i])
{
enqueue(i);
visited[i]=1;
}
}
}
}
int main(){
int numHosts,i,j,startHost;
int adjMatrix[MAX_HOSTS][MAX_HOSTS];
printf("Enter the number of hosts in the subnet:");
scanf("%d",&numHosts);
printf("Enter the adjecency matrix(0 for no connection,1 for connection):\n");
for(i=0;i<numHosts;i++){
for(j=0;j<numHosts;j++){
scanf("%d",&adjMatrix[i][j]);
}
}
printf("Enter the starting host for the broadcast (0 to %d):",numHosts-1);
scanf("%d",&startHost);
bfs(adjMatrix,numHosts,startHost);
return 0;
}