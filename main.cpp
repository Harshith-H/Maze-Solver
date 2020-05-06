#include <iostream>
#include "stack.h"
using namespace std;
#define N 7


//N=7 -----------Maze=(5,5)
int maze[N][N] = { { 0, 0, 0, 0, 0, 0, 0 },
                   { 0, 1, 1, 1, 1, 1, 0 },
                   { 0, 1, 0, 1, 0, 0, 0 },
                   { 0, 0, 1, 1, 0, 1, 0 },
                   { 0, 0, 1, 1, 0, 1, 0 },
                   { 0, 0, 1, 1, 1, 1, 0 },
                   { 0, 0, 0, 0, 0, 0, 0 } };

class pos
{
public:
    int x, y;
//    char prev = '0';
    pos(){x=1; y=1;}
    pos(int i, int j){x=i; y=j;}
};


bool isValid(int maze[N][N],int x,int y)
{
    if(x >= 0 && y >= 0 && x < N && y < N)
        if(maze[x][y]==1)
            return true;
    return false;
}

stackarr<pos> stk(50);


bool solve(int maze[N][N])
{
    pos i(1,1);     //Start from 0,0
//    char prev=0;
    int endx=N-2;
    int endy=N-2;
    stk.push(i);
//    cout<<"Current Position= "<<i.x<<","<<i.y<<endl;
    int c=0;

    while((i.x!=endx || i.y!=endy) && c<40)
    {
        c++;
        if(isValid(maze, i.x, i.y+1)) //right
        {
            pos j=stk.showtop();
            if(i.x==j.x && (i.y+1)==j.y)
            {
                maze[i.x][i.y]=-1;
                //stk.pop(j);

            }
            i.y+=1;
//            prev='r';
            stk.push(i);
        }

        else if(isValid(maze, i.x+1, i.y)) //down
        {
            pos j=stk.showtop();
            if(i.x==j.x && i.y==j.y)
            {
                maze[i.x][i.y]=-1;
                //stk.pop(j);
            }
            i.x+=1;
//            prev='d';
            stk.push(i);

        }

        else if(isValid(maze, i.x-1, i.y)) //up
        {
            pos j=stk.showtop();
            if(i.x==j.x && i.y==j.y)
            {
                maze[i.x][i.y]=-1;
                //stk.pop(j);
            }
            i.x-=1;
//            prev='u';
            stk.push(i);

        }

        else if(isValid(maze, i.x, i.y-1)) //left
        {
            pos j=stk.showtop();
            if(i.x==j.x && i.y==j.y)
            {
                maze[i.x][i.y]=-1;
                //stk.pop(j);
            }
            i.y-=1;
//            prev='l';
            stk.push(i);

        }
//        cout<<"Current Position= "<<i.x<<","<<i.y<<endl;



    }
    if(c>=40)
        return false;
    return true;

}

void printMaze(int maze[N][N])
{
    cout<<"-----------------------MAZE-----------------------"<<endl<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N; j++)
            cout<<maze[i][j]<<"\t";
        cout<<endl<<endl;
    }
    cout<<endl;
}


int main()
{
    printMaze(maze);

    if(solve(maze))
    {
        cout<<endl<<"Path found"<<endl<<endl;
//        stk.disp();
    }
    else
        cout<<"No solution found"<<endl;
//    printMaze(maze);
    stk.disp();

    return 0;
}
