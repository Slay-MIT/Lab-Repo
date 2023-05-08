#include<bits/stdc++.h>
using namespace std;

void bestfit(vector<int>blocks, vector<int> processes){
    vector<int>allocation(processes.size(), -1);
    for(int i=0;i<processes.size();i++){
        int in = -1;
        for(int j=0 ; j<blocks.size(); i++){
            if(blocks[j] >= processes[i]){
                if(in==-1){
                    in = j;
                }
                else if(blocks[j]<blocks[in]){
                    in = j;
                }
            }
            if(in != -1){
                allocation[i] = in;
                blocks[in]-=processes[i];
            }
        }
    }
    for (int i = 0; i < processes.size(); i++)
    {
        cout<<i+1<<"\t"<<processes[i]<<"\t";
        if(allocation[i]!=-1)cout<<allocation[i]+1<<endl;
        else cout<<"Not allocated"<<endl;
    }
}

void worstfit(vector<int> blocks, vector<int> processes){
    vector<int>allocation(processes.size(), -1); //allocation maintained to see which block the process has been put in
    for(int i=0;i<processes.size();i++){
        int in = -1;
        for(int j=0;j<blocks.size();j++){
            if(blocks[j]>=processes[i]){
                if(in == -1) in=j;
                else if(blocks[j]>blocks[in]){
                    in = j;
                }
            }
        }
        if(in!=-1){
                allocation[i]=in;
                blocks[i]-=processes[i];
            }
    }
    for (int i = 0; i < processes.size(); i++)
    {
        cout<<i+1<<"\t"<<processes[i]<<"\t";
        if(allocation[i]!=-1)cout<<allocation[i]+1<<endl;
        else cout<<"Not allocated"<<endl;
    }
}
void firstfit(vector<int>b,vector<int>p){
    vector<int>allocation(p.size(),-1);
    for (int i = 0; i < p.size(); i++){
        for (int j = 0; j < b.size(); j++)
        {
            if(b[j]>=p[i]){
                allocation[i]=j;
                b[j]-=p[i];
                break;
            }
        }
 
    }
    for (int i = 0; i < p.size(); i++)
    {
        cout<<i+1<<"\t"<<p[i]<<"\t";
        if(allocation[i]!=-1)cout<<allocation[i]+1<<endl;
        else cout<<"Not allocated"<<endl;
    }
} 