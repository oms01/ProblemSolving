#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    if(n_str[0]!='0'){
        return n_str;
    }
    for(int i=1;i<n_str.length();i++){
        if(n_str[i]!=n_str[i-1]){
            return n_str.substr(i,n_str.length());
        }
    }
    return "1";
}