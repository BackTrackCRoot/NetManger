/*
��Ŀ�������շ�ҵ����
���ߣ�ԬҰ
QQ��360886508��֧��QQ���䣩
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
	wchar_t Name[255];            //�û�����
	wchar_t Sex[255];             //�Ա�
	wchar_t IDCard[255];          //���֤��
	wchar_t ComputerID[255];      //������
	wchar_t Time[255];            //�ϻ�ʱ��
	wchar_t Fee[255];             //��ǰ����
	wchar_t State[255];           //�Ƿ����� 0���� 1 ������
};

//�����ַ�����ת��
inline char* UnicodeToAnsi(const wchar_t* szStr);
inline wchar_t* AnsiToUnicode(const char* szStr);