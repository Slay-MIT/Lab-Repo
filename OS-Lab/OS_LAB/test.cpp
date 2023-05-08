#include<bits/stdc++.h>
using namespace std;


void bankers(int alloc[][3], int maxn[][3], int avail[], int p, int r){
    int need[10][10], work[10];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            need[i][j]=maxn[i][j] - alloc[i][j];
        }
    }
    int completed[10] = {0};
    int ans[10], curr = 0;
    for(int k=0;k<p;k++){
        for(int i=0;i<p;i++){
            if(completed[i]==0){
                int flag = 0;
                for(int j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag == 0){
                    ans[curr++] = i;
                    completed[i]=1;
                    cout<<completed[i]<<"\t";
                    for(int l=0;l<r;l++){
                        avail[l] += alloc[i][l]; 
                    }

                }
            }
        }
    } 
    cout<<endl;
    for(int i=0;i<p;i++){
        cout<<ans[i]<<"\t";
    }

}

int main(){
    //int safe[10], complete[10];
    int n, m, i, j, k;
    n = 5; 
    m = 3;
    int alloc[5][3] = { { 0, 1, 0 }, 
                     { 2, 0, 0 }, 
                     { 3, 0, 2 }, 
                     { 2, 1, 1 }, 
                     { 0, 0, 2 } }; 
 
    int maxn[5][3] = { { 7, 5, 3 }, 
                   { 3, 2, 2 },
                   { 9, 0, 2 }, 
                   { 2, 2, 2 }, 
                   { 4, 3, 3 } }; 
 
    int avail[3] = { 3, 3, 2 };
    bankers(alloc, maxn, avail, 5, 3);
}