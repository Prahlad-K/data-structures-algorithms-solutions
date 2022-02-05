#include <iostream>

using namespace std;

int main()
{

    int T,n;
    cin>>T;

    while(T>0)
    {
        cin>>n;
        if(n<10)
            cout<<"What an obedient servant you are!"<<"\n";
        else
            cout<<-1<<"\n";

        T--;

    }
    return 0;
}
