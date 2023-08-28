#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int st,en;
    int a = slicer[0], b = slicer[1], c = slicer[2];
    if(n==1){
        st=0; en=b;
    }
    else if(n==2){
        st=a; en=num_list.size()-1;
    }
    else if(n==3){
        st=a; en=b;
    }
    else{
        for(int i=a;i<=b;i+=c){
            answer.push_back(num_list[i]);
        }
        return answer;
    }
    for(int i=st;i<=en;i++){
        answer.push_back(num_list[i]);
    }
    return answer;
}