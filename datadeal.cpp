#include "datadeal.h"
#include "pubfun.h"

/********************************************************/
//����֧�����㿪ʼ
Income::Income()
{
	data.openDataBase();
}

Income::~Income()
{
	data.closeDataBase();
}

//��ȡ������Ϣ
string Income::getErrorMessage()
{
	return errMsg;
}

//�����ݲ������ݿ�
bool Income::setValue(Table & IncomeTable)
{
	string sql = "INSERT INTO INCOME VALUES ( ";
	if (IncomeTable.ID == 0)
	{
		sql += "NULL";
	}
	else
	{
		sql += num2str(IncomeTable.ID);
	}
	sql += " , ";
	sql += num2str(IncomeTable.time);
	sql += " , \"";
	sql += IncomeTable.name;
	sql += "\" , ";
	sql += money2str(IncomeTable.amount);
	sql += " , ";
	sql += num2str(IncomeTable.typeID);
	sql += " , ";
	if (IncomeTable.remark == "")
	{
		sql += "NULL";
	}
	else
	{
		sql += "\"";
		sql += IncomeTable.remark;
		sql += "\"";
	}
	sql += ");";
	if (!data.modifyDataBase(sql))
	{
		errMsg = data.getErrorMessage();
		return false;
	}
	return true;
}

//����IDֵɾ��ĳһ��
bool Income::removeValue(const int & ID)
{
	string sql = "DELETE FROM INCOME WHERE ID = ";
	sql += num2str(ID);
	sql += ";";
	if (!data.modifyDataBase(sql))
	{
		errMsg = data.getErrorMessage();
		return false;
	}
	return true;
}

//������Ŀ�������ƻ����Ŀ���ʹ���
int Income::getTypeID(const string & typeName)
{
	QueryResult res;
	string sql = "SELECT TypeID FROM IncomeType WHERE TypeName = \"";
	sql += typeName;
	sql += "\";";
	if (!data.runSQL(sql, res))
	{
		errMsg = data.getErrorMessage();
		return -1;
	}
	else if (res.row == 0 && res.col == 0)
	{
		errMsg = "There isn't any result";
		return -1;
	}
	int ID = str2int(res.result[1]);
	return ID;
}

//��������IDȡ����������
string Income::getTypeName(const int & ID)
{
	QueryResult res;
	string sql = "SELECT TypeName FROM IncomeType WHERE TypeID = ";
	sql += num2str(ID);
	sql += ";";
	if (!data.runSQL(sql, res))
	{
		errMsg = data.getErrorMessage();
		return "NULL";
	}
	else if (res.row == 0 && res.col == 0)
	{
		errMsg = "There isn't any result";
		return "NULL";
	}
	string TypeName = res.result[1];
	return TypeName;
}

//����Ŀ���Ͳ����������ݿ�
bool Income::setType(Type & IncomeType)
{
	string sql = "INSERT INTO IncomeType VALUES( ";
	if (IncomeType.typeID != 0)
	{
		sql += num2str(IncomeType.typeID);
	}
	else
	{
		sql += "NULL";
	}
	sql += " , \"";
	sql += IncomeType.typeName;
	sql += "\");";
	if (!data.modifyDataBase(sql))
	{
		errMsg = data.getErrorMessage();
		return false;
	}
	return true;
}

//��ȡ���ݿ�����������֧�����ܺͣ���������
float Income::Sum(const string & sql)
{
	QueryResult res;
	if (!data.runSQL(sql, res))
	{
		errMsg = data.getErrorMessage();
		return 0; //����0����ʾ����
	}
	else if (res.row == 0 && res.col == 0)
	{
		errMsg = "There isn't any data";
		return -0;
	}
	float sum = 0.0;
	for (int i = 1; i < res.row+1; i++)
	{
		sum += str2float(res.result[i]);
	}
    return sum;
}

//��ȡ���ݿ�����������֧�����ܺͣ���������
float Income::getSum()
{
	string sql = "SELECT Amount FROM Income;";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε�����֧���ܶ�
float Income::getSum(const int & beginTime, const int endTime)
{
	string sql = "SELECT Amount FROM Income Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += ";";
	return Sum(sql);
}

//�������ݿ�������������ܺ�
float Income::getSumIncome(void)
{
	string sql = "SELECT Amount FROM Income WHERE Amount > 0;";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε������ܶ�
float Income::getSumIncome(const int & beginTime, const int endTime)
{
	string sql = "SELECT Amount FROM Income Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += " and ";
	sql += "Amount > 0;";
	return Sum(sql);
}

//�������ݿ�������֧�����ܺ�
float Income::getSumExpense(void)
{
	string sql = "SELECT Amount FROM Income WHERE Amount < 0;";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε������ܶ�
float Income::getSumExpense(const int & beginTime, const int endTime)
{
	string sql = "SELECT Amount FROM Income Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += " and ";
	sql += "Amount < 0;";
	return Sum(sql);
}

//�������ݿ����ض���Ŀ���ܺ�
float Income::getSumByType(const int & TypeID)
{
	string sql = "SELECT Amount FROM Income WHERE TypeID = ";
	sql += num2str(TypeID);
	sql += ";";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε��ض���Ŀ������֧���ܶ�
float Income::getSumByType(const int & beginTime, const int endTime,
		            const int & TypeID)
{
	string sql = "SELECT Amount FROM Income Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += " and ";
	sql += "TypeID = ";
	sql += num2str(TypeID);
	sql += ";";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε�˰�������ܺ�
float Income::getSumTax(const int & beginTime, const int endTime)
{
    return 0.0;
}

/********************************************/
//�ʲ���ծ���ݼ����࿪ʼ

Investment::Investment()
{
	data.openDataBase();
}

Investment::~Investment()
{
	data.closeDataBase();
}

//��ȡ������Ϣ
string Investment::getErrorMessage()
{
	return errMsg;
}

//�����ݲ������ݿ�
bool Investment::setValue(Table & InvestmentTable)
{
	string sql = "INSERT INTO Investment VALUES ( ";
	if (InvestmentTable.ID == 0)
	{
		sql += "NULL";
	}
	else
	{
		sql += num2str(InvestmentTable.ID);
	}
	sql += " , ";
	sql += num2str(InvestmentTable.time);
	sql += " , \"";
	sql += InvestmentTable.name;
	sql += "\" , ";
	sql += money2str(InvestmentTable.amount);
	sql += " , ";
	sql += num2str(InvestmentTable.typeID);
	sql += " , ";
	if (InvestmentTable.remark == "")
	{
		sql += "NULL";
	}
	else
	{
		sql += "\"";
		sql += InvestmentTable.remark;
		sql += "\"";
	}
	sql += ");";
	if (!data.modifyDataBase(sql))
	{
		errMsg = data.getErrorMessage();
		return false;
	}
	return true;
}

//����IDֵɾ��ĳһ��
bool Investment::removeValue(const int & ID)
{
	string sql = "DELETE FROM Investment WHERE ID = ";
	sql += num2str(ID);
	sql += ";";
	if (!data.modifyDataBase(sql))
	{
		errMsg = data.getErrorMessage();
		return false;
	}
	return true;
}

//������Ŀ�������ƻ����Ŀ���ʹ���
int Investment::getTypeID(const string & typeName)
{
	QueryResult res;
	string sql = "SELECT TypeID FROM InvestmentType WHERE TypeName = \"";
	sql += typeName;
	sql += "\";";
	if (!data.runSQL(sql, res))
	{
		errMsg = data.getErrorMessage();
		return -1;
	}
	else if (res.row == 0 && res.col == 0)
	{
		errMsg = "There isn't any result";
		return -1;
	}
	int ID = str2int(res.result[1]);
	return ID;
}

//��������IDȡ����������
string Investment::getTypeName(const int & ID)
{
	QueryResult res;
	string sql = "SELECT TypeName FROM InvestmentType WHERE TypeID = ";
	sql += num2str(ID);
	sql += ";";
	if (!data.runSQL(sql, res))
	{
		errMsg = data.getErrorMessage();
		return "NULL";
	}
	else if (res.row == 0 && res.col == 0)
	{
		errMsg = "There isn't any result";
		return "NULL";
	}
	string TypeName = res.result[1];
	return TypeName;
}

//����Ŀ���Ͳ����������ݿ�
bool Investment::setType(Type & InvestmentType)
{
	string sql = "INSERT INTO InvestmentType VALUES( ";
	if (InvestmentType.typeID != 0)
	{
		sql += num2str(InvestmentType.typeID);
	}
	else
	{
		sql += "NULL";
	}
	sql += " , \"";
	sql += InvestmentType.typeName;
	sql += "\");";
	if (!data.modifyDataBase(sql))
	{
		errMsg = data.getErrorMessage();
		return false;
	}
	return true;
}

//��ȡ���ݿ��������ʲ���ծ�ܺͣ������ʲ�����
float Investment::Sum(const string & sql)
{
	QueryResult res;
	if (!data.runSQL(sql, res))
	{
		errMsg = data.getErrorMessage();
		return 0; //����0����ʾ����
	}
	else if (res.row == 0 && res.col == 0)
	{
		errMsg = "There isn't any data";
		return 0;
	}
	float sum = 0.0;
	for (int i = 1; i < res.row+1; i++)
	{
		sum += str2float(res.result[i]);
	}
	return sum;
}

//��ȡ���ݿ��������ʲ���ծ���ܺͣ������ʲ�����
float Investment::getSum()
{
	string sql = "SELECT Amount FROM Investment;";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε��ʲ���ծ�ܶ�
float Investment::getSum(const int & beginTime, const int endTime)
{
	string sql = "SELECT Amount FROM Investment Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += ";";
	return Sum(sql);
}

//�������ݿ��������ʲ����ܺ�
float Investment::getSumInvestment(void)
{
	string sql = "SELECT Amount FROM Investment WHERE Amount > 0;";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε��ʲ��ܶ�
float Investment::getSumInvestment(const int & beginTime, const int endTime)
{
	string sql = "SELECT Amount FROM Investment Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += " and ";
	sql += "Amount > 0;";
	return Sum(sql);
}

//�������ݿ������и�ծ���ܺ�
float Investment::getSumDebt(void)
{
	string sql = "SELECT Amount FROM Investment WHERE Amount < 0;";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�εĸ�ծ�ܶ�
float Investment::getSumDebt(const int & beginTime, const int endTime)
{
	string sql = "SELECT Amount FROM Investment Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += " and ";
	sql += "Amount < 0;";
	return Sum(sql);
}

//�������ݿ����ض���Ŀ���ʲ���ծ�ܺ�
float Investment::getSumByType(const int & TypeID)
{
	string sql = "SELECT Amount FROM Investment WHERE TypeID = ";
	sql += num2str(TypeID);
	sql += ";";
	return Sum(sql);
}

//�����beginTime��endTimeʱ�ε��ض���Ŀ���ʲ���ծ�ܶ�
float Investment::getSumByType(const int & beginTime, const int endTime,
		            const int & TypeID)
{
	string sql = "SELECT Amount FROM Investment Where Time >= ";
	sql += num2str(beginTime);
	sql += " and Time <= ";
	sql += num2str(endTime);
	sql += " and ";
	sql += "TypeID = ";
	sql += num2str(TypeID);
	sql += ";";
	return Sum(sql);
}
