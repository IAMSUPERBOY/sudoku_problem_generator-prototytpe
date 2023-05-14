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
    int sudoku[9][9]={{0,0,0,0,0,0,0,0,},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0}} ;

   
    
    random_device rd;
        uniform_int_distribution<int> dist(1,9);
        int count=0;
        for(int x=0;x<9;x++)
    {
        
        for (int y=0;y<9;y++)
        {
            
            int N=Random::get(1,9);
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
   
