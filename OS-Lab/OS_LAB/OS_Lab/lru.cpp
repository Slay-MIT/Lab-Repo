#include <bits/stdc++.h>
using namespace std;

bool found(int ele,vector<int>arr,int n){
    for (int i = 0; i < n; i++)
        if(ele == arr[i])
            return true;
    return false;
}

int predict(int j,vector<int>process,vector<int>arr){
    priority_queue<pair<int,int>>pq;
    for (int i = 0; i < arr.size(); i++){
        int ele = arr[i];
        int k = j;
        int dist = 0;
        if(ele==-1)return i;
        while(1){
            if(ele==process[k]){
                pq.push({dist,i});
                break;
            }
            else if(k==0){
                pq.push({99,i});
                break;
            }
            dist++;
            k--;
        }
    }
    return pq.top().second;
}

void lru(vector<int>process,int framesize){
    vector<int>arr(framesize,-1);
    int hit = 0;
    int mat[framesize][process.size()+4];
    int index=0;
    int f = 0;
    for (int i = 0; i < process.size(); i++)
    {
        if(found(process[i],arr,framesize)){
            hit++;
        }
        else{
            if(i<framesize){
                index=index%framesize;
                arr[index]=process[i];
                index++;
            }
            else{
                int rep = predict(i,process,arr);
                arr[rep] = process[i];
            }
        }
        for (int j = 0; j < framesize; j++)
        {
            mat[framesize-j-1][f] = arr[j];
        }
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
    vector<int>process = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    lru(process,4);
}