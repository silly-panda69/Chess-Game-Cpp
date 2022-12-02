#include <iostream>
#include <vector>
#include <map>
#include <String>
// #include <typeinfo>
using namespace std;

vector<vector<int>> board={
           //A B C D E F G H
   /*1*/   {1,0,0,0,0,0,0,0},
   /*2*/   {0,0,0,0,0,0,0,0},
   /*3*/   {0,0,0,0,0,0,0,0},
   /*4*/   {0,0,0,0,0,0,0,0},
   /*5*/   {0,0,0,0,0,0,0,0},
   /*6*/   {0,0,0,0,0,0,0,0},
   /*7*/   {0,0,0,0,0,0,0,0},
   /*8*/   {0,0,0,0,0,0,0,0},
};
map<string,int> pos_index={
    {"A",0},
    {"B",1},
    {"C",2},
    {"D",3},
    {"E",4},
    {"F",5},
    {"G",6},
    {"H",7},
};

void move_piece(string original,string next){
    string org=original.substr(0,1);
    int orgint=stoi(original.substr(1,2));
    string nxt=next.substr(0,1);
    int nxtint=stoi(next.substr(1,2));
    board[orgint-1][pos_index[org]]=0;
    board[nxtint-1][pos_index[nxt]]=1;
};

void display(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    string x,y;
    cout<<"x= ";
    getline(cin,x);
    cout<<"y= ";
    getline(cin,y);
    move_piece(x,y);
    display();
    return 0;
}