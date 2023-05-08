#include <iostream>
#include<vector>
using namespace std;

void bankers(int alloc[][3], int maxn[][3], int available[], int n, int m){
    int need[n][m];
    int work[m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = maxn[i][j] - alloc[i][j];
        }
    }
    int finish[10] = {0}, ans[10], curr =0;
    for(int k=0 ;k<n; k++){
        for(int i=0; i<n; i++){
            if(finish[i] == 0){
                int flag = 0;
                for(int j=0; j<m; j++){
                    if(need[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    ans[curr++] = i+1;
                    finish[i] = 1;
                    for(int l=0; l< m; l++){
                        available[l] += alloc[i][l];
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<"\t";
    }
}

int main(){

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
                   { 4, 2, 2 }, 
                   { 5, 3, 3 } }; 
 
    int avail[3] = { 3, 3, 2 }; 

    bankers(alloc, maxn,avail, 5, 3);

    return 0;
}