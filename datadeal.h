#ifndef DATADEAL_H
#define DATADEAL_H
/*
���Ӽ������1.0�������а棩
���ݴ���ģ�飬���ڷ�װ���������ݲ������ݿ����Լ������ݿ���ȡ�����ݵĲ���
����:zwdnet@163.com
����:2011-10-17
���Э�飺GPL3
�����޸ģ�2012-10-05��ֲ��windows��
*/
#include <iostream>
#include <sstream>
#include <string>
#include <sqlite3.h>
#include "database.h"

using namespace std;

//����֧��/�ʲ���ծ���ݽṹ
typedef struct table
{
	int ID;  //��ĿID
	int time; //��Ŀ������ʱ��
	string name; //��Ŀ����
	float amount; //��Ŀ�Ľ������֧����Ϊ��ֵ
	int typeID; //��Ŀ������ID
	string remark; //��ע
}Table;

//��Ŀ�������ݽṹ
typedef struct type
{
	int typeID; //��Ŀ���͵�ID
	string typeName; //��Ŀ���͵�����
}Type;


//����֧������
class Income
{
public:
	Income();
	~Income();
	string getErrorMessage();   //��ó�����Ϣ
	bool setValue(Table & IncomeTable); //��ĳһ������֧����������ݿ�
	bool removeValue(const int & ID);   //����IDֵɾ��ĳһ��
	int getTypeID(const string & typeName); //������Ŀ���������ƻ����Ŀ����ID
	string getTypeName(const int & ID); //��������IDȡ����������
	bool setType(Type & IncomeType); //����Ŀ���Ͳ����������ݿ�
	float getSum(); //��ȡ���ݿ���������֧�����ܺ�
	//��ȡ��beginTime��endTimeʱ�������ݿ���������֧�����ܺ�
	float getSum(const int & beginTime, const int endTime);
	float getSumIncome(); //��ȡ���ݿ�������������ܺ�
	//��ȡ��beginTime��endTimeʱ�������ݿ�����������ܺ�
	float getSumIncome(const int & beginTime, const int endTime);
	float getSumExpense(); //��ȡ���ݿ�������֧�����ܺ�
	//��ȡ��beginTime��endTimeʱ�������ݿ�����֧�����ܺ�
	float getSumExpense(const int & beginTime, const int endTime);
	//����ض���Ŀ�Ľ���ܺ�
	float getSumByType(const int & typeID);
	//��ȡ��beginTime��endTimeʱ�������ݿ��ض�������Ŀ�Ľ���ܺ�
	float getSumByType(const int & beginTime, const int endTime,
			   const int & typeID);
    //��ȡ��beginTime��endTimeʱ�������ݿ�����˰�������õ��ܺ�
    float getSumTax(const int & beginTime, const int endTime);

private:
	float Sum(const string & sql); //��ѯ�����ĺ���,��������Ա�������ã�����get*����
	                              //ֻҪ�ӹ�sql��ѯ�������ˣ������ظ���

private:
	Table IncomeTable; //����֧��������ݽṹ
	DataBase data; //���ݿ⴦����
	string errMsg; //��¼������Ϣ
};

//�ʲ���ծ����
class Investment
{
public:
	Investment();
	~Investment();
	string getErrorMessage();   //��ó�����Ϣ
	bool setValue(Table & InvestmentTable); //��ĳһ���ʲ���ծ��������ݿ�
	bool removeValue(const int & ID);   //����IDֵɾ��ĳһ��
	int getTypeID(const string & typeName); //������Ŀ���������ƻ����Ŀ����ID
	string getTypeName(const int & ID); //��������IDȡ����������
	bool setType(Type & IncomeType); //����Ŀ���Ͳ����������ݿ�
	float getSum(); //��ȡ���ݿ������ʲ���ծ���ܺ�
	//��ȡ��beginTime��endTimeʱ�������ݿ������ʲ���ծ���ܺ�
	float getSum(const int & beginTime, const int endTime);
	float getSumInvestment(); //��ȡ���ݿ��������ʲ����ܺ�
	//��ȡ��beginTime��endTimeʱ�������ݿ������ʲ����ܺ�
	float getSumInvestment(const int & beginTime, const int endTime);
	float getSumDebt(); //��ȡ���ݿ������и�ծ���ܺ�
	//��ȡ��beginTime��endTimeʱ�������ݿ����и�ծ���ܺ�
	float getSumDebt(const int & beginTime, const int endTime);
	//����ض���Ŀ�Ľ���ܺ�
	float getSumByType(const int & typeID);
	//��ȡ��beginTime��endTimeʱ�������ݿ��ض�������Ŀ�Ľ���ܺ�
	float getSumByType(const int & beginTime, const int endTime,
			   const int & typeID);

private:
	float Sum(const string & sql); //��ѯ�����ĺ���,��������Ա�������ã�����get*����
	                              //ֻҪ�ӹ�sql��ѯ�������ˣ������ظ���

private:
	Table InvestmentTable; //�ʲ���ծ������ݽṹ
	DataBase data; //���ݿ⴦����
	string errMsg; //��¼������Ϣ
};
#endif
