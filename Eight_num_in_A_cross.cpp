#include<iostream>
using namespace std;
bool ok(int cross[],int cap)
{
    int adj[8][5]= {{-1},{0,-1},{0,-1},{0,1,2,-1},{0,1,3,-1},{1,4,-1},{2,3,4,-1},{3,4,5,6,-1}};
    for (int i =0;i<cap;i++)
    {
        if (cross[i] == cross[cap])
        {
            return false;
        }
    }
    for (int j=0; adj[cap][j] != -1; j++)
    {
        if (abs(cross[cap]-cross[adj[cap][j]])== 1)
    {
        return false;
    }
    }
    return true;
};
void print(int cross[])
{
    static int solution = 0;
    cout << "Solution" << ++solution << endl;
    cout << " " << cross[0] << cross[1] << endl;
    cout<<cross[2]<<cross[3]<<cross[4]<<cross[5]<<endl;
    cout<<" "<<cross[6]<<cross[7]<<endl;
    cout<<endl;
};
void eightNumber(int cross[],int cap)
{
    if (cap ==8)
    {
        print(cross);
    }
    else
        for (cross[cap]=1;cross[cap]<=8;cross[cap]++)
        {
            if (ok(cross,cap))
            {
                eightNumber(cross,cap+1);  
            }          
        }
};
int main(){
    int cross[8];
    eightNumber(cross,0);
    return 0;
}