#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    vector<bool> tmp(my_string.length());
    for(int i=0;i<indices.size();i++){
        tmp[indices[i]] = 1;
    }
    for(int i=0;i<my_string.length();i++){
        if(!tmp[i]) answer+=my_string[i];
    }
    return answer;
}