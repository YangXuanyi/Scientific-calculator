#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class calculate
{
public:
    void get(char x[]);
    void show();
    void cal();
    void setm(int x);
    void setn(int x);
    int getm();
    int getn();
    double sin(double x);
    double cos(double x);
    double square(double x);
    double sqr(double x);
private:
    char a[1000];
    double b[50],s;
    char f[50];
    int k=0,v=0;
    int m,n;
};
class pluss:calculate
{
public:
    void rsystem();

};
void calculate::get(char x[])
{

    double c=0.0,d,e;
    int i,j,m,t=0,t1=0;
    strcpy(a,x);
    m=strlen(a);
    for(i=0; i<m; i++)
    {
        if((a[i]<'0'||a[i]>'9')&&a[i]!='.')
        {
            f[v]=a[i];
            v++;
        }

        if(t==0)
        {
            if(a[i]<='9'&&a[i]>='0')
            {
                c=c*10+(a[i]-'0');

                if((a[i+1]<'0'||a[i+1]>'9')&&a[i+1]!='.')
                {
                    b[k]=c;
                    c=0.0;
                    k++;
                }
                if(a[i+1]=='.')
                {
                    t=1;
                }

            }

        }
        else
        {
            if(a[i]>='0'&&a[i]<='9')
            {
                t1++;
                e=a[i]-'0';
                for(j=0; j<t1; j++)
                {
                    e=e*0.1;
                }
                c=c+e;
                if(a[i+1]<'0'||a[i+1]>'9')
                {
                    b[k]=c;
                    k++;
                    c=0.0;
                    t1=0;
                    t=0;
                }
            }
        }

    }
}

void calculate::show()
{
    cout<<s<<endl;
}

void calculate::cal()
{

    s=b[0];
    int i=1,j;
    if(f[1]=='s')
    {
        if(b[0]==180||b[0]==360||b[0]==90)
        {
            if(b[0]==90)
            {
                s=1;
            }
            else
            {
                s=0;
            }

        }
        else
        {
            s=sin(b[0]);
        }
    }

    if(f[1]=='c')
    {
        if(b[0]==90||b[0]==270)
        {
            s=0;
        }
        else
        {
            s=0+cos(b[0]);
        }
    }
    if(f[1]=='^')
    {
        s=0+square(b[0]);
    }
    if(f[1]=='~')
    {
        s=0+sqr(b[0]);
    }
    if(k>=2)
    {
        for(j=0; j<v-1; j++)
        {

            if(f[j]=='+')
            {
                if(f[j+1]=='s')
                {
                    sin(b[i]);
                    s=s+sin(b[i]);
                    i++;
                }
                if(f[j+1]=='c')
                {
                    s=s+cos(b[i]);
                    i++;
                }
                if(f[j+1]=='^')
                {
                    s=s+square(b[i]);
                    i++;
                }
                if(f[j+1]=='~')
                {
                    s=s+sqr(b[i]);
                    i++;
                }
                if(f[j+1]!='s'&&f[j+1]!='c'&&f[j+1]!='^'&&f[j+1]!='~')
                {
                    s=s+b[i];
                    i++;
                }
            }
            if(f[j]=='-')
            {
                if(f[j+1]=='s')
                {
                    s=s-sin(b[i]);
                    i++;
                }
                if(f[j+1]=='c')
                {
                    s=s-cos(b[i]);
                    i++;
                }
                if(f[j+1]=='^')
                {
                    s=s-square(b[i]);
                    i++;
                }
                if(f[j+1]=='~')
                {
                    s=s-sqr(b[i]);
                    i++;
                }
                if(f[j+1]!='s'&&f[j+1]!='c'&&f[j+1]!='^'&&f[j+1]!='~')
                {
                    s=s-b[i];
                    i++;
                }
            }
            if(f[j]=='*')
            {
                if(f[j+1]=='s')
                {
                    s=s*sin(b[i]);
                    i++;
                }
                if(f[j+1]=='c')
                {
                    s=s*cos(b[i]);
                    i++;
                }
                if(f[j+1]=='^')
                {
                    s=s*square(b[i]);
                    i++;
                }
                if(f[j+1]=='~')
                {
                    s=s*sqr(b[i]);
                    i++;
                }
                if(f[j+1]!='s'&&f[j+1]!='c'&&f[j+1]!='^'&&f[j+1]!='~')
                {
                    s=s*b[i];
                    i++;
                }
            }
            if(f[j]=='/')
            {
                if(f[j+1]=='s')
                {
                    s=s/sin(b[i]);
                    i++;
                }
                if(f[j+1]=='c')
                {
                    s=s/cos(b[i]);
                    i++;
                }
                if(f[j+1]=='^')
                {
                    s=s/square(b[i]);
                    i++;
                }
                if(f[j+1]=='~')
                {
                    s=s/sqr(b[i]);
                    i++;
                }
                if(f[j+1]!='s'&&f[j+1]!='c'&&f[j+1]!='^'&&f[j+1]!='~')
                {
                    s=s/b[i];
                    i++;
                }
            }
        }
    }

}

double calculate::sin(double x)
{
    float a,b=1;
    float i,sinx;
    double q=3.14159;
    x=x*q/180.0;
    a=x;
    sinx=0;
    for(i=1; fabs(a/b)>=1e-6; i++)
    {
        sinx+=a/b;
        a=-a*x*x;
        b=b*(2*i)*(2*i+1);
    }
    return sinx;
}

double calculate::cos(double x)
{
    double i,a,b=2;
    double cosx=1.00;
    double q=3.14159;
    x=x*q/180.0;
    a=-x*x;
    for(i=2; fabs(a/b)>=1e-6; i++)
    {
        cosx+=a/b;
        a=-a*x*x;
        b=b*(2*i-1)*(2*i);
    }
    return cosx;
}

double calculate::square(double x)
{
    double s;
    s=x*x;
    return s;
}

double calculate::sqr(double x)
{
    double s;
    s=sqrt(x);
    return s;
}

void calculate::setm(int x)
{
    m=x;
}
void calculate::setn(int x)
{
    n=x;
}
int calculate::getm()
{
    return m;
}
int calculate::getn()
{
    return n;
}

void pluss::rsystem()
{
    int i=0,n,m;
    cin>>m>>n;
    int a[100];
    while(m)
    {
        a[i]=m%n;
        m=m/n;
        i++;
    }
    for(i=i-1; i>=0; i--)
    {
        if(a[i]==10)
            printf("A");
        if(a[i]==11)
            printf("B");
        if(a[i]==12)
            printf("C");
        if(a[i]==13)
            printf("D");
        if(a[i]==14)
            printf("E");
        if(a[i]==15)
            printf("F");
        if(a[i]!=10&&a[i]!=11&&a[i]!=12&&a[i]!=13&&a[i]!=14&&a[i]!=15)
            printf("%d",a[i]);
    }
}

int main()
{
    cout<<"********----------欢迎使用科学计算器--------------*****"<<endl;
    cout<<"********-----请在主菜单中选择所要计算的类型-------*****"<<endl;
    cout<<endl;
    cout<<"如果进行普通的四则运算，平方，开方，三角函数，请输入 1"<<endl;
    cout<<"如果要进行进制转换的运算请先输入 2,进行计算器功能选择."<<endl;
    cout<<endl;
    cout<<"温馨提示，如进行1运算，请输入计算式，例如：6*5-5+s30-c30="<<endl;
    cout<<"****************一定要输入等号***************************"<<endl;
    cout<<"如果进行2运算，请输入所要转换的十进制数，转换的R进制"<<endl;
    cout<<"在表达式中s代表sin，c代表cos，~代表平方，^代表开方。"<<endl;

    int rt;
    char x[100];
    calculate aa[100];
    pluss bb[100];
    for(int j=0; j<100; j++)
    {
        scanf("%d",&rt);
        if(rt==1)
        {
            cout<<"正在使用普通计算机功能: "<<endl;
            for(int i=0; i<100; i++)
            {
                scanf("%c",&x[i]);
                if(x[i]=='=')
                {
                    break;
                }
            }
            aa[j].get(x);
            aa[j].cal();
            aa[j].show();
        }
        if(rt==2)
        {
            cout<<"正在使用进制转换计算功能："<<endl;
            bb[j].rsystem();
        }
        if(rt==3)
        {
            cout<<"成功退出程序"<<endl;
            break;
        }
    }
    delete []bb;
    delete []aa;
    return 0;
}


//s60= c30=
//2.5*2.5-1.25+s0+c90+~25+^5=35
//15 2
