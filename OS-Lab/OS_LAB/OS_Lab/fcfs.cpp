#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

void fcfs(vector <int> ref, int in){
    vector <pair<int, int>> arr;
    int sum = 0;
    arr.push_back({in, ref[0]});
    for(int i=0; i <ref.size() - 1; i++){
        arr.push_back({ref[i], ref[i+1]});
    }
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i].first<<"---"<<arr[i].second<<endl;
        sum += abs(arr[i].first - arr[i].second);
    }
    cout<<"total head moment is : "<<sum<<endl;

}

int main(){

    vector<int>ref ={176, 79, 34, 60, 92, 11, 41, 114};
    fcfs(ref, 50);

    return 0;
}