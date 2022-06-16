#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class User {
public:
	User(string a, string p, string n, string i, int b, int d = 0, int w = 0, int t = 0);
	string getAccount();
	string getPassword();
	string getName();
	string getIdentity();
	int getBalance();
	int getDeposited();
	int getWithdrawn();
	time_t getDate();
	void setPassword(string x);
	void addBalance(int x);//�������x
	void addDeposited(int x);//����¼����x
	void addWithdrawn(int x);//ȡ���¼����x
	void refresh(time_t x);//ˢ�¼�¼
private:
	string account;//�˺�
	string password;//����
	string name;//����
	string identity;//���֤��
	int balance;//���
	int deposited;//���մ����Ǯ
	int withdrawn;//����ȡ����Ǯ
	time_t date;//��ȡ������
}; 