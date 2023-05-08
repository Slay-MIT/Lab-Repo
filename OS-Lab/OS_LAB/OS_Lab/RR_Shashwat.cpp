#include<iostream>
#include<vector>
#include<string>
using namespace std;

void rr( vector<vector<int>> proc , int quanta){
    int i=0;
    int current_time=0;
    int proc_count=proc.size();
    vector<vector<int>> temp=proc;
    vector<int> proc_name;
    vector<int> end_time;
    end_time.push_back(0);
    while(proc.size()>0){
        if (proc[i][1]<=current_time){
            if(proc[i][2] < quanta){
                current_time+=proc[i][2];
                proc_name.push_back(proc[i][0]);
                end_time.push_back(current_time);
                proc[i][2]=0;
            }
            else{
                proc[i][2]-=quanta;
                current_time+=quanta;
                cout<<current_time<<endl;
                proc_name.push_back(proc[i][0]);
                if(proc.size()==1){
                    end_time.push_back(current_time+proc[i][2]);
                    goto end;}
                else 
                end_time.push_back(current_time);
            }
        }
        if( proc[i][2]==0){
            proc.erase(proc.begin()+i);
        }
        else i++;
        if(i>=proc.size()) i=0;
        bool flag=false;
        for(int j=0;j<proc.size();j++){
            if (proc[j][1]<=current_time){
                flag=true;
            }
        }
        if(!flag)
            current_time++;
    }
    //--DISPLAY --
    end:
    cout<<proc_name.size()<<end_time.size()<<endl;
    for(int i=0;i<proc_name.size();i++){
        if(to_string(end_time[i]).length()>1)
        cout<<"|"<<" "<<proc_name[i]<<"  ";
        else
        cout<<"|"<<" "<<proc_name[i]<<" ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<end_time.size();i++){
        cout<<end_time[i]<<"   ";
    }cout<<endl<<endl;
    int sum=0;
    int n=0;
    for(int i=0;i<temp.size();i++){
        cout<<"WaitingTime for ";
        int ind;
        for(int j=0;j<proc_name.size();j++){
            if(temp[i][0]==proc_name[j]){
                ind=j;
            }
        }
        sum+=end_time[ind+1]-temp[i][1]-temp[i][2];
        cout<<proc_name[ind]<<" "<<end_time[ind+1]-temp[i][1]-temp[i][2];
        n+=1;
        cout<<endl;
    }
    cout<<"Average waiting time is "<<(float)sum/(float)n;
    // cout<<endl;
    // for(int i=0;i<temp.size();i++){
    //     cout<<"TurnAroundTime for ";
    //     int ind=0;
    //     for(int j=0;j<proc_name.size();j++){
    //         if(temp[i][0]==proc_name[j]){
    //            ind=j;
    //         }
    //     }
    //     cout<<proc_name[ind]<<" "<<end_time[ind+1];
    //     cout<<endl;
    // }
}
int main(){
    cout<<"enter no of processes "<<endl;
    int n;
    cin>>n;
    cout<<"enter PROC ID , ARRIVAL TIME and EXECUTION TIME"<<endl;
    vector<vector<int>> proc;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int id,at,et;
        cin>>id>>at>>et;
        temp.push_back(id);
        temp.push_back(at);
        temp.push_back(et);
        proc.push_back(temp);
    }
    cout<<"enter time quanta"<<endl;
    int tq;
    cin>>tq;
    rr(proc,tq);
}