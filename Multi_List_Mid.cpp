#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char c1,c2;
  fstream fmain,fs,fc;
  fmain.open("Main.txt",ios::in|ios::out);
  fs.open("Sindex.txt",ios::in|ios::out);
  fc.open("Cindex.txt",ios::in|ios::out);

  cout<<"Enter the two courses:";
  cin>>c1>>c2;
  char students[3];
  int index=0;
  int i=0,j=0,cpos=-1,spos;
  char ch,cfp='0',sfp,roll,course;

  while(!fc.eof())
  {
   fc.seekg(i*2+1);
   fc>>ch;
   if(ch==c1)
   {cpos=i;break;}
   else
   {i++;}
  }

   if(cpos==-1)
    cout<<"Not found.";
   else
   {
    while(cfp!='@')
    {fmain.seekg(cpos*6);
    fmain>>roll;
    fmain.seekg(cpos*6+2);
    fmain>>sfp;
    fmain.seekg(cpos*6+4);
    fmain>>cfp;
    if(sfp!='@')
    {spos=(int)sfp-48;
    fmain.seekg(spos*6+1);
    fmain>>course;
    if(course==c2)
    {students[index++]=roll;}}
    cpos=(int)cfp-48;
    }
    }

    for(int i=0;i<index;i++)
            cout<<students[i]<<" ";

   }
