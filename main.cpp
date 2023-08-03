#include <bits\stdc++.h>
using namespace std;
int score(vector<vector<int> > &matrix){
    int ma=0;
    for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
    ma=max(matrix[i][j],ma);
    }
    }

    return ma;
}
void print(vector<vector<int> > &matrix){
    ofstream fl;
    fl.open("mat2.csv");
    for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
    fl<<matrix[i][j]<<",";
    }
    fl<<endl;
    }
    fl<<endl;
    fl.close();
}

vector<vector<int>> setm(vector<vector<int>> &matrix, int x,int y,int sc){
    matrix[x][y]+=sc;
    return matrix;
}
int main(){
    int row=15;
    int column=15;
    vector<vector<int>>matrix(row, vector<int>(column,0));
    pair<pair<int,int>, int> pr[4];//{position,score}
    int j=0;
    while(j<1000)
    {
        for(int i=0;i<4;i++)
        {
        pr[i].first.first=0 + rand() % (row);
        pr[i].first.second=0 + rand() % (column);
        pr[i].second=1;

        matrix=setm(matrix,pr[i].first.first,pr[i].first.second,1);
        }
        ++j;
    }
    print(matrix);
    int highest=score(matrix);
    cout<<highest;

    return 0;
}