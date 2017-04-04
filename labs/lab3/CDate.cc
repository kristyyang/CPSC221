// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
		setDate(year,monthStr2Num(month),day);
	}

	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 

bool CDate::isValidDate(int year, int month, int day){
	return (isValidDay(year,month,day)&& year > 0);
	}
	// TODO you need to fill in the code here        ********
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
	//return false;

bool CDate::isValidDate(int year, std::string month, int day){
	return (isValidDay(year, monthStr2Num(month),day)&& year >0);
	// TODO you need to fill in the code here        ********
	// comment out "return false" below
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	//return false;
}

int CDate::monthStr2Num(std::string month){
	if(month =="January"){
		return 1;
	}else if(month =="February"){
		return 2;
	}else if(month =="March"){
		return 3;
	}else if(month =="April"){
		return 4;
	}else if(month =="May"){
		return 5;
	}else if(month =="June"){
		return 6;
	}else if(month =="July"){
		return 7;
	}else if(month =="August"){
		return 8;
	}else if(month == "September"){
		return 9;
	}else if(month =="October"){
		return 10;
	}else if(month =="November"){
		return 11;
	}else if(month =="December"){
		return 12;
	}else{
		return -1;     //Invalid value
	}
	// TODO you need to fill in the code here        ********
	//return -1;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		    valid =(day <=31);
		    break;
			// TODO you need to fill in the code here        ********
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
		    valid =(day <= 30);
		    break;
			// TODO you need to fill in the code here        ********
		default:
		    valid = false;
			// TODO you need to fill in the code here        ********
			break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	if(isValidDate(year,monthStr2Num(month),day)){
		m_year = year;
		m_month = monthStr2Num(month);
		m_day = day;
	}else{
		m_year = m_month=m_day = 0;
	}
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}



