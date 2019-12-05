/*! \file main.cpp
 * \brief Main file for the application
 *
 * Contains the entry point for the application, references to classes,
 * *****COMPLETE THIS*****
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string openFile(string file);
float compressionRatio();
string encode(const string &str);
string decode(const string &str);


int main() //!< Entry point for the application
{
	string input;
	char c;

	int asciiFront = 000;
	int asciiBack = 127;

	try {
		cout << "File data to be encoded is " << openFile("compress_decompress_1.txt") << endl;
		input = openFile("compress_decompress_1.txt");

		for (int j = 0; j < input.length(); ++j) 
		{
			c = input.at(j);
		}
		/*
		A check that the input is valid, in this case checking the input of each char has an ascii value.
		Returns with an error message if this isn't the case.
		*/
		if (!(int(c) >= asciiFront && int(c) <= asciiBack)) 
		{
			throw runtime_error("---error--- invalid input");
		}
	}

	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		system("pause");
		return 0;
	}

	cout << "Implementing RLE encoding on the above data..." << "\n" << "RLE encoded data as follows: " << encode(input) << endl;

	system("pause");

	return 0;
}



/*
***TO DO*** NEEDS OWN CLASS!
Opens the required file, take the data out as a string, pass into 'inputStr' var and then return the 'inputStr' var.
*/
string openFile(string file)
{
	ifstream inputFile;
	inputFile.open(file);
	string inputStr;

	// .eof looks for the 'end of file' marker, if it finds it it returns true.
	// so below, while have not found end of file, continuing passing the data into the inputStr var.
	while (!inputFile.eof())
	{
		inputFile >> inputStr;
	}

	return inputStr;
}



/*
***TO DO*** Needs Own CLASS!
***TO DO*** Feed data from data strings into the vars in this class - LOOK FURTHER INTO THIS
Takes the length of the initial data string from the input file.
Then takes the length of the newly RLE compressed data string.
Divide the initial data length by the compressed data length to get your compression ratio value
COULD THIS BE DONE INSIDE THE 'string encode(const string &str) {}' Class??? Or best kept as own Class, have a think about it...
PROBABLY NOT, AS THAT IS RETURNING A STRING, NEED A FLOAT RETURNED.
*/
float compressionRatio()
{
	int initalDataLength /* = */;	// Need to pass .length() (or would .size() be better?) of inital data length string into this var, get it from openFile() or encode()?
	int encodedDataLength /* = encode().encoding.length()*/;	// Needs to pass .length() (or would .size() be better?) of 'encoding' string into this var
	float compressedRatio;

	compressedRatio = initalDataLength / encodedDataLength;

	return compressedRatio;
}



/*
***TO DO*** NEEDS OWN CLASS
***TO DO*** Sort out the problem with 'count', when value is over 9, going into double digits and following ascii, : ; etc
PROBLEM - app won't display number over 9
REASON - it is expecting a char, which is only displayed as one char, so '10' ends up as ':' (following ascii code on from 9)
SOLUTION - turn the integer presented by count into a string and have that string passed into encoding, so 10 and above are displayed correctly.
FURTHER PROBLEMS... - can't get this to work..... 'no conversion from string to char exists', thought a string was a container for char's... missing something here
*/
string encode(const string &str) {
	int dataLength = str.length();
	string encoding;
	/*
	stringstream ss;
	string countStr;
	*/

	for (int i = 0; i < dataLength; ++i)
	{
		int count = 1;
		while (str[i] == str[i + 1])
		{
			count++;
			i++;
		}
		/*
		countStr = to_string(count);
		encoding.push_back(countStr);
		*/
		encoding += std::to_string(count);
		encoding.push_back(str[i]);
	}
	return encoding;
}



/*
***TO DO*** NEEDS OWN CLASS
***TO DO*** pretty much all of it...
Needs to take the compressed data
Then take the numerical value
And apply that to the ascii char
Then create a new string that has the numerical value times the ascii char
I think.... LOOK FURTHER INTO THIS
*/
string decode(const string &str)
{

	string decoding;

	return decoding;
}
