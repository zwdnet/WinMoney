/*
���Ӽ������1.0�������а棩
������
����:zwdnet@163.com
����:2011-10-16
���Э�飺GPL3
�����޸ģ�2012-10-05��ֲ��windows��
*/
#include <iostream>
#include "database.h"
#include "datadeal.h"
#include "tools.h"

using namespace std;

int main()
{
	DataBase money; //���ݿ���
	int input = 0;
	while (input != 19)
	{
		input = getInput();
		switch (input)
		{
		case 1:
			initDataBase(); //��ʼ�����ݿ�
			break;
		case 2:
			backupDataBase(); //����/�ָ����ݿ�
			break;
		case 3:
			addIncome();     //����һ������֧��
			break;
		case 4:
			removeIncome();  //ɾ��һ������֧��
			break;
		case 5:
			searchIncomeByType(); //����Ŀ���ͼ�������֧����¼
			break;
		case 6:
			searchIncomeByTime(); //����Ŀ���ڼ�������֧����¼
			break;
		case 7:
			addInvestment(); //����һ���ʲ���ծ
			break;
		case 8:
			removeInvestment();  //ɾ��һ���ʲ���ծ
			break;
		case 9:
			searchInvestmentByType(); //����Ŀ���ͼ����ʲ���ծ��¼
			break;
		case 10:
			searchInvestmentByTime(); //����Ŀ���ڼ����ʲ���ծ��¼
			break;
		case 11:
			changeSocietyInsurance();  //�����籣��¼
			break;
		case 12:
			outputSocientyInsuranceState(); //����籣״̬
			break;
		case 13:
			outputCashFlow();   //���ָ�����ڷ�Χ���ֽ�������
			break;
		case 14:
			outputBalanceSheet(); //���ָ�����ڷ�Χ���ʲ���ծ��
			break;
		case 15:
			analysisState(); //��������״��
			break;
		case 16:
			outputDatabaseState(); //�����ǰ���ݿ�洢�ļ�¼����
			break;
        case 17:
            yearStatics(); //������ͳ����Ϣ
            break;
        case 18:
            taxStatus(); //���ָ�����ڷ�Χ�ڵ�˰����Ϣ��
		default:
			break;
		}
	}
	cout<<"��лʹ�ã��ټ���"<<endl;
	return 0;
}
