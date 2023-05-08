#include<bits/stdc++.h>
using namespace std;


int main(){
    int Max[10][10], Need[10][10], Allocation[10][10], Available[10], Completed[10], safeSequence[10];
    int p, r, process, count = 0, k=0;
    
    cout<<"Enter number of processes: ";
    cin>>p;
    cout<<"\nEnter number of resources: ";
    cin>>r;

    for(int i=0;i<p;i++){
        Completed[i]=0;
        safeSequence[i]=0;
    }
    
    cout<<"\n Enter max matrix for each process: "<<endl;
    for(int i=0;i<p;i++){
        cout<<" For process id "<<i+1<<" : ";
        for(int j=0;j<r;j++){
            cin>>Max[i][j];
        }
    }
    cout<<"\nEnter Allocation for each process: "<<endl;
    for(int i=0;i<p;i++){
        cout<<"For process id "<<i+1<<" : ";
        for(int j=0;j<r;j++){
            cin>>Allocation[i][j];
        }
    }

    cout<<"\nInitial Resource allocation "<<endl;
    for(int i=0;i<r;i++){
        cin>>Available[i];
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            Need[i][j] = Max [i][j] - Allocation[i][j];
            
        }
    }
    cout<<"Max matrix:\tAllocation Matrix"<<endl;
        for(int i=0;i<p;i++){
            for(int j=0;j<r;j++){
                cout<<Max[i][j];
            }
            cout<<"\t\t";
            for(int j=0;j<r;j++){
                cout<<Allocation[i][j];
            }
            cout<<"\n";
        }
    do{
        cout<<"Available Matrix: \n";
        for(int i=0;i<r;i++){
            cout<<Available[i]<<"\t";
        }
        cout<<"\n";
        /*-------------------------------------*/
        process = -1;
        for(int i=0;i<p;i++){
            if(Completed[i]==0){
                process = i;
                for(int j=0;j<r;j++){
                    if(Available[j]<=Need[i][j]){
                        process = -1;
                        break;
                    }
                }
            }
            if(process != -1)
                break;
        }
        if(process != -1){
            cout<<"\nProcess "<<process+1<<" runs to completion \n";
            safeSequence[count] = process + 1;
            count++;
            for(int i=0;i<r;i++){
                Available[i]+=Allocation[process][i];
                Allocation[process][i]=0;
                Max[process][i] = 0;
                Completed[process] = 1;
            }
        }
        k++;
    }while(k !=2*p  && process!=-1);
    if(count == p){
        cout<<"The system is in a safe state"<<endl;
        cout<<"Safe Sequence: "<<endl;
        for(int i=0;i<p;i++){
            cout<<safeSequence[i]<<"\t";
        }
    }
    else{
        cout<<"The system is in an unsafe state"<<endl;
        cout<<"Safe Sequence: "<<endl;
        for(int i=0;i<p;i++){
            cout<<safeSequence[i]<<"\t";
        }
    }

}

// #include <iostream>
// #include <cstring>

// using namespace std;

// int main(){
//     int m,n;
//     cout << "Enter the number of processes(m): ";
//     cin >> m;
//     cout << "Enter the number of resources(n): ";
//     cin >> n; 

//     //Develop the Matrices and Vectors
//     int allocation[m][n], max[m][n], need[m][n], available[n];
//     cout << "Enter the Max matrix :\n";
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin >> max[i][j];
//         }
//     }
//     cout << "Enter the Allocation matrix :\n";
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin >> allocation[i][j];
//             need[i][j] = max[i][j] - allocation[i][j];
//         }
//     }
//     cout << "Enter the available vector:\n";
//     for(int i=0;i<n;i++)
//         cin >> available[i];
    
//     // Apply Safety Algorithm    
//     int work[n], finish[m], safestate[m];
//     memset(finish, 0, sizeof(finish));
//     memcpy(work, available, sizeof(work));
//     int i=0, ind = 0;
//     while(1){
//         int success = 0;
//         for(int j=0;j<m;j++){
//             if(!finish[j]){
//                 int inside = 1;
//                 for(int k = 0;k<n; k++){
//                     if(need[j][k]>work[k]){
//                         inside = 0;
//                         break;
//                     }
//                 }
//                 if(inside){
//                     safestate[ind++] = j;
//                     for(int k = 0;k<n; k++)
//                         work[k] += allocation[j][k];
//                     finish[j] = 1;
//                     success = 1;
//                 }
//             }
//         }
//         if(!success)
//             break;
//     }

//     // Output safestate array
//     cout << "Safe state: ";
//     for(int i=0;i<m;i++){
//         cout << safestate[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }
