//区间不相交问题
//最大不相交区间的个数

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];

}

int MaxUnIntersect(vector<vector<int> >& inter){

    sort(inter.begin(), inter.end(), cmp);
    for(int j = 0; j < inter.size(); ++j){
        cout << inter[j][1] << endl;
    }

    int end = inter[0][1];
    int num = 1;
    for(int i = 1; i < inter.size(); ++i){
        if(inter[i][0] >= end){
            num++;
            end = inter[i][1];
        }

    }

    return num;

}

int main(void){
    int a[][5] = {{1, 2}, {1, 4}, {1, 6}};
    vector< vector<int> > w;
    for(int i = 0; i < 3; i++){
        vector<int> op(a[i], a[i] + 2);
        w.push_back(op);
        

    }
    cout << MaxUnIntersect(w);



    return 0;
}