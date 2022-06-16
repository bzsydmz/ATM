
#include "ATM.h"

void ATM::moveCursor(SHORT x, SHORT y) {
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
void ATM::hideCursor() {
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hOut, &cursor);
}
void ATM::shape() {
	moveCursor(0, 0);
	cout << "++--------------------------------------++" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "||                                      ||" << endl;
	}
	cout << "++--------------------------------------++" << endl;
	cout << "|                                        |" << endl;
	cout << "|   [1][2][3]              =====         |" << endl;
	cout << "|   [4][5][6]              �忨��        |" << endl;
	cout << "|   [7][8][9]             ________       |" << endl;
	cout << "|   [0][ȷ��]            [________]      |" << endl;
	cout << "|                         ��ȡ���       |" << endl;
	cout << "+----------------------------------------+" << endl;
}
string* ATM::readFile() {
	ifstream fin;
	fin.open("Users4.txt", ios::in);
	if (!fin.is_open()) {
		shape();
		moveCursor(3, 3);
		cout << "ϵͳ��������ϵ������ԱѰ�������" << endl;
		moveCursor(0, 20);
		exit(0);
	}
	string* users = new string[4];
	for (int i = 0; i < 4; i++) {
		getline(fin, users[i]);
	}
	fin.close();
	return users;
}
void ATM::writeFile(User x) {
	string* users = readFile();
	ofstream fout;
	fout.open("Users4.txt", ios::out);
	for (int i = 0; i < 4; i++) {
		if (users[i].substr(0, 19) != x.getAccount())
			fout << users[i] << endl;
		else {
			fout << x.getAccount() << x.getPassword() << x.getIdentity();
			string balance = to_string(x.getBalance());
			int size = balance.size();
			for (int j = 0; j < 5 - size; j++) {
				balance = '0' + balance;
			}
			string deposited = to_string(x.getDeposited());
			size = deposited.size();
			for (int j = 0; j < 5 - size; j++) {
				deposited = '0' + deposited;
			}
			string withdrawn = to_string(x.getWithdrawn());
			size = withdrawn.size();
			for (int j = 0; j < 5 - size; j++) {
				withdrawn = '0' + withdrawn;
			}
			string date = to_string(x.getDate());
			fout << balance << deposited << withdrawn << date << x.getName() << endl;
		}
	}
	fout.close();
}
void ATM::loading() {
	shape();
	moveCursor(3, 5);
	cout << "������";
	for (int i = 0; i < 4; i++) {
		cout << ".";
		Sleep(300);
	}
	Sleep(300);
	shape();
}
void ATM::lockcard() {
	shape();
	moveCursor(3, 2);
	cout << "���������������" << endl;
	cout << "|| �����˻��ѱ�����" << endl;
	cout << "|| ����ϵ������ԱѰ�����" << endl;
	moveCursor(0, 20);
	exit(0);
}
void ATM::inputNumber(string& s, int x, int y) {
	int i = 0;
	while (1) {
		moveCursor(x, y);
		cout << "+-------------------+";
		moveCursor(x, y + 1);
		cout << "|" << s;
		for (int j = 0; j < 19 - (int)s.size(); j++) {
			cout << " ";
		}
		cout << "|";
		moveCursor(x, y + 2);
		cout << "+-------------------+" << endl;
		char t = _getch();
		if (i < 19 && t >= '0' && t <= '9') {
			s += t;
			i++;
		}
		else if (t == '\b' && s.size()) {
			i--;
			s = s.substr(0, i);
		}
		else if (t == '\r' && s.size())
			break;
		if (i >= 1) {
			moveCursor(x, y + 4);
			cout << "��Enter��ȷ��";
		}
		else {
			moveCursor(x, y + 4);
			cout << "                 ";
		}
	}
}
void ATM::inputPassword(string& s, int x, int y) {
	int i = 0;
	string asterisk = "      ";
	while (1) {
		moveCursor(x, y);
		cout << "+---+---+---+---+---+---+";
		moveCursor(x, y + 1);
		for (int j = 0; j < 6; j++) {
			cout << "| " << asterisk[j] << " ";
		}
		cout << "|";
		moveCursor(x, y + 2);
		cout << "+---+---+---+---+---+---+" << endl;
		char g = _getch();
		if (i < 6 && g >= '0' && g <= '9') {
			s += g;
			asterisk[i] = '*';
			i++;
		}
		else if (g == '\b' && i) {
			moveCursor(x, y + 4);
			cout << "                   " << endl;
			asterisk[i - 1] = ' ';
			s = s.substr(0, i - 1);
			i--;
		}
		else if (g == '\r' && s.size() == 6)
			break;
		if (i == 6) {
			moveCursor(x, y + 4);
			cout << "��Enter��ȷ��" << endl;
		}
	}
}
string ATM::numFarmat(int x) {
	string s1 = to_string(x);
	string s2;
	for (int i = s1.size() - 1, count = 0; i >= 0; i--, count++) {
		if (count % 3 == 0 && count) {
			s2 = ',' + s2;
		}
		s2 = s1[i] + s2;
	}
	s2 += ".00";
	return s2;
}
void ATM::createAccount() {
	ifstream fin;
	fin.open("Users4.txt");
	if (!fin.is_open()) {
		time_t now = time(NULL) / 60 / 60 / 24;
		string n = to_string(now);
		ofstream fout;
		fout.open("Users4.txt", ios::out);
		fout << "1111111111111111111111111345123200112111324100000000000000" << n << "sandy" << endl;
		fout << "1234567890123456789123456100000197011112121100000000000000" << n << "joker" << endl;
		fout << "1212121212121212121121212230212199012111111100000000000000" << n << "hutao" << endl;
		fout << "1091237710129381092477985509222200003028978100000000000000" << n << "luban" << endl;
		fout.close();
		return;
	}
	fin.close();
}
void ATM::beginPage() {
	shape();
	moveCursor(3, 2);
	cout << "��ӭʹ��CQU����ATM��������!";
	moveCursor(3, 6);
	cout << "��������п�";
	moveCursor(3, 7);
	cout << "����Enter����";
	while (_getch() != '\r');
}
User ATM::verify(string& account, string& password) {
	int times = 0; //�������
	while (times < 3) {
		shape();
		account = "";
		password = "";
		moveCursor(3, 2);
		cout << "�������˺ţ�" << endl;
		inputNumber(account, 3, 5);
		shape();
		moveCursor(3, 2);
		cout << "���������룺" << endl;
		inputPassword(password, 3, 5);
		string* users = readFile();
		for (int i = 0; i < 4; i++) {
			if (users[i].substr(0, 19) == account) {
				if (users[i].substr(19, 6) == password)
					return User(account, password, users[i].substr(63), users[i].substr(25, 18),
						stoi(users[i].substr(43, 5)), stoi(users[i].substr(48, 5)),
						stoi(users[i].substr(53, 5)), stoi(users[i].substr(58, 5)));
				else
					break;
			}
		}
		shape();
		moveCursor(3, 4);
		cout << "�˺Ż��������";
		Sleep(1600);
		times++;
	}
	lockcard();
}
void ATM::homePage(User& x) {
	while (1) {
		shape();
		moveCursor(15, 1);
		cout << "ATM��������";
		moveCursor(0, 5);
		cout << "|| 1 - ��ѯ���";
		cout << "                ȡ�� - 2" << endl << endl;
		cout << "|| 3 - ���";
		cout << "                �޸����� - 4" << endl << endl;
		cout << "|| 5 - ת��";
		cout << "                    �˿� - 6" << endl << endl;
		switch (_getch() - '0') {
		case 1:inquiry(x); break;
		case 2:withdraw(x); break;
		case 3:deposit(x); break;
		case 4:changePassword(x); break;
		case 5:transfer(x); break;
		case 6:exitCard(); break;
		}
	}
}
void ATM::inquiry(User x) {
	loading();
	moveCursor(3, 1);
	cout << "��";
	moveCursor(7, 3);
	cout << numFarmat(x.getBalance()) << " Ԫ\n\n\n\n";
	cout << "|| 1 - �������˵�" << endl << endl;
	cout << "|| 0 - �˿�" << endl;
	while (1) {
		int i = _getch();
		if (i == '1')
			break;
		else if (i == '0')
			exitCard();
	}
}
void ATM::withdraw(User& x) {
	shape();
	moveCursor(3, 2);
	cout << "������Ҫȡ��Ľ�" << endl << endl;
	cout << "|| 1 - 100Ԫ";
	cout << "                  200Ԫ - 2" << endl << endl;
	cout << "|| 3 - 500Ԫ";
	cout << "                 1000Ԫ - 4" << endl << endl;
	cout << "|| 5 - �������";
	cout << "          ���������� - 6" << endl << endl;
	while (1) {
		int t = _getch();
		int take[] = { 100,200,500,1000 };
		if (t >= '1' && t <= '4') {
			if (take[t - '1'] > x.getBalance()) {
				cout << "\n|| ����             ";
				Sleep(1400);
				break;
			}
			else if (take[t - '1'] + x.getWithdrawn() > 20000) {
				cout << "\n|| �������ȡ���ת�ˣ��޶�20,000Ԫ";
				Sleep(1400);
				break;
			}
			loading();
			x.addBalance(-take[t - '1']);
			x.addWithdrawn(take[t - '1']);
			moveCursor(3, 3);
			cout << "��ȡ�������ֽ�";
			Sleep(1400);
			break;
		}
		else if (t == '5') {
			shape();
			moveCursor(3, 2);
			cout << "������Ҫȡ��Ľ�";
			string out_money;
			inputNumber(out_money, 3, 3);
			if (out_money.size() > 4)
				cout << "\n|| ����ȡ����ܳ���3,000Ԫ";
			else {
				int money = stoi(out_money);
				if (money > 3000)
					cout << "\n|| ����ȡ����ܳ���3,000Ԫ";
				else if (money > x.getBalance())
					cout << "\n|| ����           ";
				else if (money + x.getWithdrawn() > 20000)
					cout << "\n|| �������ȡ���ת�ˣ��޶�20,000Ԫ";
				else if (money % 100 != 0)
					cout << "\n|| ֻ��ȡ��100�������Ľ��";
				else {
					loading();
					moveCursor(3, 3);
					cout << "��ȡ�������ֽ�";
					x.addBalance(-money);
					x.addWithdrawn(money);
				}
			}
			Sleep(1400);
			break;
		}
		else if (t == '6')
			break;
	}
	writeFile(x);
}
void ATM::deposit(User& x) {
	shape();
	string in_money;
	moveCursor(3, 3);
	cout << "������ֽ��������Ľ��";
	inputNumber(in_money, 3, 5);
	if (in_money.size() > 5)
		cout << "\n|| ����������100�ų�Ʊ";
	else {
		int money = stoi(in_money);
		if (money > 10000)
			cout << "\n|| ����������100�ų�Ʊ";
		else if (money && money % 100 != 0)
			cout << "\n|| ֻ�ܴ���100Ԫ���ĳ�Ʊ";
		else if (money + x.getDeposited() > 50000)
			cout << "\n|| ���մ���޶�50,000Ԫ";
		else if (money == 0)
			cout << "\n|| ��������Ч���";
		else {
			loading();
			x.addBalance(money);
			x.addDeposited(money);
			shape();
			moveCursor(3, 3);
			cout << "���ɹ�";
			writeFile(x);
		}
	}
	Sleep(1400);
}
void ATM::refreshRecord(User& x) {
	time_t now = time(NULL) / 60 / 60 / 24;
	if (now != x.getDate()) {
		x.refresh(now);
		writeFile(x);
	}
}
void ATM::changePassword(User& x) {
	shape();
	string input1, input2;
	moveCursor(3, 2);
	cout << "������ԭ���룺" << endl;
	inputPassword(input1, 3, 4);
	if (input1 == x.getPassword()) {
		shape();
		moveCursor(3, 2);
		cout << "�����������룺" << endl;
		input1 = "";
		inputPassword(input1, 3, 4);
		if (input1 == x.getPassword()) {
			cout << "\n|| �����벻����ԭ������ͬ!" << endl;
			Sleep(1400);
		}
		else {
			shape();
			moveCursor(3, 2);
			cout << "���ٴ����룺" << endl;
			input2 = "";
			inputPassword(input2, 3, 4);
			if (input1 == input2) {
				x.setPassword(input2);
				writeFile(x);
				shape();
				moveCursor(3, 3);
				cout << "�޸ĳɹ������μ��������п�����";
				Sleep(1600);
			}
			else {
				cout << "\n|| �����������벻һ�£�";
				Sleep(1500);
			}
		}
	}
	else {
		cout << "\n|| �������   " << endl;
		Sleep(1500);
	}
}
void ATM::transfer(User& x) {
	shape();
	string to_account;
	moveCursor(3, 2);
	cout << "������ת�����˺ţ�";
	inputNumber(to_account, 3, 4);
	if (to_account == x.getAccount()) {//������Լ�ת�˵����
		shape(); 
		moveCursor(3, 3);
		cout << "�޷�����˻�ת�ˣ���˶��˻���Ϣ";
		Sleep(1700);
		return;
	}
	string* users = readFile();
	bool found = 0;
	User* to = 0;
	for (int i = 0; i < 4; i++) {
		if (users[i].substr(0, 19) == to_account) {
			to= new User(users[i].substr(0, 19), users[i].substr(19, 6), users[i].substr(63),
					users[i].substr(25, 18), stoi(users[i].substr(43, 5)), stoi(users[i].substr(48, 5)),
					stoi(users[i].substr(53, 5)), stoi(users[i].substr(58, 5)));
			found = 1;
			break;
		}
	}
	if (found) {
		shape();
		moveCursor(3, 3);
		cout << "������ת�˽�";
		string to_money;
		inputNumber(to_money, 3, 5);
		shape();
		moveCursor(3, 3);
		if (to_money.size() > 5)
			cout << "����ת�˽��ܳ���20000Ԫ";
		else {
			int money = stoi(to_money);
			if (money > 20000)
				cout << "����ת�˽��ܳ���20000Ԫ";
			else if (money > x.getBalance())
				cout << "����";
			else if (money + x.getWithdrawn() > 20000)
				cout << "�������ȡ���ת�ˣ��޶�20,000Ԫ";
			else if (money % 100 != 0)
				cout << "ֻ��ת��100�������Ľ��";
			else {
				loading();
				moveCursor(3, 3);
				cout << "ת�˳ɹ���";
				x.addBalance(-money);
				x.addWithdrawn(money);
				to->addBalance(money);
				writeFile(x);
				writeFile(*to);
				delete to; to = NULL;
			}
		}
		Sleep(1600);
		return;
	}
	shape();
	moveCursor(3, 3);
	cout << "�޷�����˻�ת�ˣ���˶��˻���Ϣ";
	Sleep(1700);
}
void ATM::exitCard() {
	shape();
	moveCursor(3, 3);
	cout << "���պ��������п�";
	moveCursor(0, 20);
	exit(0);
}
void ATM::run() {
	hideCursor();
	createAccount();
	beginPage();
	string account, password;
	User me = verify(account, password);
	refreshRecord(me);
	homePage(me);
}
