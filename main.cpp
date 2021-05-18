#include <iostream>
#include "queue.h"
using namespace std;

int **graph;
int *used;
que *q = new que;



int bfs (int v, int n){
//int check=1;

used[v]=1;
push(q,v);
int s=1;
while (s>0){
    int cur=front(q);

    s--;

    for(int i=0;i<n;i++){
        if (i!=cur && graph[cur][i]){
            if (!used[i]){
                used[i]=used[cur]+1;
                push(q,i);
                s++;
            }else if(used[cur]%2 == used[i]%2){
            return 0;
            }
        }
    }
    return 0;

}

return 1;
}


int main()
{
int flag=0;

    int n;
    cin>>n;
    int *color;
    color=new int[n];
    graph=new int*[n];
    used=new int[n];
    for (int i=0;i<n;i++){
        graph[i]=new int[n];
        used[i]=0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

for (int i=0;i<n;i++){
        if (!used[i]){
int check=bfs(i,n);
if (!check){
    flag=0;
}
}}
for (int i=0;i<n;i++){
    color[i]=used[i]%2;
}

for (int i=0;i<n;i++){
    cout<<used[i]<<" ";
}
cout<<flag;
return 0;
}
