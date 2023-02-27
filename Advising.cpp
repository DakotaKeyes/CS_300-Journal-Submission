#include <iostream>

#include <fstream>

#include <vector>

#include <string>

using namespace std;

///////////////////////////////
// Strucutre course definition//
////////////////////////////////
struct Course {

	string courseNumber;

	string name;

	vector<string> prerequisites;

};

////////////////////////////////////////////////
// Function to split string to list of strings//
////////////////////////////////////////////////
vector<string> tokenize(string s, string del = " ")		{

	vector<string> stringArray;

	int start = 0;

	int end = s.find(del);

	while (end != -1) {

		stringArray.push_back(s.substr(start, end - start));

		start = end + del.size();

		end = s.find(del, start);

	}

	stringArray.push_back(s.substr(start, end - start));

	return stringArray;

}

///////////////////////////////////////////////////////////
// Loading the file & storing details into list of courses//
///////////////////////////////////////////////////////////
vector<Course> LoadDataStructure()

{

	///////////////////////////////////
	// Using iftsream to open file//
    ////////////////////////////////
	ifstream fin("abcu.txt", ios::in);

	vector<Course> courses;

	string line;

	////////////////////////
	// Loop for program//
	//////////////////////
	while (1)	{

		 getline(fin, line);

		 ////////////////////////////////////////
		// Break when end of file is reached///
		////////////////////////////////////////

		if (line == "-1")

			break;

		Course course;

		vector<string> tokenizedInformation = tokenize(line, ",");

		///////////////////////////
		// Storing information //
		//////////////////////////

		course.courseNumber = tokenizedInformation[0];

		course.name = tokenizedInformation[1];

		////////////////////////////////////
		// if prereqs exist, store /////////
		////////////////////////////////////
		for (int i = 2; i < tokenizedInformation.size(); i++)	{

			course.prerequisites.push_back(tokenizedInformation[i]);
		}

		////////////////////////////////////////////
		// appending course into list of the courses//
		////////////////////////////////////////////////
		courses.push_back(course);
	}
	///////////////
	// close file//
	///////////////

	fin.close();

	////////////////////////
	// returncourse list///
	///////////////////////

	return courses;

}

//////////////////////////////////
// printing course info to console//
///////////////////////////////////
void printCourse(Course course)	{

	string courseNumber = course.courseNumber;
	string name = course.name;
	vector<string> prerequisites = course.prerequisites;

	cout << "Course Number: " << courseNumber << endl;
	cout << "Course Name: " << name << endl;
	cout << "Prerequisites: ";

	for (int i = 0; i < prerequisites.size(); i++)	{
		cout << prerequisites[i] << " " << endl;
	}

}
//////////////////////////////
// printing all course info///
///////////////////////////////

void printCourseList(vector<Course> courses)	{
	int n = courses.size();

	///////////////////////
	// Sorting the list//
	/////////////////////
	for (int i = 0; i < n - 1; i++)	{

		for (int j = 0; j < n - i - 1; j++)	{

			if (courses[j].courseNumber > courses[j + 1].courseNumber)		{

				swap(courses[j + 1], courses[j]);
			}
		}
	}

	//////////////////////////////////////////////
	// traversing list to print all course info///
	//////////////////////////////////////////////
	for (int i = 0; i < n; i++)	{

		printCourse(courses[i]);

	}

}
///////////////////////////////////////
// search course given course number //
///////////////////////////////////////

void searchCourse(vector<Course> courses)	{

	int n = courses.size();
	string courseNumber;
	int f = 0;

	cout << "Enter courseNumber: ";
	cin >> courseNumber;


	for (int i = 0; i < n; i++)	{

		///////////////////////////////
		// print course if found///
		/////////////////////////////
		if (courses[i].courseNumber == courseNumber)	{

			f = 1;

			printCourse(courses[i]);

			break;
		}
	}

	/////////////////
	//error message//
	/////////////////
	if (f == 0)	{

		cout << "Course with given course number not found\n";
	}
}

int main(int argc, char** argv)	{
	vector<Course> courses;

	////////
	//Menu//
	////////

	cout << "1.Load Data Structure" << endl;

	cout << "2.Print Course List"<< endl;

	cout << "3.Print Course" << endl;

	cout << "4.Exit" << endl;

	int ch;

	////////////////////////////////////
	// loop will stop if user enters 4//
	////////////////////////////////////
	do {
		
		cout << "\nEnter your choice: ";

		cin >> ch;


		switch (ch)

		{

		case 1: courses = LoadDataStructure(); break;

		case 2: printCourseList(courses); break;

		case 3: searchCourse(courses); break;

		case 4: cout << "Exit\n"; break;


		default: cout << "Invalid Choice" << endl;
		}


	} while (ch != 4);

	return 0;
}

