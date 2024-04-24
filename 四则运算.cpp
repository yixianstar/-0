#include<iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
using namespace std;
int num,maxNum,ffloat,fout,fkuo;
string op;
double generateNumber() 
{
    if(ffloat)
    {
    	double x=rand()%100+1;
    	double y=x*1.0/100;
    	return rand()%maxNum+y;
	}
	else
		return rand()%maxNum;
}

void generateExpression()
{
	double nnum[5]={0};
	for(int i=0;i<5;i++)
		nnum[i]=generateNumber();
	int len=1;
	int opra=rand()%op.size();
	if(fout)
	{
		ofstream outputFile("output.txt",ios::app);
		if (outputFile.is_open())
		{
			if(fkuo)
			{
				outputFile<<'('<<nnum[0]<<' ';
				for(int i=0;i<op.size();i++)
				{
					if(len==1)
					{
						outputFile<<op[opra]<<' '<<nnum[len++]<<") ";
					}
					else
					{
						opra=(opra+1)%op.size();
						outputFile<<op[opra]<<' '<<nnum[len++]<<' ';
					}
				}
				outputFile<<"= "<<endl;
			}
			else
			{
				outputFile<<nnum[0]<<' ';
				for(int i=0;i<op.size();i++)
				{
					outputFile<<op[opra]<<' '<<nnum[len++]<<' ';
					opra=(opra+1)%op.size();
				}
				outputFile<<"= "<<endl;
			}
			outputFile.close();
			cout << "文件写入成功！" << endl;
		}
		else
		{
			cout<<"无法打开文件"<<endl;
		}
	}
	else
	{
		if(fkuo)
		{
			cout<<'('<<nnum[0]<<' ';
			for(int i=0;i<op.size();i++)
			{
				if(len==1)
				{
					cout<<op[opra]<<' '<<nnum[len++]<<") ";
				}
				else
				{
					opra=(opra+1)%op.size();
					cout<<op[opra]<<' '<<nnum[len++]<<' ';
				}
			}
			cout<<"= "<<endl;
		}
		else
		{
			cout<<nnum[0]<<' ';
			for(int i=0;i<op.size();i++)
			{
				cout<<op[opra]<<' '<<nnum[len++]<<' ';
				opra=(opra+1)%op.size();
			}
			cout<<"= "<<endl;
		}
	}
}

void menu()
{
	cout<<"请输入题的数目: ";
    cin>>num;
    cout<<"请输入您要使用的运算符，+,-,*,/(注意：如有多个运算符请不要用空格隔开)：";
    cin>>op;
    cout<<"请你设置最大数(如十以内，百以内等)：";
	cin>>maxNum;
	cout<<"是否有小数(0代表无，1代表有)：";
	cin>>ffloat;
	cout<<"是否有括号(0代表无，1代表有)：";
	cin>>fkuo;
	cout<<"将输出结果放到哪里(0代表打印台，1代表文件里)：";
	cin>>fout;
    for (int i = 0; i < num; i++) 
	{
        generateExpression();
    }
}

int main() 
{
	int m;
    srand(time(0));
    cout<<"                               欢迎进入小学四则运算自动生成系统"<<endl;
    while(1)
    {
    	cout<<"请选择你要进行的操作： "<<endl;
		cout<<"1、生成四则运算\n"<<"2、退出\n";
		cin>>m;
    	if(m==1)
    	{
    		menu(); 
		}
		else
			exit(0);
	}
    return 0;
}
