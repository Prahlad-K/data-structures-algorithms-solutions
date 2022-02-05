#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T,a, b, c;
    cin>>T;

    while(T>0)
    {
        cin>>a>>b>>c;
        if(a>0&&b>0&&c>0&&a+b+c==180)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";

        T--;

    }
    return 0;
}
