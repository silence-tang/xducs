#include <iostream>
using namespace std;
int main()
{
    int n;
    int count=0;
    int Coordinate[100][100]={0};    //先给数组初始化
    cin >> n;
    for(int i=0;i<n;i++)
    {  
        int Pos[4];
        //x1,y1,x2,y2
        cin>>Pos[0]>>Pos[1]>>Pos[2]>>Pos[3];
        for(int j=Pos[0];j<Pos[2];j++)
        for(int k=Pos[1];k<Pos[3];k++)
            Coordinate[j][k]=1;    //给数组赋值，一会进行判断了
    }
    for(int i=0;i<100;i++)
    for(int j=0;j<100;j++)
    if(Coordinate[i][j]==1)
        count++;
    cout<<count<<endl;
    return 0;
}
