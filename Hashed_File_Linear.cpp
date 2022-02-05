#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
struct stud{
char rollno[3];
char name[10];
char marks[3];}s;

class Buffer{public:
Buffer();
char *buf;
void pack(char*, char*,int);
}b;

Buffer::Buffer()
{buf=new char;
*buf='\0';}

void Buffer::pack(char *s1,char *s2,int t)
{if(t==2)
   {for(int i=strlen(s2);i<9;i++)
   strcat(s2,"*");}
s1=strcat(s1,s2);
}


void make_default(int n)
{ofstream f;
f.open("VHash.txt",ios::app);
for(int i=0;i<n*13;i++)
    f<<'@';
f.close();
}

bool read(fstream &f,int r,char* tb)
{char ch;
f.seekg((r*13),ios::beg);
int i=0;
do
{f>>ch;
if(ch!='@')
{tb[i]=ch;
i++;}
}while(i<13&&ch!='@');
tb[13]='\0';
if(i==13)
    return true;
else
    return false;}

void write(fstream &f,int r,char *tb)
{char ch;
cout<<r<<"r";
f.seekp((r*13));
int i=0;

do
{f<<tb[i];
i++;}while(i<13);
}

int key(char* buff)
{char ch;ch=buff[0];
int i=(int)ch-48;ch=buff[1];
int j=(int)ch-48;
return(i*10+j);
}

void add(fstream &f,char *buff,int n)
{int r,k,c=0;
char* tbuff;tbuff=new char;
k=key(buff);
r=k%n;

while(read(f,r,tbuff)&&c<n)
{r=(r+1)%n;c++;}
write(f,r,buff);
}

char* giveroll(char* tr)
{char* rolln;rolln=new char;
rolln[0]=tr[0];
rolln[1]=tr[1];
rolln[2]='\0';
    return rolln;
}

void make_default_pos(fstream &f,int r)
{f.seekp(r*13);
    for(int i=r*13;i<(r+1)*13;i++)
    f<<'@';
}

void search(fstream& f,int roll,int n)
{int r,c=0,k;char *tbuff;tbuff=new char;char st;
r=roll%n;
do
{if(read(f,r,tbuff))
{k=key(giveroll(tbuff));}
if(k!=roll)
r=(r+1)%n;
c++;}while(k!=roll&&c<n);
if(k==roll)
{cout<<"Record found:"<<tbuff<<"\n";
cout<<"Update?:";
cin>>st;
while(st!='n')
{make_default_pos(f,r);
cout<<"Name:";
cin>>s.name;
cout<<"Marks:";
cin>>s.marks;
char *temp;temp=new char;*temp='\0';
b.pack(temp,giveroll(tbuff),1);
b.pack(temp,s.name,2);
b.pack(temp,s.marks,3);
add(f,temp,n);
cout<<"Update?:";
cin>>st;
}}
else if(c==n)
    cout<<"Record not found.";}


int main()
{char x,st;int n,roll;fstream f;
cout<<"Enter size of file:";
cin>>n; int i=0;
make_default(n);
do
{*(b.buf)='\0';
fstream f;
f.open("VHash.txt",ios::in|ios::out);
cout<<"Rollno:";
cin>>s.rollno;
cout<<"Name:";
cin>>s.name;
cout<<"Marks:";
cin>>s.marks;
b.pack(b.buf,s.rollno,1);
b.pack(b.buf,s.name,2);
b.pack(b.buf,s.marks,3);
cout<<b.buf<<"\n";
int l=strlen(b.buf);
add(f,b.buf,n);i++;
f.close();
cout<<"Continue?:";
cin>>x;
}while(i<n&&x!='n');

f.open("VHash.txt",ios::in|ios::out);
cout<<"Search?:";
cin>>st;
while(st!='n')
{cout<<"Enter rollno:";
cin>>roll;
search(f,roll,n);
cout<<"Search?:";
cin>>st;}
f.close();
return 0;
}
