#include <iostream>

using namespace std;

int main()
{

    int T,n, ans=0;
    cin>>T;

    while(T>0)
    {
        cin>>n;
        ans = ans + n/100;
        n = n % 100;
        ans = ans + n/50;
        n = n % 50;
        ans = ans + n/10;
        n = n % 10;
        ans = ans + n/5;
        n = n % 5;
        ans = ans + n/2;
        n = n % 2;
        ans = ans + n;
        cout<<ans<<"\n";
        ans =0;
        T--;

    }
    return 0;
}
