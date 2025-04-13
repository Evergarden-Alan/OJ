#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <numeric>
#include <limits>
// 快速输入输出
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n,vector<int>(n));
    int startx=0,starty=0;
    int loop=n/2;
    int mid = n/2;
    int num = 1;
    int offset = 1;

    while(loop--){
        int i = startx,j=starty;

        for(i;i<n-offset;i++){
            matrix[j][i]=num++;
        }
        for(j;j<n-offset;j++){
            matrix[j][i]=num++;
        }
        for(i;i>startx;i--){
            matrix[j][i]=num++;
        }
        for(j;j>starty;j--){
            matrix[j][i]=num++;
        }
        startx++;
        starty++;
        offset+=1;
    }
    if(n%2!=0){
        matrix[mid][mid]=n*n;
    }

    return matrix;
}

//不涉及算法，单纯的模拟过程，注意循环不定量的界定，并且注意观察模拟对象的规律
int main(){

    generateMatrix(3);

    return 0;
}