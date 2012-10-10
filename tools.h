#ifndef PUBFUN_H
#define PUBFUN_H
/*
���Ӽ�������1.0�������а棩
�����а�Ҫ�õĹ��ߺ���ģ��
����:zwdnet@163.com
����:2011-10-19
����Э�飺GPL3
�����޸ģ�2012-10-05��ֲ��windows��
*/
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include "pubfun.h"
#include "database.h"
#include "datadeal.h"

using namespace std;

//�������������������ӵĻ�����ʹ��ʱ������˵����δ���壬ԭ��֪
template <typename T>
string num2str(T n);
int str2int(string s);
float str2float(string s);
//��������

//��ȡ�û�����
int getInput(void)
{
	int input = 0;
	int t = 0;
	do
	{
		system("cls");
		if (t > 0)
		{
			cout<<"�����������������!"<<endl;
		}
		t++;
		cout<<"1.��ʼ�����ݿ⣨��ɾ�������ִ����ݣ����ã�)......"<<endl
		    <<"2.����/�ָ����ݿ�................................"<<endl
		    <<"3.����һ������/��֧��¼.........................."<<endl
		    <<"4.ɾ��һ������/��֧��¼.........................."<<endl
		    <<"5.����Ŀ���Ƽ�������/��֧��¼...................."<<endl
		    <<"6.�����ڷ�Χ��������/��֧��¼...................."<<endl
		    <<"7.����һ��Ͷ��/��ծ��¼.........................."<<endl
		    <<"8.ɾ��һ��Ͷ��/��ծ��¼.........................."<<endl
	            <<"9.����Ŀ���Ƽ����ʲ�/��ծ��¼...................."<<endl
		    <<"10.�����ڷ�Χ�����ʲ�/��ծ��¼..................."<<endl
		    <<"11.����һ���籣�ɷѼ�¼.........................."<<endl
		    <<"12.���Ŀǰ���籣״��............................"<<endl
		    <<"13.���ָ�����ڷ�Χ���ֽ�������.................."<<endl
		    <<"14.���ָ�����ڷ�Χ���ʲ���ծ��.................."<<endl
		    <<"15.����ָ�����ڷ�Χ�ڵĲ���״��.................."<<endl
		    <<"16.�����ǰ���ݿ��д洢�ļ�¼������.............."<<endl
		    <<"17.�˳�.........................................."<<endl;
		cout<<"��ӭʹ��!�밴��ʾ����ѡ��:";
		cin>>input;
		if (input >= 1 && input <= 17)
		{
			break;
		}
		else
		{
		    input = 0;
		    /*�����������ڳ�����ʱ������������Ļ���������Ȼ�������ַ�����
		    �������ڣ������ѭ����
		    �ο�:http://hi.baidu.com/our514/blog/item/47183ce936b2512ab80e2db5.html
		    */
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while (1);
	return input;
}

//��ʼ�����ݿ�
void initDataBase(void)
{
	system("cls");
	cout<<"���򼴽���ʼ��ʼ�����ݿ⣬�⽫ɾ�����м�¼����Ӧ��ֻ�ڿ�ʼʹ�ñ���������������������ݵ�ʱ��ʹ�ñ����ܣ�����������ʹ��ǰ�ȱ������ݿ�!!!"<<endl
	    <<"ȷʵҪִ����(yes/no)";
	string answer;
	cin>>answer;
	if (answer == "no")
	{
		return;
	}
	else if (answer == "yes")
	{
		DataBase data;
		data.initDataBase();
		cout<<"���ݿ��ʼ����ϣ�"<<endl;
		cin.get();
		cout<<"�����������......";
		cin.get();
	}
}

//����/�ָ����ݿ⣬����ʹ����linux�������Ҫ��ֲ������ϵͳӦ���޸ģ��������system���)��
void backupDataBase(void)
{
	int choose = 0;
	do
	{
		system("cls");
		cout<<"1.�������ݿ⡣2.�ָ����ݿ�"<<endl;
		cout<<"������ѡ��:";
		cin>>choose;
	}while (choose != 1 && choose != 2);
	if (choose == 1) //�������ݿ�
	{
		cout<<"���뱸���ļ�������·�����ļ���:";
		string file;
		cin>>file;
		string command = "copy ./money.db ";
		command += file;
		system(command.c_str());
	}
	else if (choose == 2)  //�ָ����ݿ�
	{
		cout<<"���뱸���ļ�������·�����ļ���:";
		string file;
		cin>>file;
		string command = "copy ";
		command += file;
		command += " ./money.db";
		system(command.c_str());
	}
	cout<<"������ɣ������������......";
	cin.get();
	cin.get();
}

//�ж�����������Ƿ�Ϸ���Ч
bool judgeTime(int time)
{
	//�Ϸ���ʱ�䷶Χ��1980��1��1�յ�2099��12��31��
	if (time < 19800101 || time > 21000101)
	{
		return false;
	}
	//����ת�����ҳ��·ݺ�����
	int MonthDay = time % (time / 10000);
	int Month = MonthDay / 100;
	int Day = MonthDay % 100;
	if (Month == 0 || Month > 12) //��������Բ���
	{
		return false;
	}
	if (Day == 0) //�������ܵ���0
	{
		return false;
	}
	//�����·ݵ�����
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 ||
	    Month == 10 || Month == 12)
	{
		if (Day > 31)
		{
			return false;
		}
	}
	//���2��
	else if (Month == 2)
	{
		//��ͨ�����꣺ǰ2������
		//���������꣺��2������
		int year = time / 10000;
		if ((year % 4 == 0 && year % 100 != 0) ||
		    (year % 100 == 0 && year % 400 == 0))
		{
			if (Day > 29)
			{
				return false;
			}
		}
		//������
		else
		{
			if (Day > 28)
			{
				return false;
			}
		}
	}
	//���С��
	else
	{
		if (Day > 30)
		{
			return false;
		}
	}
	//���ϼ�鶼ͨ����˵�������ǺϷ���
	return true;
}

//��������֧������
bool inputIncomeData(Table & data)
{
	Income IncomeData;
	data.ID = NULL;
	cout<<"������Ŀ����ʱ��(��ʽ:YYYYMMDD):";
	cin>>data.time;
	if (!judgeTime(data.time))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return false;
	}
	string name;
	cout<<"������Ŀ����:";
	cin>>data.name;
	cout<<"������Ŀ��֧��Ϊ��������Ϊ��:";
	cin>>data.amount;
	string typeName;
	//������е�������Ŀ���ͣ����û�ѡ��
	string sql = "SELECT TypeID from IncomeType";
	QueryResult res;
	DataBase database;
	database.runSQL(sql, res);
	int i = 0;
	for (i = 1; i < res.row+1; i++)
	{
		//ȡ����������
		string TypeName = IncomeData.getTypeName(str2int(res.result[i]));
		cout<<i<<"."<<TypeName<<endl;
	}
	int option; //ѡ��
	cout<<"��������Ŀ���ʹ��룬���Ҫ�����µ����ͣ�������0:";
	cin>>option;
	if (option < 0 || option > res.row+1)
	{
		cout<<"�������!"<<endl;
		cin.get();
		return false;
	}
	if (option == 0)
	{
		cout<<"������Ŀ����:";
		cin>>typeName;
	}
	else
	{
		typeName = IncomeData.getTypeName(str2int(res.result[option]));
	}
	cout<<"������Ŀ��ע(������\"��\"):";
	cin>>data.remark;
	int typeID = IncomeData.getTypeID(typeName);
	if (typeID == -1)
	{
		Type IncomeType;
		IncomeType.typeName = typeName;
		IncomeType.typeID = NULL;
		IncomeData.setType(IncomeType);
		typeID = IncomeData.getTypeID(typeName);
	}
	data.typeID = typeID;
	return true;
}

//����һ������֧����Ŀ
void addIncome(void)
{
	system("cls");
	cout<<"����һ������֧����Ŀ"<<endl;
	Table IncomeTable;
	if (!inputIncomeData(IncomeTable))
	{
		return;
	}
	Income IncomeData;
	IncomeData.setValue(IncomeTable);
	cout<<"��������֧����¼�ɹ��������������......";
	cin.get();
	cin.get();
}

//ɾ��һ������֧��
void removeIncome(void)
{
	system("cls");
	cout<<"ɾ��һ������֧����Ŀ"<<endl;
	cout<<"������Ҫɾ������ĿID(����֪���������������������ܲ�ѯ):";
	int ID = 0;
	cin>>ID;
	Income IncomeData;
	if (!IncomeData.removeValue(ID))
	{
		cout<<"����Ŀ�����ڣ�ɾ��ʧ��!�����������......";
		cin.get();
		cin.get();
		return;
	}
	cout<<"ɾ���ɹ��������������......";
	cin.get();
	cin.get();
	return;
}

//���ߺ����������¼�Ĳ�ѯ���,which=1Ϊ����֧����¼��which=2Ϊ�ʲ���ծ��¼
void outputResult(const string & sql, const int which)
{
	DataBase incomeData;
	QueryResult res;
	if (!incomeData.runSQL(sql, res))
	{
		cout<<"��ѯʧ��!�����������......";
		cin.get();
		cin.get();
		return;
	}
	cout<<"��ѯ���Ϊ:"<<endl;
	int t = 0;
	int index = 0;
	for (int i = res.col; i < (res.row+1)*res.col; i++)
	{
		t++;
		if (t == 1)
		{
			index++;
			cout<<"��"<<index<<"��:";
			cout<<"��ĿID=";
		}
		else if (t == 2)
		{
			cout<<"��Ŀ����=";
		}
		else if (t == 3)
		{
			cout<<"��Ŀ����=";
		}
		else if (t == 4)
		{
			cout<<"��Ŀ���=";
		}
		else if (t == 5)
		{
			//��������ID������������
			QueryResult TypeName;
			string querysql;
			if (which == 1)
			{
				querysql = "SELECT TypeName FROM IncomeType WHERE TypeID = ";
			}
			else if (which == 2)
			{
				querysql = "SELECT TypeName FROM InvestmentType WHERE TypeID = ";
			}
			querysql += res.result[i];
			querysql += ";";
			incomeData.runSQL(querysql, TypeName);
			cout<<"��Ŀ����="<<TypeName.result[1]<<";";
		}
		else if (t == 6)
		{
			cout<<"��ע=";
		}
		if (t != 5)
		{
			cout<<res.result[i]<<";";
		}
		if (t == 6)
		{
			t = 0;
			cout<<endl;
		}
	}
	cout<<"����"<<index<<"����"<<endl;
	cout<<"��ѯ�����������������......";
	cin.get();
	cin.get();
}

//����Ŀ���Ƽ�������֧����¼
void searchIncomeByName(void)
{
	system("cls");
	string name;
	cout<<"����Ŀ���Ƽ�������֧����¼"<<endl;
	cout<<"������Ҫ��������Ŀ����:";
	cin>>name;
	string sql = "SELECT * FROM Income where Name like \"%";
	sql += name;
	sql += "%\";";
	outputResult(sql, 1);
}

//����Ŀ���ڷ�Χ��������֧����¼
void searchIncomeByTime(void)
{
	system("cls");
	int beginTime, endTime;
	cout<<"����Ŀ���ڼ�������֧����¼"<<endl;
	cout<<"������Ҫ��������Ŀ�����ڷ�Χ"<<endl;
	cout<<"��ʼʱ��:";
	cin>>beginTime;
	cout<<"����ʱ��:";
	cin>>endTime;
	if (!judgeTime(beginTime) || !judgeTime(endTime))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return;
	}
	if (beginTime > endTime)
	{
		cout<<"�����ʱ����󣬽������ڱ��벻С�ڿ�ʼʱ�䣬�����������";
		cin.get();
		cin.get();
		return;
	}
	string sql = "SELECT * FROM Income where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	outputResult(sql, 1);
}

//�����ʲ���ծ����
bool inputInvestmentData(Table & data)
{
	Investment InvestmentData;
	data.ID = NULL;
	cout<<"������Ŀ����ʱ��(��ʽ:YYYYMMDD):";
	cin>>data.time;
	if (!judgeTime(data.time))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return false;
	}
	string name;
	cout<<"������Ŀ����:";
	cin>>data.name;
	cout<<"������Ŀ����ծΪ�����ʲ�Ϊ��:";
	cin>>data.amount;
	string typeName;
	//������е�������Ŀ���ͣ����û�ѡ��
	string sql = "SELECT TypeID from InvestmentType";
	QueryResult res;
	DataBase database;
	database.runSQL(sql, res);
	int i = 0;
	for (i = 1; i < res.row+1; i++)
	{
		//ȡ����������
		string TypeName = InvestmentData.getTypeName(str2int(res.result[i]));
		cout<<i<<"."<<TypeName<<endl;
	}
	int option; //ѡ��
	cout<<"��������Ŀ���ʹ��룬���Ҫ�����µ����ͣ�������0:";
	cin>>option;
	if (option < 0 || option > res.row+1)
	{
		cout<<"�������!"<<endl;
		cin.get();
		return false;
	}
	if (option == 0)
	{
		cout<<"������Ŀ����:";
		cin>>typeName;
	}
	else
	{
		typeName = InvestmentData.getTypeName(str2int(res.result[option]));
	}
	cout<<"������Ŀ��ע(������\"��\"):";
	cin>>data.remark;
	int typeID = InvestmentData.getTypeID(typeName);
	if (typeID == -1)
	{
		Type InvestmentType;
		InvestmentType.typeName = typeName;
		InvestmentType.typeID = NULL;
		InvestmentData.setType(InvestmentType);
		typeID = InvestmentData.getTypeID(typeName);
	}
	data.typeID = typeID;
	return true;
}

//����һ���ʲ���ծ��Ŀ
void addInvestment(void)
{
	system("cls");
	cout<<"����һ���ʲ���ծ��Ŀ"<<endl;
	Table InvestmentTable;
	if (!inputInvestmentData(InvestmentTable))
	{
		return;
	}
	Investment InvestmentData;
	InvestmentData.setValue(InvestmentTable);
	cout<<"�����ʲ���ծ��¼�ɹ��������������......";
	cin.get();
	cin.get();
}

//ɾ��һ���ʲ���ծ
void removeInvestment(void)
{
	system("cls");
	cout<<"ɾ��һ���ʲ���ծ��Ŀ"<<endl;
	cout<<"������Ҫɾ������ĿID(����֪���������������������ܲ�ѯ):";
	int ID = 0;
	cin>>ID;
	Investment InvestmentData;
	if (!InvestmentData.removeValue(ID))
	{
		cout<<"����Ŀ�����ڣ�ɾ��ʧ��!�����������......";
		cin.get();
		cin.get();
		return;
	}
	cout<<"ɾ���ɹ��������������......";
	cin.get();
	cin.get();
	return;
}

//����Ŀ���Ƽ����ʲ���ծ��¼
void searchInvestmentByName(void)
{
	system("cls");
	string name;
	cout<<"����Ŀ���Ƽ����ʲ���ծ��¼"<<endl;
	cout<<"������Ҫ��������Ŀ����:";
	cin>>name;
	string sql = "SELECT * FROM Investment where Name like \"%";
	sql += name;
	sql += "%\";";
	outputResult(sql, 2);
}

//����Ŀ���ڷ�Χ�����ʲ���ծ��¼
void searchInvestmentByTime(void)
{
	system("cls");
	int beginTime, endTime;
	cout<<"����Ŀ���ڼ����ʲ���ծ��¼"<<endl;
	cout<<"������Ҫ��������Ŀ�����ڷ�Χ"<<endl;
	cout<<"��ʼʱ��:";
	cin>>beginTime;
	cout<<"����ʱ��:";
	cin>>endTime;
	if (!judgeTime(beginTime) || !judgeTime(endTime))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return;
	}
	if (beginTime > endTime)
	{
		cout<<"�����ʱ����󣬽������ڱ��벻С�ڿ�ʼʱ�䣬�����������";
		cin.get();
		cin.get();
		return;
	}
	string sql = "SELECT * FROM Investment where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	outputResult(sql, 2);
}

//�����籣���˽ɷѼ�¼
void changeSocietyInsurance()
{
	DataBase data;
	data.openDataBase();
	system("cls");
	cout<<"����һ���籣���˽ɷѼ�¼"<<endl;
	cout<<"������Ŀ����ʱ��(��ʽ:YYYYMMDD):";
	int time;
	cin>>time;
	if (!judgeTime(time))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return;
	}

	QueryResult res;
	float old, med, job, house; //���ϡ�ҽ�ơ�ʧҵ��������ĵ�ǰֵ
	string sql = "SELECT * FROM SocietyInsurance;";
	if (!data.runSQL(sql, res) || (res.row == 0 && res.col == 0))
	{
		old = 0.0;
		med = 0.0;
		job = 0.0;
		house = 0.0;
	}
	else
	{
		old = str2float(res.result[6]);
		med = str2float(res.result[7]);
		job = str2float(res.result[8]);
		house = str2float(res.result[9]);
	}
	float newOld, newMed, newJob, newHouse;  //������籣�ɷ�ֵ
	cout<<"�����籣������Ŀ�ı��ֵ��(��ֵΪ�ɷѣ���ֵΪ���ģ�����ҽ������)"
	    <<endl;
	cout<<"���ϱ���:";
	cin>>newOld;
	cout<<"ҽ�Ʊ���:";
	cin>>newMed;
	cout<<"ʧҵ����:";
	cin>>newJob;
	cout<<"ס��������:";
	cin>>newHouse;
	old += newOld;
	med += newMed;
	job += newJob;
	house += newHouse;
	sql = "UPDATE SocietyInsurance Set Time = ";
	sql += num2str(time);
	sql += ", Old = ";
	sql += num2str(old);
	sql += ", Med = ";
	sql += num2str(med);
	sql += ", Job = ";
	sql += num2str(job);
	sql += ", House = ";
	sql += num2str(house);
	sql += ";";
	if (!data.modifyDataBase(sql))
	{
		cout<<"�޸��籣�ɷѼ�¼ʧ��!"<<endl;
	}
	else
	{
		cout<<"�޸ĳɹ���"<<endl;
	}
	data.closeDataBase();
	cout<<"�����������"<<endl;
	cin.get();
	cin.get();
}

//�����ǰ���籣���˽ɷ����
void outputSocientyInsuranceState()
{
	DataBase data;
	data.openDataBase();
	system("cls");
	cout<<"��ǰ�����籣���˽ɷ�����Ϊ:"<<endl;
	QueryResult res;
	float old, med, job, house; //���ϡ�ҽ�ơ�ʧҵ��������ĵ�ǰֵ
	string sql = "SELECT * FROM SocietyInsurance;";
	if (!data.runSQL(sql, res) || (res.col == 0 && res.row == 0))
	{
		cout<<"û�����ĽɷѼ�¼"<<endl;
		cout<<"�����������......"<<endl;
		cin.get();
		cin.get();
		data.closeDataBase();
		return;
	}
	old = str2float(res.result[6]);
	med = str2float(res.result[7]);
	job = str2float(res.result[8]);
	house = str2float(res.result[9]);
	cout<<"���ɷ�ʱ��:"<<res.result[5]<<endl;
	cout<<"���ϱ��ո��˽ɷ��ܶ�:"<<old<<endl;
	cout<<"ҽ�Ʊ��ո��˽ɷ��ܶ�:"<<med<<endl;
	cout<<"ʧҵ���ո��˽ɷ��ܶ�:"<<job<<endl;
	cout<<"ס����������˽ɷ��ܶ�:"<<house<<endl;
	cout<<"�����������......"<<endl;
	cin.get();
	cin.get();
	data.closeDataBase();
}

//���ָ�����ڷ�Χ���ֽ�������
void outputCashFlow(void)
{
	system("cls");
	int beginTime, endTime;
	cout<<"���ָ�����ڷ�Χ���ֽ�������"<<endl;
	cout<<"������Ҫ��������Ŀ�����ڷ�Χ"<<endl;
	cout<<"��ʼʱ��:";
	cin>>beginTime;
	cout<<"����ʱ��:";
	cin>>endTime;
	if (!judgeTime(beginTime) || !judgeTime(endTime))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return;
	}
	Income IncomeData;
	//�����������
	float TotalIncome = 0.0, TotalExpense = 0.0, Total = 0.0;
	TotalIncome = IncomeData.getSumIncome(beginTime, endTime);
	TotalExpense = IncomeData.getSumExpense(beginTime, endTime);
	Total = IncomeData.getSum(beginTime, endTime);

	//���
	string space = "        ";//�������ʱ�ո�
	string line = "----------------------------------------------"; //�ָ���
	system("cls");
	cout<<"��"<<beginTime<<"��"<<endTime<<"���ֽ�������"<<endl;
	cout<<line<<endl;
	cout<<"������="<<TotalIncome<<"Ԫ,����"<<endl;
	string sql = "SELECT TypeID from IncomeType";
	QueryResult res;
	DataBase database;
	database.runSQL(sql, res);
	for (int i = 1; i < res.row+1; i++)
	{
		//ȡ����������
		string TypeName = IncomeData.getTypeName(str2int(res.result[i]));
		if (TypeName == "NULL" || IncomeData.getSumByType(beginTime,
					endTime, str2int(res.result[i])) <= 0)
		{
			continue;
		}
		cout<<space;
		cout<<TypeName<<" = "<<IncomeData.getSumByType(beginTime,
				endTime, str2int(res.result[i]))<<endl;
	}
	cout<<line<<endl;
	cout<<"��֧��="<<fabs(TotalExpense)<<"Ԫ,����"<<endl;
	for (int i = 1; i < res.row+1; i++)
	{
		//ȡ����������
		string TypeName = IncomeData.getTypeName(str2int(res.result[i]));
		if (TypeName == "NULL" || IncomeData.getSumByType(beginTime,
					endTime, str2int(res.result[i])) >= 0)
		{
			continue;
		}
		cout<<space;
		cout<<TypeName<<" = "<<-IncomeData.getSumByType(beginTime,
				endTime, str2int(res.result[i]))<<endl;
	}
	cout<<line<<endl;
	cout<<"����-֧��="<<Total<<endl;
	cout<<line<<endl;
	cout<<"�����ϣ������������......";
	cin.get();
	cin.get();
}

//���ָ�����ڷ�Χ���ʲ���ծ��
void outputBalanceSheet(void)
{
	system("cls");
	int beginTime, endTime;
	cout<<"���ָ�����ڷ�Χ���ʲ���ծ��"<<endl;
	cout<<"������Ҫ��������Ŀ�����ڷ�Χ"<<endl;
	cout<<"��ʼʱ��:";
	cin>>beginTime;
	cout<<"����ʱ��:";
	cin>>endTime;
	if (!judgeTime(beginTime) || !judgeTime(endTime))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return;
	}
	Investment InvestmentData;
	//�����������
	float TotalInvestment = 0.0, TotalDebt = 0.0, Total = 0.0;
	TotalInvestment = InvestmentData.getSumInvestment(beginTime, endTime);
	TotalDebt = InvestmentData.getSumDebt(beginTime, endTime);
	Total = InvestmentData.getSum(beginTime, endTime);

	//���
	string space = "        ";//�������ʱ�ո�
	string line = "----------------------------------------------"; //�ָ���
	system("cls");
	cout<<"��"<<beginTime<<"��"<<endTime<<"���ʲ���ծ��"<<endl;
	cout<<line<<endl;
	cout<<"���ʲ�="<<TotalInvestment<<"Ԫ,����"<<endl;
	string sql = "SELECT TypeID from InvestmentType";
	QueryResult res;
	DataBase database;
	database.runSQL(sql, res);
	for (int i = 1; i < res.row+1; i++)
	{
		//ȡ����������
		string TypeName = InvestmentData.getTypeName(str2int(res.result[i]));
		if (TypeName == "NULL" || InvestmentData.getSumByType(beginTime,
					 endTime, str2int(res.result[i])) <= 0)
		{
			continue;
		}
		cout<<space;
		cout<<TypeName<<" = "<<InvestmentData.getSumByType(beginTime,
				endTime, str2int(res.result[i]))<<endl;
	}
	cout<<line<<endl;
	cout<<"�ܸ�ծ="<<fabs(TotalDebt)<<"Ԫ,����"<<endl;
	for (int i = 1; i < res.row+1; i++)
	{
		//ȡ����������
		string TypeName = InvestmentData.getTypeName(str2int(res.result[i]));
		if (TypeName == "NULL" || InvestmentData.getSumByType(beginTime,
					endTime, str2int(res.result[i])) >= 0)
		{
			continue;
		}
		cout<<space;
		cout<<TypeName<<" = "<<-InvestmentData.getSumByType(beginTime,
				endTime, str2int(res.result[i]))<<endl;
	}
	cout<<line<<endl;
	cout<<"���ʲ�="<<Total<<endl;
	cout<<line<<endl;
	cout<<"�����ϣ������������......";
	cin.get();
	cin.get();
}

/*����ָ�����ڷ�Χ�Ĳ���״��
  �������ݵļ��㷽�������ݽ��;������ڡ��������ƽ̡̳�����ӱ����2007��3�±�����һ�棬���⾭��ó�״�ѧ������*/
void analysisState(void)
{
	system("cls");
	int beginTime, endTime;
	cout<<"����ָ�����ڷ�Χ�Ĳ���״��"<<endl;
	cout<<"������Ҫ��������Ŀ�����ڷ�Χ"<<endl;
	cout<<"��ʼʱ��:";
	cin>>beginTime;
	cout<<"����ʱ��:";
	cin>>endTime;
	if (!judgeTime(beginTime) || !judgeTime(endTime))
	{
		cout<<"�����ʱ����󣬱�����19800101��20991231֮�䣬��Ϊ�Ϸ����ڣ������������";
		cin.get();
		cin.get();
		return;
	}
	string sql;
	DataBase database;
	Income IncomeData;
	Investment InvestmentData;
	string space = "        ";//�������ʱ�ո�
	string line = "----------------------------------------------"; //�ָ���
	system("cls");
	cout<<"��"<<beginTime<<"��"<<endTime<<"�Ĳ���״��"<<endl;
	cout<<line<<endl;
	//��������֧����
	//ӯ��/����
	float RestDeficit = IncomeData.getSum(beginTime, endTime);
	cout<<"����-֧��="<<RestDeficit<<"Ԫ"<<endl;
	if (RestDeficit > 0)
	{
		cout<<"���ڱ�ʱ����ڵ�����֧����ӯ�࣬״̬����"<<endl;
	}
	else if (RestDeficit == 0)
	{
		cout<<"���ڱ�ʱ����ڵ�����֧���պ�ƽ�⣬û��ӯ�࣬Ӧ�����ս�֧��"<<endl;
	}
	else
	{
		cout<<"���ڱ�ʱ����ڵ�����֧�����ֳ������������ս�֧���Ը������Ĳ���״��"<<endl;
	}
	//�����û���ʱ��εĶ����ϵ������������ά���ٿơ��ٶȰٿƵ�
	float SumExpense = IncomeData.getSumExpense(beginTime, endTime); //��ȡʱ�������֧��
	int foodID = IncomeData.getTypeID("��ʳ"); //��ȡʳƷ֧����TypeID
	float SumFoodExpense = IncomeData.getSumByType(beginTime, endTime, foodID); //���ʱ����ڵ�ʳƷ֧������
	float Engel = SumFoodExpense/SumExpense; //��������ϵ��
	cout<<"���ڱ�ʱ����ڵĶ����ϵ��Ϊ:"<<Engel<<",";
	//��������ϵ���������
	if (Engel > 0.6)
	{
		cout<<"��Ŀǰ������ˮƽ����ƶ��״̬��"<<endl;
	}
	else if (Engel <= 0.6 && Engel > 0.5)
	{
		cout<<"��Ŀǰ������ˮƽ�����±�״̬��"<<endl;
	}
	else if (Engel <= 0.5 && Engel > 0.4)
	{
		cout<<"��Ŀǰ������ˮƽ����С��״̬��"<<endl;
	}
	else if (Engel <= 0.4 && Engel > 0.3)
	{
		cout<<"��Ŀǰ������ˮƽ������Ը�ԣ״̬��"<<endl;
	}
	else if (Engel <= 0.3 && Engel > 0.2)
	{
		cout<<"��Ŀǰ������ˮƽ���ڸ�ԣ״̬��"<<endl;
	}
	else
	{
		cout<<"��Ŀǰ������ˮƽ���ڼ��主ԣ״̬��"<<endl;
	}
	cout<<line<<endl;
	//�ʲ���ծ����
	float TotalInvestment, TotalDebt;
	TotalInvestment = InvestmentData.getSumInvestment(beginTime, endTime);
	TotalDebt = InvestmentData.getSumDebt(beginTime, endTime);
	float TotalSub = TotalInvestment - TotalDebt;
	cout<<"�������ڵ����ʲ�="<<TotalInvestment<<"Ԫ"<<endl;
	cout<<"�ܸ�ծ="<<TotalDebt<<"Ԫ"<<endl;
	cout<<"���ʲ�="<<TotalSub<<"Ԫ"<<endl;
	//���㳥������
	float RateOfPay = fabs(TotalSub/TotalInvestment);
	cout<<"���ĳ�������="<<RateOfPay<<",";
	if (RateOfPay > 0.8)
	{
		cout<<"���ĳ����������ߣ�û�г�������Լ������ö�ȣ��������ӽ���Ż�����ṹ"<<endl;
	}
	else if (RateOfPay <= 0.8 && RateOfPay > 0.5)
	{
		cout<<"���ĳ��������ʵ�������ά�����ڵĸ�ծˮƽ��"<<endl;
	}
	else
	{
		cout<<"���ĳ����������ͣ���ζ�����ڵ�������Ҫ����ծ��ά�֣�һ��ծ���ڻ򾭼ò������������ʲ���ծ�����齵��ծ��ˮƽ��"<<endl;
	}
	cout<<line<<endl;
	//���㸺ծ�ʲ�����
	float RateOfDebtInvestment = fabs(TotalDebt/TotalInvestment);
	cout<<"�����ڵĸ�ծ�ʲ�����="<<RateOfDebtInvestment<<",";
	if (RateOfDebtInvestment >= 1)
	{
		cout<<"���ĸ�ծ�����ʲ��������������Ʋ�!"<<endl;
	}
	else if (RateOfDebtInvestment < 1 && RateOfDebtInvestment >= 0.5)
	{
		cout<<"���ĸ�ծ̫�ࡣ"<<endl;
	}
	else
	{
		cout<<"���ĸ�ծ�ʶȡ�"<<endl;
	}
	cout<<line<<endl;
	//���㸺ծ�������
	float TotalIncome = IncomeData.getSumIncome(beginTime, endTime);
	float RateOfDebtIncome = fabs(TotalDebt/TotalIncome);
	cout<<"�����ڵĸ�ծ�������="<<RateOfDebtIncome<<",";
	if (RateOfDebtIncome > 0.4)
	{
		cout<<"�������ڵĸ�ծ������������ȹ����ˣ������ծ��"<<endl;
	}
	else if (RateOfDebtIncome <= 0.4 && RateOfDebtIncome >= 0.36)
	{
		cout<<"�������ڵĸ�ծ����������ı������ˣ���������ֻ����ծ��"<<endl;
	}
	else
	{
		cout<<"�������ڵĸ�ծ����������ı���ƫ�ͣ����ʵ�����ծ��"<<endl;
	}
	cout<<line<<endl;
	//�����Ա���
	int TypeID = InvestmentData.getTypeID("�������ʲ�");
	float FlowRate, FlowInvestment;
	float TotalExpense = IncomeData.getSumExpense(beginTime, endTime);
	if (TypeID == -1)
	{
		FlowRate = 0;
	}
	else
	{
		FlowInvestment = InvestmentData.getSumByType(TypeID);
		FlowRate = fabs(FlowInvestment/TotalExpense);
	}
	cout<<"�����ڵ������Ա���="<<FlowRate<<",";
	if (FlowRate > 6)
	{
		cout<<"���������Ա���̫���ˣ��е��˷ѣ���������Ͷ�ʡ�"<<endl;
	}
	else if (FlowRate <= 6 && FlowRate >= 3)
	{
		cout<<"���������Ա������ˣ����鱣�֡�"<<endl;
	}
	else
	{
		cout<<"���������Ա���̫�ͣ��������Ӵ�����������ʲ�����Ӧ����"<<endl;
	}
	cout<<line<<endl;
	cout<<"�����ϣ������������......";
	cin.get();
	cin.get();
}

//�����ǰ���ݿ��״̬
void outputDatabaseState(void)
{
	system("cls");
	DataBase database;
	QueryResult res;
	string querystr;
	int incomeNum = 0, investmentNum = 0; //�ֱ��¼����֧����Ŀ��Ͷ�ʸ�ծ��Ŀ��¼����
	//��ѯ����֧����¼����
	querystr = "select count(*) from Income;";
	if (!database.runSQL(querystr, res))
	{
		cout<<"��ѯ���ݿ�ʧ�ܣ�"<<endl;
		return;
	}
	else
	{
		incomeNum = str2int(res.result[1]);
	}
	res.clear();
	//��ѯͶ�ʸ�ծ��¼����
	querystr = "select count(*) from Investment;";
	if (!database.runSQL(querystr, res))
	{
		cout<<"��ѯ���ݿ�ʧ�ܣ�"<<endl;
		return;
	}
	else
	{
		investmentNum = str2int(res.result[1]);
	}
	cout<<"��ǰ���ݿ��еļ�¼����Ϊ:"<<endl;
	cout<<"����֧����¼����:"<<incomeNum<<"��"<<endl;
	cout<<"Ͷ�ʸ�ծ��¼����:"<<investmentNum<<"��"<<endl;
	cout<<"��ѯ��ϣ������������......"<<endl;
	cin.get();
	cin.get();
}
#endif