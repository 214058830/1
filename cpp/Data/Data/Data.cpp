#include"Data.h"
#include<iostream>
#include"Data.h"
using namespace std;


	Date::Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!IsInvalidDate())
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

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
	bool operator==(const Date& d)const {

	}
	bool operator!=(const Date& d)const {

	}
	bool operator>(const Date& d)const {

	}

	bool Date::IsInvalidDate() {
		if (this->_month >= 12 || this->_day >= 31) {
			return false;
		}
	}
	int _GetDaysOfMonth(int year, int month) {

	}
	friend ostream& operator<<(ostream& _cout, const Date& d) {

	}
	friend istream& operator>>(istream& _cin, Date& d) {

	}