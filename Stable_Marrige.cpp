#include<iostream>
using namespace std;
bool ok(int q[],int c){
    int mp[3][3] ={
        {0,2,1},
        {0,2,1},
        {1,2,0}
    };
    int wp[3][3]={
        {2,1,0},
        {0,1,2},
        {2,0,1}
    };
    //curent man:i
    // current woman: q[i]
    // new man: c
    // new woman: q[c]
    for (int i = 0; i < c; i++)
        {
            if (q[c] ==q[i])
            {
                return false;
            }
            //check if current man prefers the new woman && the new woman prefer the current man 
            //Or current woman prefers the new man && new man prefer the current woman
            if (mp[i][q[c]]<mp[i][q[i]] && wp[q[c]][i]<wp[q[c]][c]||wp[q[i]][c]<wp[q[i]][i]&&mp[c][q[i]]<mp[c][q[c]])
            {
                return false;
            }
        }
    return true;
};
void print(int q[])
{
    static int count =1;
    cout<< "Solution #" << count << ": \n";
    count++;
    cout<<"Mam\tWoman"<<endl;
    //print the solution of man and woman
    for (int i = 0; i < 3; i++)
    {
        cout <<i<<"\t"<<q[i] << "\n";
    }
    cout<<endl;
};
int main(){
    int q[3] ={};
    int c=0;
    q[c]= 0;
    while (c>=0)
    {
        c++;
        if (c==3)
        {
            print(q);
            //backtrack
            c--;
        }
        else{
            q[c] = -1;
        }
        while (c>=0)
        {
            q[c]++;
            if (q[c]==3)
            {
                //backtrack
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
