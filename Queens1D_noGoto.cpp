#include<iostream>
#include<cmath>
using namespace std;
bool ok(int q[],int c)
{
    for (int i = 0; i < c; i++)
    {
        if (q[i] == q[c]|| abs(q[i]-q[c]) == abs(i-c))            {
                return false;
        }
    }
    return true;
};
void print(int q[])
{
    static int count =1;
    cout << "Solution #" << count << ": ";
    count++;
    for (int i = 0; i < 8; i++)
    {
        cout << q[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (q[j] == i)
            {
                cout<<"X ";
            }
            else 
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int q[8]={0};
    int c=0;
    q[c] =0;
    while (c>=0)
    {
        c++;
        if (c ==8)
        {
            print(q);
            c--;
        }
        else 
        {
            q[c] = -1;
        }
        while (c>=0)
        {
            q[c]++;
            if (q[c] == 8)
            {
                c--;
            }
            else if (ok(q,c))
            {
                break;
            }
        }
    }
    return 0;
}