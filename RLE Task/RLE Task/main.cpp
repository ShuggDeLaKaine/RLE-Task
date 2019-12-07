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
	RLE RLE; //!< reference to call functions from within the 'RLE' class.
	string input; //!< string variable to take the data from the text file.

	try 
	{
		cout << "File data to be encoded is " << RLE.openFile("big_mix.txt") << endl;
		input = RLE.openFile("big_mix.txt"); //!< using the openFile function to return a string of the .txt files contents and assign that to the input variable.
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		system("pause");
		return 0;
	}

	cout << "Implementing RLE encoding on the above data..." << "\n" << "RLE encoded data as follows: " << RLE.encode(input) << endl;
	cout << "The compression rate of this file is " << RLE.getCR() << endl;
	cout << "Decompressing RLE encoded data to give original data stream of " << RLE.decode(RLE.encode(input)) << endl;
	
	system("pause");

	return 0;
}
