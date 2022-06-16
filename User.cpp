
#include "User.h"

User::User(string a, string p, string n, string i, int b, int d, int w, int t) {
	account = a;
	password = p;
	name = n;
	identity = i;
	balance = b;
	deposited = d;
	withdrawn = w;
	date = t;
}
string User::getAccount() {
	return account;
}
string User::getPassword() {
	return password;
}
string User::getName() {
	return name;
}
string User::getIdentity() {
	return identity;
}
int User::getBalance() {
	return balance;
}
int User::getDeposited() {
	return deposited;
}
int User::getWithdrawn() {
	return withdrawn;
}
time_t User::getDate() {
	return date;
}
void User::setPassword(string x) {
	password = x;
}
void User::addBalance(int x) {
	balance += x;
}
void User::addDeposited(int x) {
	deposited += x;
}
void User::addWithdrawn(int x){
	withdrawn += x;
}
void User::refresh(time_t x) {
	deposited = 0;
	withdrawn = 0;
	date = x;
}
