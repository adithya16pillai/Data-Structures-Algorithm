#include <iostream>
using namespace std;

int g[5][5],n,st[5],top=-1,vis[5];

void readmatrix(){
    int i,j;
    cout << "\nEnter the number of vertices:";
    cin >> n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
        cout << "\nEdge from " << i <<" to " << j << ": ";
        cin >> g[i][j];
    }
}

void initialize() {
    int i;
    for(i=0;i<n;i++)
        vis[i]=0;
}

void printmatrix() {
    int i,j;
    cout << "\nAdjacency Matrix:\n";
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
        cout << g[i][j];
    cout << "\n";
    }
}

void push(int x) {
    st[++top]=x;
}

int pop() {
    if(top==-1)
        return -1;
    else
        return st[top--];
}

void dfs(int s) {
    int x,i;
    push(s); 
    vis[s]=1;
    x=pop();
    if(x!=-1)
        cout << x;
    while(x!=-1) {
        for(i=0;i<=n-1;i++) {
            if((g[x][i]==1) && (vis[i]==0)) {
                push(i);
                vis[i]=1;
            }
        }
        x=pop();
        if(x!=-1)
            cout << x;
    }
}
int main() {
    int s;
    readmatrix();
    printmatrix();
    while(1) {
    initialize();
    cout << "\nEnter Source:";
    cin >> s;
    cout << "\nDFS:";
    dfs(s);
    }
    return 0;
}