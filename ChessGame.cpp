#include <iostream>
#include <vector>
#include <map>
#include <String>
// #include <typeinfo>
using namespace std;

//Values of each pieces will be known as Sxy
//where S , signifies the name of the piece
//where R=Rook,H=Knight,B=Bishop,K=King,Q=Queen,P=Pawn
//where x , signifies each sides , 1 being black and 2 as white
//and y , signifies each sides duplicate pieces
//and 'A' signifies empty chess squares

vector<vector<string>> board={
           //A B C D E F G H
   /*1*/   {"R11","H11","B11","K11","Q11","B12","H12","R12"},   
   /*2*/   {"P11","P12","P13","P14","P15","P16","P17","P18"},
   /*3*/   {"A","A","A","A","A","A","A","A"},
   /*4*/   {"A","A","A","A","A","A","A","A"},
   /*5*/   {"A","A","A","A","A","A","A","A"},
   /*6*/   {"A","A","A","A","A","A","A","A"},
   /*7*/   {"P21","P22","P23","P24","P25","P26","P27","P28"},
   /*8*/   {"R21","H21","B21","K21","Q21","B22","H22","R22"},
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

//true for white and false for black
int change_sides(bool change){
    if(change){
        return 2;
    }
    else if(!change){
        return 1;
    }
}

string check_enemysides(int moving_hand){
    if(moving_hand==1){
        return "2";
    }
    else if(moving_hand==2){
        return "1";
    }
}

void move_piece(string original,string next,int moving_hand){
    string org=original.substr(0,1);
    int orgint=stoi(original.substr(1,2));
    string nxt=next.substr(0,1);
    int nxtint=stoi(next.substr(1,2));
    string enemy_index=check_enemysides(moving_hand); //returns enemy side number
    string move_index=to_string(moving_hand);//returns the moving side
    if(board[nxtint-1][pos_index[nxt]]=="A"
    &&board[orgint-1][pos_index[org]]!="A") //checking if the move is valid when the space is empty
    {
        string move_piece_index=board[orgint-1][pos_index[org]].substr(1,1);
        cout<<move_piece_index<<"\n";
        if(move_piece_index==move_index){
            string temp=board[orgint-1][pos_index[org]];
            board[orgint-1][pos_index[org]]="A";
            board[nxtint-1][pos_index[nxt]]=temp;
        }else{
            cout<<"Wrong Side\n";
        }
       
    }
    else if(board[nxtint-1][pos_index[nxt]]!="A"&&board[orgint-1][pos_index[org]]!="A"){ //checking if the move is not valid for attacking on enemy
        string enemy=board[nxtint-1][pos_index[nxt]];
        enemy=enemy.substr(1,1);
        if(enemy==enemy_index && enemy!=move_index){
            string temp=board[orgint-1][pos_index[org]];
            board[orgint-1][pos_index[org]]="A";
            board[nxtint-1][pos_index[nxt]]=temp;
        }
        else if(enemy==move_index){
            cout<<"Attacking own piece\n";
        }
    }
    else{
        cout<<"Not a viable move!\n";
    }
};

void display(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=="A"){
                cout<<board[i][j]<<"   ";
            }else{
                cout<<board[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    string x,y;
    bool change=false; 
    display();
    while(true){
        change=!change;
        if(change==true){
            cout<<"White moves !\n";
        }else if(change==false){
            cout<<"Black moves !\n";
        }
        cout<<"x= ";
        getline(cin,x);
        cout<<"y= ";
        getline(cin,y);
        move_piece(x,y,change_sides(change));
        display();
    }
    return 0;
} 
