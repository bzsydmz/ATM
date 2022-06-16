#pragma once
#include "User.h"
#include <Windows.h>
#include <conio.h>
#include <fstream>

class ATM {
public:
	void run();//����
private:
	void moveCursor(SHORT x, SHORT y);//���ƹ��λ��
	void hideCursor();//���ع��
	void shape();//��ӡATM���߿���״
	string* readFile();//���ļ�
	void writeFile(User x);//д�ļ�
	void loading();//��ʾ�����н���
	void lockcard();//����
	void inputNumber(string& s, int x, int y);//����ʵ�������˺ż����ʱ�Ľ���Ч��
	void inputPassword(string& s, int x, int y);//����ʵ������6λ����ʱ�Ľ���Ч��
	string numFarmat(int x);//����ʵ�ֽ����ʾ��ʽ��ÿ��λһ�������ұ�����λС��
	void createAccount();//Ԥ�ȴ����˻�
	void beginPage();//��ʼҳ��
	User verify(string& x, string& y);//�����֤
	void homePage(User& x);//��ҳ��
	void inquiry(User x);//����ѯ
	void withdraw(User& x);//ȡ�� (�����޶�3000Ԫ/����2��Ԫ)
	void deposit(User& x);//��� (�����޶�10000Ԫ/����5��Ԫ)
	void refreshRecord(User& x);//ˢ�´�ȡ���¼����
	void changePassword(User& x);//�޸�����
	void transfer(User& x);//ת��
	void exitCard();//�˿�
};


