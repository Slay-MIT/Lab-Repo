#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int index(vector <int> ref, int in){
    for (int i=0; i<ref.size(); i++){
        if (in == ref[i]){
            return i;
        }
    }
}

void look (vector <int> ref, int in, char ch){
    ref.push_back(in);
    sort(ref.begin(), ref.end());
    int ind = index(ref, in);
    vector <pair<int, int>> arr;
    int sum = 0;
    if(ch == 'l'){
        for (int i=ind; i>0; i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        arr.push_back({ref[0], ref[ind+1]});
        for(int i= ind+1; i<ref.size() - 1; i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i].first<<"---"<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total Head Moment is "<<sum<<endl;
    }
    else{
        for(int i=ind; i<ref.size()-1; i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        arr.push_back({ref[ref.size() - 1], ref[ind -1]});
        for(int i=ind-1;i>0;i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i].first<<"---"<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total Head Moment is "<<sum<<endl;
    }
}

void clook(vector <int> ref, int in, char ch){
    int sum = 0;
    ref.push_back(in);
    sort(ref.begin(), ref.end());
    vector <pair<int, int>> arr;
    int ind = index(ref, in);
    if (ch == 'l'){
        for(int i= ind; i>0; i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        arr.push_back({ref[0], ref[ref.size() - 1]});
        for(int i = ref.size() - 1; i>ind +1; i--){
            arr.push_back({ref[i], ref[i-1]});
        }
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i].first<<"---"<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total Head Moment is "<<sum<<endl;

    }
    else{
        for(int i= ind; i<ref.size() - 1; i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        arr.push_back({ref[ref.size() - 1], ref[0]});
        for(int i=0; i<ind-1; i++){
            arr.push_back({ref[i], ref[i+1]});
        }
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i].first<<"---"<<arr[i].second<<endl;
            sum+=abs(arr[i].first - arr[i].second);
        }
        cout<<"Total Head Moment is "<<sum<<endl;
    }
    
}

int main(){

    vector<int>ref ={176, 79, 34, 60, 92, 11, 41, 114};
    //look(ref,50,'l');
    clook(ref,50,'h');

    return 0;
}