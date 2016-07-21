#ifndef _Course_Type_
#define _Course_Type_
#include <iostream>

#include <string>

class courseType
{
public:
	void setCourseInfo(string cName, string cNo, char grade, int credits);

	void print(ostream& outp, bool isGrade);

	int getCredits();

	void getCourseNumber(string& cNo);

	char getGrade();

	bool operator==(const courseType&) const;
	bool operator!=(const courseType&) const;
	bool operator<=(const courseType&) const;
	bool operator<(const courseType&) const;
	bool operator>=(const courseType&) const;
	bool operator>(const courseType&) const;

	courseType(string cName = "", string cNo = "", char grade = '*', int credits = 0);

private:
	string courseName;
	string courseNo;
	char courseGrade;
	int courseCredits;

};

void courseType::setCourseInfo(string cName, string cNo, char grade, int credits)
{
	courseName = cName;
	courseNo = cNo;
	courseGrade = grade;
	courseCredits = credits;
}

void courseType::print(ostream& outp, bool isGrade)
{
	outp << left;
	outp << setw(8) << courseNo << " ";
	outp << setw(15) << courseName;
	outp.unsetf(ios::left);
	outp.setw(3) << courseCredits << " ";

	if(isGrade)
		outp << setw(4) << courseGrade << endl;
	else
		outp << setw(4) << "***" << endl;
}

courseType::courseType(string cName, string cNo, char grade, int credits)
{
	setCourseInfo(cName, cNo, grade, credits);
}

int courseType::getCredits()
{
	return courseCredits;
}

char courseType::getGrade()
{
	return courseGrade;
}

void courseType::getCourseNumber(string& cNo)
{
	cNo = courseNo;
}

bool courseType::operator==(const courseType& right) const
{
	return (courseNo == right.courseNo);
}

bool courseType::operator!=(const courseType& right) const
{
	return (courseNo != right.courseNo);
}

bool courseType::operator<=(const courseType& right) const
{
	return (courseNo <= right.courseNo);
}

bool courseType::operator<(const courseType& right) const
{
	return (courseNo < right.courseNo);
}

bool courseType::operator>=(const courseType& right) const
{
	return (courseNo >= right.courseNo);
}

bool courseType::operator>(const courseType& right) const
{
	return (courseNo > right.courseNo);
}

#endif