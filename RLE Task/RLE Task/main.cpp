/*! \file main.cpp
 * \brief Main file for the application
 *
 * Contains the entry point for the application, references to classes,
 * *****COMPLETE THIS*****
 */

#include <iostream>
#include "RLE.h"
using namespace std;


int main() //!< Entry point for the application
{
	RLE RLE;

	string input; //!< string variable to take the data from the text file.
	char c;

	int asciiFront = 000;
	int asciiBack = 127;

	try {
		cout << "File data to be encoded is " << RLE.openFile("compress_decompress_2.txt") << endl;
		input = RLE.openFile("compress_decompress_2.txt"); //!< using the openFile function to return a string of the .txt files contents and assign that to the input variable.

		for (int j = 0; j < input.length(); ++j) 
		{
			c = input.at(j);
			/*
			A check that the input is valid, in this case checking the input of each char has an ascii value.
			Returns with an error message if this isn't the case.
			*/
			if (!(int(c) >= asciiFront && int(c) <= asciiBack))
			{
				throw runtime_error("---error--- invalid input");
			}
		}

	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		system("pause");
		return 0;
	}

	cout << "Implementing RLE encoding on the above data..." << "\n" << "RLE encoded data as follows: " << RLE.encode(input) << endl;
	cout << "The compression rate of this file is " << RLE.getCR() << endl;

	system("pause");

	return 0;
}
