#include <iostream>
using namespace std;
int a [3000];
int R, sum;
int main ()
{
    a[0]=1;
    int n,b, answ;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>b;
        a[b]=1;
        R=b;
        sum+=b;
        for (int j=0; j<R; j++)
        {
            if (a[j]==1) a[R+j]=1;
        }
    }
    if (sum%2==0) cout<<sum/2<<" "<<sum/2<<endl;
    else
    {
        for (int i=sum/2; i>=0 ; i--)
        {
            if (a[i]==1)
            {
                answ=i;
                break;
            }
        }
        cout<<answ<<" "<<sum-answ<<endl;
    }
    /*
    Пример 1:
    4
    8 10 5 18
    Пример 2:
    5
    11 17 24 2 17
    Пример 3:
    4
    8 10 5 19
    */
}
