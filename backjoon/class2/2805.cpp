#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 1000001;
int n;
long long int m;
long long int tree[MAX];

long long int checkLength(int cutLength){
    long long int total = 0;
    for(int i = 0; i < n; i++){
        long long int temp = tree[i] - cutLength;
        if(temp > 0) total += temp;
    }
    return total;
}


long long int highestLength(int s1, int e1){
    int start = s1;
    int end = e1;
    int mid;
    if(checkLength(start) == m) return start;
    if(checkLength(end) == m) return end;
    while(start + 1 < end){
        //cout << start << ' ' << end << '\n';
        mid = (start + end) / 2;
        if(checkLength(mid) >= m) start = mid;
        else end = mid;
    }
    return start;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        long long int input;
        cin >> input;
        tree[i] = input;
    }
    sort(tree, tree+n); // 10 15 17 20
    cout << highestLength(0, tree[n-1]);

    return 0;
}