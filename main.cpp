#include <iostream>
#include<graphics.h>
#include<conio.h>
#include "queue.h"
#include<math.h>
#include <string>
#include<sstream>
#include "string.h"
#define PI 3.14159265

const double ang=2*PI;
using namespace std;

int **graph;
int *used;
que *q =NULL;



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

}

return 1;
}


int main()
{
int flag=1;

    int n;
    cin>>n;
    int *color, *center;
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
/*
for (int i=0;i<n;i++){
    cout<<used[i]<<" ";
}*/
if (!flag){
    cout<<"Error";
    return 0;
}
center=new int[n];
int gd=CUSTOM;
int gm=CUSTOM_MODE(800,800);
initgraph(&gd,&gm,"");
//line(1,1,100,100);
int first=0, second=0;
stringstream ss;
for (int i=0;i<n;i++){
        ss<<i;
        string s=ss.str();
        char const *st=s.c_str();
    if (color[i]){
    circle(300,100+85*first,20);
    outtextxy(300,100+85*first,st);
    center[i]=100+85*first;
    first++;
    }else{

    circle(600,100+85*second,20);
    outtextxy(600,100+85*second,st);
    center[i]=100+85*second;
    second++;
    }
    ss.str("");
}

for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
        if (graph[i][j]){
            if (color[i]){
                line(320,center[i],580,center[j]);
            }else{
            line(580,center[i],320,center[j]);
            }
        }
    }
}

readkey();
closegraph();
return 0;
}
