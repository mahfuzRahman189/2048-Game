#include<iostream>
#include<vector>
#include<algorithm>
#include <chrono>
#include<random>

using namespace std;
int grid[4][4];

void randomSpawn()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<pair<int,int>>emptysell;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            {
                emptysell.push_back({i,j});
            }
        }
    }
    if(!emptysell.empty())
    {
        int randomIndex=rng()%emptysell.size();
        grid[emptysell[randomIndex].first][emptysell[randomIndex].second]=(rng()%2+1)*2;
    }
}

bool canMove()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)return true;
            if(i<=2&&grid[i][j]==grid[i+1][j])return true;
            if(j<=2&&grid[i][j]==grid[i+1][j])return true;
        }
    }
    return false;
}
void showGrid()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
          // if(grid[i][j]!=0)
            cout<<"\t"<<grid[i][j];
        }
        cout<<endl<<endl;
    }
}

void left()
{
    for(int i=0;i<4;i++)
    {
        int tmp[4]={0};
        int pos=0;

        for(int j=0;j<4;j++)
        {
            if(grid[i][j]!=0)
            {
                if(pos>0&&tmp[pos-1]==grid[i][j])
                {
                    tmp[pos-1]*=2;
                }
                else{
                    tmp[pos++]=grid[i][j];
                }
            }


        }

        for(int j=0;j<4;j++)
        {
            grid[i][j]=tmp[j];
        }

    }
}
void rotateclockwise()
{
    for(int i=0;i<4;i++)
    {
        for(int j=i;j<4;j++)
        {
            swap(grid[i][j],grid[j][i]);
        }
    }
    for(int i=0;i<4;i++)
    {
        reverse(grid[i],grid[i]+4);
    }
}
void up()
{
    rotateclockwise();
    rotateclockwise();
    rotateclockwise();
    left();
    rotateclockwise();

}
void down()
{
    rotateclockwise();
    left();
    rotateclockwise();
    rotateclockwise();
    rotateclockwise();

}
bool check2048(){
     for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==2048)return true;
        }
    }
    return false;
}
void right()
{
    rotateclockwise();
    rotateclockwise();
    left();
    rotateclockwise();
    rotateclockwise();
}
int main()
{
    randomSpawn();
    randomSpawn();
    char cmd;
    while(canMove)
    {
        cout<<"\t      THE 2048 GAME"<<endl;
        showGrid();
        cout<<"Enter move (w: up, s: down, a: left, d: right, q: quit): ";
        cin>>cmd;
        if(cmd=='q')break;
        switch(cmd)
        {
        case 'a':
            left();
            break;
        case 'd':
            right();
            break;
        case 'w':
            up();
            break;
        case 's':
            down();
            break;
        default:
            cout<<"Invalid move. Try again."<<endl;
            continue;
        }
        randomSpawn();
        if(check2048())
        {
            cout<<"You have won!!"<<endl;
            return 0;
        }
        system("cls");
    }
    cout<<"GAME OVER!!"<<endl;

}
