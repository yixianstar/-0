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
			cout << "�ļ�д��ɹ���" << endl;
		}
		else
		{
			cout<<"�޷����ļ�"<<endl;
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
	cout<<"�����������Ŀ: ";
    cin>>num;
    cout<<"��������Ҫʹ�õ��������+,-,*,/(ע�⣺���ж��������벻Ҫ�ÿո����)��";
    cin>>op;
    cout<<"�������������(��ʮ���ڣ������ڵ�)��";
	cin>>maxNum;
	cout<<"�Ƿ���С��(0�����ޣ�1������)��";
	cin>>ffloat;
	cout<<"�Ƿ�������(0�����ޣ�1������)��";
	cin>>fkuo;
	cout<<"���������ŵ�����(0�����ӡ̨��1�����ļ���)��";
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
    cout<<"                               ��ӭ����Сѧ���������Զ�����ϵͳ"<<endl;
    while(1)
    {
    	cout<<"��ѡ����Ҫ���еĲ����� "<<endl;
		cout<<"1��������������\n"<<"2���˳�\n";
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
