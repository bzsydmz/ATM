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
	void addBalance(int x);//余额增加x
	void addDeposited(int x);//存款记录增加x
	void addWithdrawn(int x);//取款记录增加x
	void refresh(time_t x);//刷新纪录
private:
	string account;//账号
	string password;//密码
	string name;//姓名
	string identity;//身份证号
	int balance;//余额
	int deposited;//单日存入的钱
	int withdrawn;//单日取出的钱
	time_t date;//存取款日期
}; 