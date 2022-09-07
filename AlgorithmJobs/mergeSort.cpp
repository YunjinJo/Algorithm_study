#include <stdio.h>
#include <iostream>
using namespace std;


void merging(int arr[], int s1, int e1, int s2, int e2)
{
    int p, q; // 시작점 포인터
    int temp[100]; // 합친 결과를 임시 저장
    int temp_inx = 0;

    p = s1;
    q = s2;
    while(p <= e1 && q <= e2)
    {
        if(arr[p] <= arr[q])
        {
            temp[temp_inx++] = arr[p];
            p++;
        }
        else
        {
            temp[temp_inx++] = arr[q];
            q++;
        }
    }
    if(p > e1) // p가 범위 밖으로 나감, q에 아직 값이 남아있음
    {
        for(int i = q; i <= e2; i++)
        {
            temp[temp_inx++] = arr[q];
            q++;
        }
    }
    else
    {
        for(int i = p; i <= e1; i++)
        {
            temp[temp_inx++] = arr[p];
            p++;
        }
    }

    // arr[s1 ~ e2] 까지의 값을 복사
    for(int i = s1; i <= e2; i++)
    {
        arr[i] = temp[i - s1]; // temp는 0부터 시작하기 때문에 i - s1
    }
}

void mergeSort(int arr[], int start, int end)
{
    // arr을 start부터 end까지 합병정렬
    if(start >= end) // 기저조건
    {
        return; // 아무것도 안함
    }
    else
    {
        // 1. 왼쪽 절반을 합병정렬
        // 2. 오른쪽 절반을 합병정렬
        // 3. 둘을 합친다
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid); // 왼쪽 절반 합병정렬
        mergeSort(arr, mid+1, end); // 오른쪽 절반 합병정렬
        merging(arr, start, mid, mid+1, end); // 둘을 합친다.
    }
}


int main()
{
    int n;
    int numbers[100]; // 배열은 포인터

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    mergeSort(numbers, 0, n - 1); // 포인터이기 때문에 함수속에서 바꿔도 적용됨
    for(int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
    return 0;
}