/*
项目：网吧收费业务类
作者：袁野
QQ：360886508（支持QQ邮箱）
*/


#include <Windows.h>
#include <time.h>
#include "sqlite3.h"
#pragma once
class NetPerson
{
public:

	NetPerson();
	NetPerson(CString PersonName);// find person and to set this person
	~NetPerson();
	CString GetPersonName();
	int SetPersonName(CString PersonName);
	CString GetPersonTime();
	CString GetNowTime();
	int SetPersonTime(CString mTime);
	CString GetPersonIDCard();
	int SetPersonIDCard(CString PersonIDCard);
	CString GetPersonComputerID();
	int SetComputerID(CString mComputerID);
	CString GetPersonFee();
	int SetPersonFee(CString dFee);
	CString GetPersonSex();
	int SetPersonSex(CString cSex);
	CString GetPersonState();
	int SetPersonState(CString mState);
	int AddUser();
	int Login();
	int Logout();
private:
	wchar_t Name[255];            //用户姓名
	wchar_t Sex[255];             //性别
	wchar_t IDCard[255];          //身份证号
	wchar_t ComputerID[255];      //机器号
	wchar_t Time[255];            //上机时间
	wchar_t Fee[255];             //当前费用
	wchar_t State[255];           //是否在线 0在线 1 不在线
};

//两种字符类型转换
inline char* UnicodeToAnsi(const wchar_t* szStr);
inline wchar_t* AnsiToUnicode(const char* szStr);