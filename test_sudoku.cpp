#include <iostream>
#include<cstdlib>
#include <string>
#include "randm.hpp"
#include <random>
#include "TextTable.hpp"

using namespace std;
using Random=effolkronium::random_static;



bool row_check(int x,int y,int N,int arr[9][9]) //returns false if the element reoccurs in the current row of the given elemen
{ 
    for(int j=0;j<9;j++)
    {       
        if (j==y)
        {
            continue;
        }
        if(arr[x][j]==N)
        {
            return false;
        }
    }
    return true;
}


bool col_check(int x,int y,int N,int arr[9][9]) //return false if given element is present in any other location of the given column
{
    for(int i=0;i<9;i++)
    {
        if (i==x){continue;}
        if (arr[i][y]==N)
        {
            return false;
        }   
    }
    return true;
}
/* bool row_check(int N,int row,int sudoku[9][9])
    {
            int flag=0;
        
            for(int j=0;j<9;j++)
            {   
                if (N==sudoku[row][j])
                {
                    continue;
                    flag++;
                   

                }
                else
                { if (flag<=1)
                    return true;
                  else
                  {return false;}
                }
            }
           
        
    } */
/* bool col_check(int N,int column,int sudoku[9][9])
{   int flag=0;
    for(int j=0;j<9;j++)
    {
        if (N==sudoku[j][column])
        {
            continue;
            flag++;
        }
        else
        {
            if (flag<=1)
            return true;
            else{return false;}
        }
    }
    
    
} */
/* tuple <int,int> sq_check(int N,int index,int A[9][9])

{   //*******************************************
    if (index==1 || index==4 || index==7)
    {
        for(int i=index-1;i<(index-1)+3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (N==A[i][j])
                {
                    return {i,j}; 
                }
            }
        }
        return {-1,-1};
    }
    //********************************************
    else if (index==2 || index==5 || index==8)
    {
        for(int i=index-2;i<(index-2)+3;i++)
        {
            for(int j=3;j<6;j++)
            {
                if(N==A[i][j])
                {
                    return {i,j};

                }
            }
        }
        return {-1,-1};
    }
    else if (index==3 || index==6 || index==9)
    {
        for(int i=index-3;i<(index-3);i++)
        {
            for(int j=6;j<9;j++)
            {
                if (N==A[i][j])
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
    
} */
void display(int A[9][9])
{
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void display_table(int A[9][9])
{
    TextTable table( '-', '|', '+' );
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            table.add(to_string(A[i][j]));

        }
        table.endOfRow();
    }
    table.setAlignment(2,TextTable::Alignment::RIGHT);
    cout<<endl<<table;
}
/* tuple <int,int> sq_check(int N,int x,int y,int A[9][9])

{ 
    int index=0;
    if(x<3 && y<3)
    {
        index=1; 
    }
    else if ((x<6 && x>=3) && (y<3))
    {
        index=2;
    }
    else if ((x<9 && x>=6) && (y<3))
    {
        index=3;
    }
    else if (x<3 && (y>=3 && y<6))
    {
        index=4;
    }
    else if ((x<6 && x>=3) && (y>=3 && y<6))
    {
        index=5;
    }
    else if((x<9 && x>=3) && (y>=3 && y<6)){
        index=6;
    }
    else if (x<3 && (y>=6 && y<9))
    {
        index=7;
    }
    else if ((x<6 && x>=3) && (y>=6 && y<9))
    {
        index=8;
    }
    else if((x<9 && x>=3) && (y>=6 && y<9)){
        index=9;
    }

    //*******************************************
    if (index==1 || index==4 || index==7)
    {
        for(int i=index-1;i<(index-1)+3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if ((i==x)&&(j==y)){continue;}
                if (N==A[i][j] && A[i][j]==0)
                {
                    continue;
                    return {-1,-1}; 
                }
                else{return {i,j};}
            }
        }
       
    }
    //********************************************
    else if (index==2 || index==5 || index==8)
    {
        for(int i=index-2;i<(index-2)+3;i++)
        {
            for(int j=3;j<6;j++)
            {
                if ((i==x)&&(j==y)){continue;}
                if(N==A[i][j] && A[i][j]==0)
                {
                    continue;
                    return {-1,-1};

                }
                else{return {i,j};}
            }
        }
       
    }
    else if (index==3 || index==6 || index==9)
    {
        for(int i=index-3;i<(index-3);i++)
        {
            for(int j=6;j<9;j++)
            {
                if ((i==x)&&(j==y)){continue;}
                if (N==A[i][j] && A[i][j]==0)
                {
                    continue;
                    return {-1,-1};
                }
                else{return {i,j};}
            }
        } 
       
    
}}*/

bool sq_check(int N,int x,int y,int A[9][9])

{ 
    int index=0;
    if(x<3 && y<3)
    {
        index=1; 
    }
    else if ((x<6 && x>=3) && (y<3))
    {
        index=2;
    }
    else if ((x<9 && x>=6) && (y<3))
    {
        index=3;
    }
    else if (x<3 && (y>=3 && y<6))
    {
        index=4;
    }
    else if ((x<6 && x>=3) && (y>=3 && y<6))
    {
        index=5;
    }
    else if((x<9 && x>=3) && (y>=3 && y<6)){
        index=6;
    }
    else if (x<3 && (y>=6 && y<9))
    {
        index=7;
    }
    else if ((x<6 && x>=3) && (y>=6 && y<9))
    {
        index=8;
    }
    else if((x<9 && x>=3) && (y>=6 && y<9)){
        index=9;
    }

    //*******************************************
    if (index==1 || index==4 || index==7)
    {
        for(int i=index-1;i<(index-1)+3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if ((i==x)&&(j==y)){continue;}
                if (N==A[i][j])
                {
                    return false;
                }
            }
        }
        return true;
       
    }
    //********************************************
    else if (index==2 || index==5 || index==8)
    {
        for(int i=index-2;i<(index-2)+3;i++)
        {
            for(int j=3;j<6;j++)
            {
                if ((i==x)&&(j==y)){continue;}
                if(N==A[i][j])
                {
                    return false;

                }
                
            }
        }
        return true;
       
    }
    else if (index==3 || index==6 || index==9)
    {
        for(int i=index-3;i<(index-3);i++)
        {
            for(int j=6;j<9;j++)
            {
                if ((i==x)&&(j==y)){continue;}
                if (N==A[i][j])
                {
            
                    return false;
                }
                
            }

        }
        return true;
    }
}
int main()
{
    /* int placed[81]; *///holds information regarding the locations in which numbers have been placed
    /* default_random_engine generator;
    uniform_int_distribution<int> distribution(1,9); */
    int sudoku[9][9]={{0,0,0,0,0,0,0,0,},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0}} ;

    /*int count=0;
    while(count<10){

    
    int N= distribution(generator);
    tuple<int,int> ch=check(N,count,sudoku);
    cout<<get<0>(ch)<<" "<<get<1>(ch)<<endl;
    if (get<0>(ch)>=0)
    {
        int N_N=sudoku[get<0>(ch)][get<1>(ch)];
        cout<<"N_N:"<<N_N<<endl;
        tuple<int,int> sq=sq_check(N,sudoku);
        if (get<0>(sq)>=0)
        {
            int x=get<0>(sq);int y=get<1>(sq);
            sudoku[x][y]=N;
            count++;
        }
    }
    }     */
 

    /* 
    
    {
        random_device rd;
        uniform_int_distribution<int> dist(1,9);
        for (int y=0;y<9;y++)
        {
            
            int N=dist(rd);
            if (N==0){continue;}
            cout<<N<<endl;
        if (row_check(x,y,N,sudoku) && col_check(x,y,N,sudoku) && sq_check(N,x,y,sudoku))
        {
            sudoku[x][y]=N;
            
        }
        }
    } */
    
    random_device rd;
        uniform_int_distribution<int> dist(1,9);
        int count=0;
        for(int x=0;x<9;x++)
    {
        
        for (int y=0;y<9;y++)
        {
            
            int N=Random::get(1,9);
            if (N==0){count++;continue;}
            cout<<count<<endl;
        if (row_check(x,y,N,sudoku) && col_check(x,y,N,sudoku) && sq_check(N,x,y,sudoku))
        {
            sudoku[x][y]=N;
            
        }
        }
    }
    
    display(sudoku);
    display_table(sudoku);
  

    return 0;

    }
   
