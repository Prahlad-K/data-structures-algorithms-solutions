#include <iostream>

using namespace std;
int count1s(int n)
{
    int c=0;
    while(n)
    {
        n= n&(n-1);
        c++;
    }
    return c;
}
int pos(int n)
{
    int p =0;

    while((n&1)==0)
    {
        n = n>>1;
        p++;
    }
    return p;
}

int main()
{

    int T,a,b, ans;
    cin>>T;

    while(T>0)
    {
        cin>>a>>b;

        if(a==b)
            ans = 0;
        else if(b!=0&&b!=1)
        {int na, nb, p, n=0;
        na = count1s(a);
        nb = count1s(b);
        p = pos(b);

        if(nb>na)
            ans = p-na+nb;
        else
        {
        if(p>(na-nb))
            ans = p-na+nb;
        else
            {
                int x =0;
                while(b)
                {
                    if((b&1)==1)
                    {
                        n++;
                        if((x-n)>=(na-nb))
                        {
                            n+=(x-n)-(na-nb);
                            break;
                        }
                    }
                    x++;
                    b>>=1;
                }
                if(b==0)
                    ans =-1;
                else
                    ans = n;
            }
        }
        }
        else if(b==1)
        {
            if(a==0)
                ans =1;
            else
                ans =-1;
        }
        else
            ans =-1;

        cout<<ans<<"\n";
        T--;
    }
    return 0;
}
