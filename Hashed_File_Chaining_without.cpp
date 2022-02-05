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
{ofstream f1,f2;
f1.open("VHash_WOR.txt");
f2.open("VHash_index.txt");
for(int i=0;i<n*13;i++)
    {f1<<'@';}
for(int i=0;i<n*4;i++)
    {f2<<'@';}

f1.close();
f2.close();
}

bool read(fstream &f1,int r,char* tb)
{char ch;
f1.seekg((r*13),ios::beg);
int i=0;
do
{f1>>ch;
if(ch!='@')
{tb[i]=ch;
i++;}
}while(i<13&&ch!='@');
tb[13]='\0';
if(i==13)
    return true;
else
    return false;}

void write(fstream &f1,int r,char *tb)
{char ch;
f1.seekp((r*13));
int i=0;
do
{f1<<tb[i];
i++;}while(i<13);
}

int key(char* buff)
{char ch;ch=buff[0];
int i=(int)ch-48;ch=buff[1];
int j=(int)ch-48;
return(i*10+j);
}

char* convtochar(int k)
{int x=k,r;char* rolln;int i=0;
rolln=new char;
while(x>0)
{r=x%10;
rolln[i]=(char)(r+48);
i++;
x=x/10;
}
rolln[i]='\0';
return rolln;
}

int retpos(fstream &f2,int r,int k,int n)
{int c=0,tf,tb,ret,flag=0;char *ch,fp,*roll;
ch=new char;
do
{f2.seekg(r*4);
tf=r;
f2>>ch[0];
if(ch[0]=='@')
{ret=r;flag=1;}
else
{
f2>>ch[1];
f2>>fp;
if(fp=='@')
    {r=(r+1)%n;c++;}
else
    {r=(int)fp-48;}}
}while(flag==0);

f2.seekg(ret*4);
roll=convtochar(k);
f2<<roll[1]<<roll[0];
if(c>0)
{
f2.seekg(((tf-c+n)%n)*4+2);
f2<<(char)(tf+48);
f2.seekg(tf*4+3);
f2<<(char)((tf-c+n)%n+48);}

cout<<ret<<" ret\n";
return ret;
}

void add(fstream &f1,fstream &f2,char *buff,int n,int flag)
{int r,k,c=0,x;
char* tbuff;tbuff=new char;
k=key(buff);
r=k%n;
if(flag==0)
{x=retpos(f2,r,k,n);}
else
    x=r;
write(f1,x,buff);
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
r=roll%n;fstream f2;
f2.open("Vhash")
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
add(f,f2,temp,n,1);
cout<<"Update?:";
cin>>st;}
cout<<"Delete?:";
cin>>st;
if(st!='n')
    make_default_pos(f,r);
cout<<"Deleted Successfully!\n";
}

else if(c==n)
    cout<<"Record not found.";}

int main()
{char x,st;int n,roll;
cout<<"Enter size of file:";
cin>>n; int i=0;
make_default(n);
fstream f1,f2;
do
{*(b.buf)='\0';
f1.open("VHash_WOR.txt",ios::in|ios::out);
f2.open("VHash_index.txt",ios::in|ios::out);
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
add(f1,f2,b.buf,n,0);i++;
f1.close();
f2.close();
cout<<"Continue?:";
cin>>x;
}while(i<n&&x!='n');

f1.open("VHash_WOR.txt",ios::in|ios::out);
cout<<"Search?:";
cin>>st;
while(st!='n')
{cout<<"Enter rollno:";
cin>>roll;
search(f1,roll,n);
cout<<"Search?:";
cin>>st;}

f1.close();

return 0;
}
