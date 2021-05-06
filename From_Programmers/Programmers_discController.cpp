#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(vector<int> const & a, vector<int> const & b)
    { return a[1] > b[1]; }
};

int solution(vector<vector<int>> jobs) {
    int time = 0, answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    for(int i=0;i<jobs.size() || !pq.empty();){
        if(jobs.size() > i && time >= jobs[i][0]){
            pq.push(jobs[i++]);
            continue;
        }
        if(!pq.empty()){
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else{
            time = jobs[i][0];
        }
    }
    
    
    return answer / jobs.size();
}