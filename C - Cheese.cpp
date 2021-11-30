/*
美味しさを最大化するために美味しさを降順で出力する
マージソートを降順に調整
美味しさが同一の場合は量が多い方を優先して使用する
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>

#define MAX 400000
#define SENTINEL -1
using namespace std;

struct Cheese {
    int taste;
    int weight;
};

struct Cheese L[MAX / 2 + 2], R[MAX / 2 + 2];

// ソート実行
void merge(struct Cheese A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid -left;
    int n2 = right - mid;
    for ( i = 0; i < n1; i++ ) L[i] = A[left + i];
    for ( i = 0; i < n2; i++ ) R[i] = A[mid + i];
    L[n1].taste = R[n2].taste = L[n1].weight = R[n2].weight = SENTINEL;
    i = j = 0;
    for ( k = left; k < right; k++ ) {
        // 降順でソート
        // 美味しさが同じ場合は重量が多い方を上へ
        if ( L[i].taste > R[j].taste ) {
            A[k] = L[i++];
        } else if ( ( L[i].taste == R[j].taste ) && ( L[i].weight > R[j].weight ) ) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(struct Cheese A[], int n, int left, int right) {
    int mid;
    if ( left + 1 < right ) {
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, left, mid, right);
    }
}

// 美味しさをw[g]以下で出力する
// 配列は降順である必要がある
long long tasteCheck(int n, int w, struct Cheese A[]) {
    long long result = 0;
    int rest = w;   // 残重量
    for ( int i = 0; i < n; i++ ) {
        long long b = A[i].weight;
        if ( b <= rest ) {
            rest -= b;
            result += A[i].taste * b;
        }
        else {
            b = rest;
            result += A[i].taste * b;
            //cout << A[i].taste << " X " << rest << " → ";
            return result;
        }
        //cout << A[i].taste << " X " << b << " → ";
        //cout << result << endl;
    }
    cout << endl;
    return result;
}

int main() {
    int n, w;
    struct Cheese A[MAX];
    cin >> n;
    cin >> w;
    for ( int i = 0; i < n; i++ ) {
        cin >> A[i].taste;
        cin >> A[i].weight;
    }
    // おいしさが大きいチーズを先に使う
    mergeSort(A, n, 0, n);
    cout << tasteCheck(n, w, A) << endl;

    return 0;
}