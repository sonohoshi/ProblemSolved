#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(auto i = completion.begin(); i != completion.end(); i++){
        if(m.find(*i) != m.end()){
            m[*i]++;
        }else{
            m[*i] = 1;
        }
    }
    
    for(auto i = participant.begin(); i != participant.end(); i++){
        if(m[*i] > 0){
            m[*i]--;
        }else{
            return *i;
        }
    }
}