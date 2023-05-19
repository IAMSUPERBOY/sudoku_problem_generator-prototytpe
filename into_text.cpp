#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void write(fstream obj,int A[9][9])
{
    obj.open("problem.txt");
    for(int i=0;i<9;i++)
    {
        obj<<"["
        for(int j=0;j<9;j++)
        {
            obj<<to_string(A[i][j])
            if (j==8)
            {
                continue;
            }
            else{obj<<",";}
        }

        obj<<"],";

    }

}

int main()
{
    fstream problem;
    problem.open("problem.txt");
    



    
}


