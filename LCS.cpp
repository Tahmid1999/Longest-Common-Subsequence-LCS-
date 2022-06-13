///Longest Common Subsequence(LCS)


#include <iostream>
#include<vector>
using namespace std;


class Cube{

private:
    int cost;
    char symbol;
    char letter;


public:

  void set_cost(int x){
      cost=x;
      }



  void set_symbol(char c){
        symbol=c;

   }

     void set_letter(char d){
        letter=d;

   }



 int get_cost(){
    return cost;
 }

 char get_symbol(){
    return symbol;
 }

 char get_letter(){
    return letter;
 }

};

///Prototypes
void LCS(string a,string b,int x,int y);
void populate_matrix(Cube **cube,int x,int y,char* first,char* second);
void show_path(Cube** cube,int x,int y);


int main(){
string a;
string b;

cout<<"Enter 1st word :";
cin>>a;

cout<<"Enter 2nd word :";
cin>>b;

int x=a.length();
int y=b.length();

LCS(a,b,x,y);


}






void LCS(string a,string b,int x,int y){

char *first;
char *second;

Cube **cube;
    first=new char[x];
    for(int i=0;i<x;i++) first[i]=a[i];


    second=new char[y];
    for(int j=0;j<y;j++) second[j]=b[j];


    cube=new Cube *[x+1];
    for(int k=0;k<x+1;k++)
        cube[k]=new Cube[y+1];
    populate_matrix(cube,x,y,first,second);
    show_path(cube,x,y);


}


void populate_matrix(Cube **cube,int x,int y,char* first,char* second){



for (int i=0;i<x+1;i++){
    for(int j=0;j<y+1;j++){
        if(i==0){
            cube[i][j].set_cost(0);
            cube[i][j].set_symbol('-');
            cube[i][j].set_letter('-');
        }

        else if(j==0){
             cube[i][j].set_cost(0);
             cube[i][j].set_symbol('-');
             cube[i][j].set_letter('-');
        }

       else{
            if(first[i-1]==second[j-1]){
                cube[i][j].set_cost(cube[i-1][j-1].get_cost()+1);
                cube[i][j].set_symbol('D');
                cube[i][j].set_letter(first[i-1]);
            }
            else{
                if(cube[i][j-1].get_cost()>=cube[i-1][j].get_cost()){
                        cube[i][j].set_cost(cube[i][j-1].get_cost());
                        cube[i][j].set_symbol('L');
                        cube[i][j].set_letter('-');

                }
                else{
                        cube[i][j].set_cost(cube[i-1][j].get_cost());
                        cube[i][j].set_symbol('U');
                         cube[i][j].set_letter('-');

                }

            }

       }

    }
}

}

void show_path(Cube** cube,int x,int y){


char c[x];
for(int i=0;i<x;i++){
    c[i]='.';
}
int a=x;
int b=y;
int j=0;

cout<<"Length :"<<cube[x][y].get_cost()<<endl;
Cube X=cube[a][b];



while(true){
    if(X.get_symbol()=='L'){
            a=a;
            b=b-1;
            X=cube[a][b];

    }
   else if(X.get_symbol()=='U'){
            a=a-1;
            b=b;
            X=cube[a][b];

    }

    else if(X.get_symbol()=='D'){
            c[j]=X.get_letter();
            a=a-1;
            b=b-1;
            X=cube[a][b];
            j++;

    }
   else if(X.get_symbol()=='-') break;
}


cout<<"Sequence:";
for (int i = x-1; i >=0; i--){
        if(c[i]!='.')cout<<c[i];
}
}




