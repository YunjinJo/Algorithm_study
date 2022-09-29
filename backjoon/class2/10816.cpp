#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int lower_binary(int *count, int target, int size){
    int start, mid, end;
    start = 0;
    end = size - 1;
    while(end > start){
        mid = (start + end) / 2;
        if(count[mid] >= target) end = mid;
        else start = mid + 1;
    }
    return end;
}

int upper_binary(int *count, int target, int size){
    int start, mid, end;
    start = 0;
    end = size - 1;
    while(end > start){
        mid = (start + end) / 2;
        if(count[mid] > target) end = mid;
        else start = mid + 1;
    }
    return end;
}



int main(){
    int n, m;
    int lower, upper;
    cin >> n;
    int *count = new int[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &count[i]);
    }
    sort(count, count+n);

    cin >> m;
    int *findNumber = new int[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &findNumber[i]);
    }
    
    for(int i = 0; i < m; i++){
        lower = lower_binary(count, findNumber[i], n);
        upper = upper_binary(count , findNumber[i], n);
        if(upper == n - 1 && count[n-1] == findNumber[i]){
            upper++;
        }
        cout << upper - lower << " ";
    }

    return 0;
}