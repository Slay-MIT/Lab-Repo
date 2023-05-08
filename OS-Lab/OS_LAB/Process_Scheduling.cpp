#include<bits/stdc++.h>
using namespace std;

class Process{
    public:
    int BT, AT, Prior, PID, Rem;
    float WT, TT;
};

int min(Process p[], int n, int timer){
    int min_time = 9999;
    int min=-1;
    for(int i=0;i<n;i++){
        if(p[i].AT <= timer && p[i].Rem >0 && p[i].BT<min_time){
            min_time = p[i].BT;
        }
    }
}


void RR(Process p[], int n){
    cout<<"In RR"<<endl;

    int timer = 0;
    float TAT = 0;
    float WT = 0;
    int done = 0, q;
    cout<<"Enter time slice: "<<endl;
    cin>>q;
    while(done!=n){
        for(int i=0;i<n;i++){
            int count = q;
            int start=timer;
            while(p[i].Rem>0 && p[i].AT<=timer && count>0){
                timer++;
                p[i].Rem--;
                count--;
            }
            if(start!=timer){
                cout<<p[i].PID<<" ----> ("<<start<<" , "<<timer<<" )"<<endl;
                if(p[i].Rem == 0){
                    TAT+=(timer-p[i].AT);
                    WT += (timer - p[i].AT + timer - p[i].BT);
                    done++;
                }
            }   
        }
    }
    TAT=TAT/n;
    WT=WT/n;
    printf("Turnaround Time = %0.2f ms \n", TAT);
    printf("Waiting Time = %0.2f ms\n\n\n", WT);
    


  cout<<"Exiting RR: "<<endl;
}


int main(){
    cout<<"In main"<<endl;
    int n;
        cout<<"Enter number of processes: "<<endl;
        cin>>n;
        Process p[n];
        cout<<"Enter PID, AT, BT, Priority: ";
        for(int i=0;i<n;i++){
            cout<<"Process ID "<<i+1<<"\t";
            cin>>p[i].PID>>p[i].AT>>p[i].BT>>p[i].Prior;
            p[i].Rem = p[i].BT; 
        }
        p[n].PID = -1;
    RR(p, n);
}