#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(int i=0;i<intStrs.size();i++){
        string a = intStrs[i].substr(s,l);
        if(stoi(a) > k) answer.push_back(stoi(a));
    }
    return answer;
}