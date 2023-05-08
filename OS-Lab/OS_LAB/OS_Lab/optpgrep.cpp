#include <bits/stdc++.h>
using namespace std;

bool found(int ele,vector<int>arr,int n){
    int flag = 0;
    for (int i = 0; i < n; i++){
        if(ele == arr[i]){
            flag = 1;
            break;
        }
    }
    return (flag ? 1 : 0);
}

int distance(int j,vector<int>arr,vector<int>process,int n){
    priority_queue<pair<int,int>>pq;
    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        if(ele==-1){
            return i;
        }
        else{   
            int dist = 0;
            int k = j;
            while(1){
                if(ele==process[k]){
                    pq.push({dist,i});
                    break;
                }
                else if(k==n-1){
                    pq.push({99,i});
                    break;
                }
                k++;
                dist++;
            }
        }
    }
    return pq.top().second;
}
void optimal(vector<int>process,int framesize){
    vector<int>arr(framesize,-1);
    int hit = 0;
    int mat[framesize][process.size()];
    int index = 0;
    int f=0;
    for (int i = 0; i < process.size(); i++)
    {
        if(found(process[i],arr,framesize)){
            hit++;
        }
        else{
            if(i<3){
                index = index%framesize;
                arr[index] = process[i];
                index++;
            }
            else{
                int rep = distance(i,arr,process,process.size());
                arr[rep]=process[i];
            }
        }
        for (int j = 0; j < framesize; j++)
            mat[framesize-1-j][f]=arr[j];
        
        f++;
    }
    for (int i = 0; i < framesize; i++){
        for (int j = 0; j < process.size(); j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<hit;
}
int main(){
    vector<int>process =  {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3};
    // vector<int>arr = {2,1,0,7};
    optimal(process,5);
    // cout<<process.size();
}