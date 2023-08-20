#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    for(auto x:number){
        answer+=x-'0';
    }
    return answer%9;
}