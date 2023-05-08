#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int find_dis(vector <int> ref, int in){
    int dis = abs(ref[0]-in);
    int curr = 0;
    for(int i=0;i<ref.size(); i++){
        int temp = abs(ref[i] - in);
        if(temp<dis){
            dis = temp;
            curr = i;
        }
    }
    return curr;
}

void sstf(vector <int> ref, int in){
    vector <pair<int, int>> arr;
    int sum = 0;
    for(int i=0; ref.size()!=0; i++){
        int pos = find_dis(ref, in);
        arr.push_back({in, ref[pos]});
        in = ref[pos];
        ref.erase(ref.begin() + pos);
        
    }
    for(int i=0; i<arr.size(); i++){
        sum+=abs(arr[i].first - arr[i].second);
        cout<<arr[i].first<<"---"<<arr[i].second<<endl;
    }
    cout<<"Total head moment is "<<sum;
}

int main(){

    vector<int>ref ={176, 79, 34, 60, 92, 11, 41, 114};
    sstf(ref, 50);

    return 0;
}