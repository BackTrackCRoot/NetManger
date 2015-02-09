#include "stdafx.h"
#include "NetPerson.h"

sqlite3 *mydb = 0;
char *errmsg = 0;

/*
int sqlite3_exec(
sqlite3*,                                   An open database
const char *sql,                            SQL to be evaluated
int(*callback)(void*, int, char**, char**),   Callback function
void *,                                    1st argument to callback
char **errmsg                               Error msg written here
sqlite3描述的是数据库句柄
sql 要执行的SQL语句
callback回调函数
void *回调函数的第一个参数
errmsg错误信息，如果没有SQL问题则值为NULL
);
*/
NetPerson::NetPerson()
{
	int ret = sqlite3_open("E:\\CodeProject\\NetManger\\Debug\\NetManger.db", &mydb);
	if (ret != SQLITE_OK)
	{
		MessageBox(NULL,L"数据库打开失败！",L"数据库错误",MB_OK);
	}
}
NetPerson::NetPerson(CString PersonName)
{
	char **dbresult; int i , nrow, ncolumn , ret;
	ret = sqlite3_open("E:\\CodeProject\\NetManger\\Debug\\NetManger.db", &mydb);
	if (ret != SQLITE_OK)
	{
		MessageBox(NULL, L"数据库打开失败！", L"数据库错误", MB_OK);
	}
	CString sql;
	sql.Append(L"select * from NetPerSon where Name =\'");
	sql.Append(PersonName);
	sql.Append(L"\'");
	//MessageBox(NULL, sql, NULL, MB_OK);
	ret = sqlite3_get_table(mydb,UnicodeToAnsi(sql), &dbresult, &nrow, &ncolumn, &errmsg);
	if (ret != SQLITE_OK)
	{
		::MessageBoxA(NULL, errmsg, NULL, MB_OK);
	}
	//index = ncolumn + 2;
	CString Text;
	for (i = 0; i < nrow; i++)
	{
		if (dbresult[1] == NULL)
		{
			MessageBox(NULL, L"查无此人！请重新输入！", L"查询错误", MB_OK);
		}
		else
		{
			SetPersonName(AnsiToUnicode(dbresult[ncolumn + 1]));
			SetPersonSex(AnsiToUnicode(dbresult[ncolumn + 2]));
			SetPersonIDCard(AnsiToUnicode(dbresult[ncolumn + 3]));
			SetComputerID(AnsiToUnicode(dbresult[ncolumn + 4]));
			SetPersonTime(AnsiToUnicode(dbresult[ncolumn + 5]));
			SetPersonFee(AnsiToUnicode(dbresult[ncolumn + 6]));
			SetPersonState(AnsiToUnicode(dbresult[ncolumn + 7]));
		}
			//lstrcpynW(ComputerID, AnsiToUnicode(dbresult[ncolumn + 4]),255);

			//++index;
		//}
	}
	//MessageBox(NULL, Text, NULL, MB_OK);
	sqlite3_free_table(dbresult);
}

NetPerson::~NetPerson()
{
	sqlite3_close(mydb);
}

CString NetPerson::GetPersonName()
{
	return Name;
}

int NetPerson::SetPersonName(CString PersonName)
{
	lstrcpynW(Name, PersonName,255);
	return 0;
}

CString NetPerson::GetPersonTime()
{
	return Time;
}

CString NetPerson::GetNowTime()
{
	time_t t = time(0);
	CString nowTime;
	struct tm tmTmp;
	localtime_s(&tmTmp, &t);
	nowTime.Format(L"%02d%02d%02d%02d%02d",tmTmp.tm_mon+1, tmTmp.tm_mday, tmTmp.tm_hour, tmTmp.tm_min, tmTmp.tm_sec);
	return nowTime;
}
int NetPerson::SetPersonTime(CString mTime)
{
	lstrcpynW(Time, mTime, 255);
	return 0;
}

CString NetPerson::GetPersonIDCard()
{
	return IDCard;
}


CString NetPerson::GetPersonComputerID()
{

	return ComputerID;
}

int NetPerson::SetPersonIDCard(CString PersonIDCard)
{
	lstrcpynW(IDCard, PersonIDCard, 255);
	return 0;
}

CString NetPerson::GetPersonFee()
{
	return Fee;
}
CString NetPerson::GetPersonSex()
{
	return Sex;
}
int NetPerson::SetPersonSex(CString cSex)
{
	if (cSex == L"boy")
	{
		cSex.Empty();
		cSex.Append(L"男");
	}
	else if (cSex == L"girl")
	{
		cSex.Empty();
		cSex.Append(L"女");
	}
	else if (cSex == L"男")
	{
		cSex.Empty();
		cSex.Append(L"boy");
	}
	else if (cSex == L"女")
	{
		cSex.Empty();
		cSex.Append(L"girl");
	}
	else
	{
		;
	}
	lstrcpynW(Sex, cSex, 255);
	return 0;
}
int NetPerson::SetPersonFee(CString dFee)
{
	lstrcpynW(Fee, dFee, 255);
	return 0;
}

int NetPerson::SetComputerID(CString mComputerID)
{
	lstrcpynW(ComputerID, mComputerID, 255);
	return 0;
}

inline char* UnicodeToAnsi(const wchar_t* szStr)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL);
	return pResult;
}
//将单字节char*转化为宽字节wchar_t*  
inline wchar_t* AnsiToUnicode(const char* szStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen);
	return pResult;
}

int NetPerson::AddUser()
{
	CString sql;
	sql.Empty();
	sql.Format(L"insert into NetPerSon (Name,Sex,IDCard,ComputerID,Time,Fee,State) values (\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\')", Name,Sex,IDCard,ComputerID,Time,Fee,State);
	int ret = sqlite3_exec(mydb, UnicodeToAnsi(sql), NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		::MessageBoxA(NULL, errmsg, NULL, MB_OK);
	}
	//MessageBox(NULL, sql, NULL, MB_OK);
	return 0;
}
int NetPerson::Login()
{
	CString sql;
	sql.Empty();
	sql.Format(L"update NetPerSon set Time = \'%s\', State = \'%s\',ComputerID = \'%s\' where Name = \'%s\'", Time, State,ComputerID,Name);
	MessageBox(NULL, sql, NULL, MB_OK);
	int ret = sqlite3_exec(mydb, UnicodeToAnsi(sql), NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		::MessageBoxA(NULL, errmsg, NULL, MB_OK);
	}
	return 0;
}

int NetPerson::Logout()
{
	char **dbresult; int nrow, ncolumn, ret;
	CString sql;
	sql.Append(L"select Time,Fee from NetPerSon where Name =\'");
	sql.Append(Name);
	sql.Append(L"\'");
	ret = sqlite3_get_table(mydb, UnicodeToAnsi(sql), &dbresult, &nrow, &ncolumn, &errmsg);
	if (ret != SQLITE_OK)
	{
		::MessageBoxA(NULL, errmsg, NULL, MB_OK);
	}
	//for (i = 0; i < nrow; i++)
	SetPersonFee(AnsiToUnicode(dbresult[ncolumn + 1]));
	lstrcpynW(Time, AnsiToUnicode(dbresult[ncolumn]), 255);
	int UseTime = _wtoi(GetNowTime())-_wtoi(Time);
	CString nFree;
	nFree.Format(L"%d", _wtoi(GetPersonFee()) - UseTime);
	SetPersonFee(nFree);
	SetPersonState(L"离线");
	SetPersonTime(L"");
	sql.Empty();
	sql.Format(L"update NetPerSon set Time = \'%s\', State = \'%s\', Fee =\'%s\' where Name = \'%s\'", Time, State,Fee, Name);
	ret = sqlite3_exec(mydb, UnicodeToAnsi(sql), NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		::MessageBoxA(NULL, errmsg, NULL, MB_OK);
	}
	return 0;
}

int NetPerson::SetPersonState(CString mState)
{
	if (mState == L"离线")
	{
		lstrcpynW(State, L"1", 255);
	}
	else if (mState == L"在线")
	{
		lstrcpynW(State, L"0", 255);
	}
	else if (mState == L"0")
	{
		lstrcpynW(State, L"在线", 255);
	}
	else if (mState == L"1")
	{
		lstrcpynW(State, L"离线", 255);
	}
	else
	{
		;
	}
	return 0;
}
CString NetPerson::GetPersonState()
{
	return State;
}
