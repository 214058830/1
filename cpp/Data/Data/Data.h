#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);

	// 2018 11 1 + 100 
	Date operator+(int days);
	// 2018 11 4 - 100 = 2018 11 -94 
	// 2018 11 4 - 锛?100锛?= 2018 11 4 + 100 
	Date operator-(int days);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	// 2018 11 4 
	// 2019 1 1 
	int operator-(const Date& d);
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	bool operator>(const Date& d)const;


private:
	bool IsInvalidDate();
	int _GetDaysOfMonth(int year, int month);
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);

private:
	int _year;
	int _month;
	int _day;
};