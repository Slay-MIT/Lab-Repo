/*#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

void fifo(vector<int> pages, int num_frames) {
    queue<int> frame_queue;
    unordered_set<int> frame_set;
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (frame_set.find(pages[i]) == frame_set.end()) {
            if (frame_queue.size() == num_frames) {
                int victim = frame_queue.front();
                frame_queue.pop();
                frame_set.erase(victim);
            }
            frame_queue.push(pages[i]);
            frame_set.insert(pages[i]);
            page_faults++;
        }
    }

    cout << "FIFO Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
}

void optimal(vector<int> pages, int num_frames) {
    unordered_set<int> frame_set;
    vector<int> frame_list(num_frames, -1);
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (frame_set.find(pages[i]) == frame_set.end()) {
            if (frame_list[num_frames - 1] != -1) {
                int farthest = -1;
                int victim = -1;
                for (int j = 0; j < num_frames; j++) {
                    int k = i + 1;
                    while (k < pages.size() && pages[k] != frame_list[j]) {
                        k++;
                    }
                    if (k > farthest) {
                        farthest = k;
                        victim = j;
                    }
                }
                frame_set.erase(frame_list[victim]);
                frame_list[victim] = pages[i];
                frame_set.insert(pages[i]);
            } else {
                frame_list[page_faults] = pages[i];
                frame_set.insert(pages[i]);
            }
            page_faults++;
        }
    }

    cout << "Optimal Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
}

void lru(vector<int> pages, int num_frames) {
    unordered_set<int> frame_set;
    vector<int> frame_list(num_frames, -1);
    vector<int> page_list;
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (frame_set.find(pages[i]) == frame_set.end()) {
            if (frame_list[num_frames - 1] != -1) {
                int victim = distance(page_list.begin(), find(page_list.begin(), page_list.end(), frame_list[0]));
                frame_set.erase(frame_list[0]);
                frame_list[0] = pages[i];
                frame_set.insert(pages[i]);
                page_list.erase(page_list.begin() + victim);
            } else {
                frame_list[page_faults] = pages[i];
                frame_set.insert(pages[i]);
            }
            page_list.push_back(pages[i]);
            page_faults++;
        } else {
            page_list.erase(find(page_list.begin(), page_list.end(), pages[i]));
            page_list.push_back(pages[i]);
        }
        auto it = find(frame_list.begin(), frame_list.end(), pages[i]);
        if (it != frame_list.end()) {
            rotate(frame_list.begin(), it, it + 1);
        }
    }

    cout << "LRU Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
}

int main() {
    vector<int> pages;
    int num_frames;

    cout << "Enter the number of frames: ";
    cin >> num_frames;

    cout << "Enter the page references (enter -1 to stop): ";
    int page;
    while (cin >> page && page != -1) {
        pages.push_back(page);
    }

    fifo(pages, num_frames);
    optimal(pages, num_frames);
    lru(pages, num_frames);

    return 0;
}*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void fifo(vector<int> pages, int num_frames) {
    queue<int> frame_queue;
    vector<bool> frame_set(1000, false); // assuming page numbers are between 0 and 999
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (!frame_set[pages[i]]) {
            if (frame_queue.size() == num_frames) {
                int victim = frame_queue.front();
                frame_queue.pop();
                frame_set[victim] = false;
            }
            frame_queue.push(pages[i]);
            frame_set[pages[i]] = true;
            page_faults++;
        }
    }

    cout << "FIFO Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
}

void optimal(vector<int> pages, int num_frames) {
    vector<bool> frame_set(1000, false); // assuming page numbers are between 0 and 999
    vector<int> frame_list(num_frames, -1);
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (!frame_set[pages[i]]) {
            if (frame_list[num_frames - 1] != -1) {
                int farthest = -1;
                int victim = -1;
                for (int j = 0; j < num_frames; j++) {
                    int k = i + 1;
                    while (k < pages.size() && pages[k] != frame_list[j]) {
                        k++;
                    }
                    if (k > farthest) {
                        farthest = k;
                        victim = j;
                    }
                }
                frame_set[frame_list[victim]] = false;
                frame_list[victim] = pages[i];
                frame_set[pages[i]] = true;
            } else {
                frame_list[page_faults] = pages[i];
                frame_set[pages[i]] = true;
            }
            page_faults++;
        }
    }

    cout << "Optimal Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
}

void lru(vector<int> pages, int num_frames) {
    vector<bool> frame_set(1000, false); // assuming page numbers are between 0 and 999
    vector<int> frame_list(num_frames, -1);
    vector<int> page_list;
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (!frame_set[pages[i]]) {
            if (frame_list[num_frames - 1] != -1) {
                int victim = distance(page_list.begin(), find(page_list.begin(), page_list.end(), frame_list[0]));
                frame_set[frame_list[0]] = false;
                frame_list[0] = pages[i];
                frame_set[pages[i]] = true;
                page_list.erase(page_list.begin() + victim);
            } else {
                frame_list[page_faults] = pages[i];
                frame_set[pages[i]] = true;
            }
            page_list.push_back(pages[i]);
            page_faults++;
        } else {
            page_list.erase(find(page_list.begin(), page_list.end(), pages[i]));
            page_list.push_back(pages[i]);
        }
        auto it = find(frame_list.begin(), frame_list.end(), pages[i]);
        if (it != frame_list.end()) {
            rotate(frame_list.begin(), it, it + 1);
        }
    }

    cout << "LRU Page Replacement Algorithm" << endl;
    cout << "Number of page faults: " << page_faults << endl;
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
    optimal(pages, num_frames);
    //lru(pages, num_frames);

    return 0;
}