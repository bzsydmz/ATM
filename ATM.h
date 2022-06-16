#pragma once
#include "User.h"
#include <Windows.h>
#include <conio.h>
#include <fstream>

class ATM {
public:
	void run();//运行
private:
	void moveCursor(SHORT x, SHORT y);//控制光标位置
	void hideCursor();//隐藏光标
	void shape();//打印ATM机边框形状
	string* readFile();//读文件
	void writeFile(User x);//写文件
	void loading();//显示加载中界面
	void lockcard();//锁卡
	void inputNumber(string& s, int x, int y);//用于实现输入账号及金额时的界面效果
	void inputPassword(string& s, int x, int y);//用于实现输入6位密码时的界面效果
	string numFarmat(int x);//用于实现金额显示格式，每三位一个逗号且保留两位小数
	void createAccount();//预先创建账户
	void beginPage();//起始页面
	User verify(string& x, string& y);//身份验证
	void homePage(User& x);//主页面
	void inquiry(User x);//余额查询
	void withdraw(User& x);//取款 (单笔限额3000元/单日2万元)
	void deposit(User& x);//存款 (单笔限额10000元/单日5万元)
	void refreshRecord(User& x);//刷新存取款记录数据
	void changePassword(User& x);//修改密码
	void transfer(User& x);//转账
	void exitCard();//退卡
};


