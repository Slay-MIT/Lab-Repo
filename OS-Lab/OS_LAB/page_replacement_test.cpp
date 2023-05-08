#include<bits/stdc++.h>
using namespace std;

void fifo(vector<int> pages, int num_frame){
    queue<int> q_frame;
    int page_fault =0;
    vector<bool> frame_set(1000, false);
    for(int i=0;i<pages.size();i++){
        if(!frame_set[pages[i]]){
            if(q_frame.size() == num_frame){
                int victim = q_frame.front();
                q_frame.pop();
                frame_set[victim] = false;
            }
            q_frame.push(pages[i]);
            frame_set[pages[i]] = true;
            page_fault++;
        }
    }
    cout<<"FIFO Page replacement: "<<endl;
    cout<<"Number of hits: "<<pages.size() - page_fault<<endl;
    cout<<"Number of page faults:  "<<page_fault<<endl;
}

void Optimal(vector<int> pages, int num_frames){
    vector<int> frame_set(1000, false);
    vector<int> frame_list(num_frames, -1);
    int page_faults = 0;

    for(int i=0;i<pages.size();i++){
        if(!frame_set[pages[i]]){
            if(frame_list[num_frames - 1] != -1){
                int farthest = -1;
                int victim = -1;
                for(int j=0;j<num_frames;j++){
                    int k = i+1;
                    while(k<pages.size() && pages[k] != frame_list[j]){
                        k++;
                    }
                    if(k>farthest){
                        farthest = k;
                        victim = j;
                    }
                }
                frame_set[frame_list[victim]] = false;
                frame_list[victim] = pages[i];
                frame_set[pages[i]] = true;
            }
            else{
                frame_list[page_faults] = pages[i];
                frame_set[pages[i]] = true;
            }
            page_faults++;
        }
    }
     cout << "Optimal Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
}

void lru(vector<int> pages, int num_frames){
    
}

int main() {
    vector<int> pages;
    int num_frames;

    // cout << "Enter the number of frames: ";
    // cin >> num_frames;

    //cout << "Enter the page references (enter -1 to stop): ";
    int page;
    // while (cin >> page && page != -1) {
    //     pages.push_back(page);
    // }
    num_frames = 5;
    pages = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    //fifo(pages, num_frames);
    Optimal(pages, num_frames);
    //lru(pages, num_frames);

    return 0;
}