#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    for(auto i = phone_book.begin(); i != phone_book.end(); i++){
        um[*i] = 1;
    }
    
    for(int i=0;i<phone_book.size();i++){
        string str = "";
        for(int j=0;j<phone_book[i].size();j++){
            str += phone_book[i][j];
            if(um[str] && str != phone_book[i]) return false;
        }
    }
    
    return true;
}