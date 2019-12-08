/*! \file main.cpp
 * \brief Main file for the application
 *
 * Contains the entry point for the application, references to classes and the main run of the application.
 */

/*! \mainpage RLE Task 2020
* This is a simple program which runs RLE upon data taken from a text file, encodes it, gives a compression ratio
* and then decodes back to original data.
*/

#include <iostream>
#include "RLE.h"
using namespace std;


int main() //!< Entry point for the application
{
	RLE RLE; //!< reference to call functions from within the 'RLE' class.
	string input; //!< string variable to take the data from the text file.
	string encodedInput; //!< string variable to take encoded string and pass on to be decoded.

	try 
	{
		cout << "File data to be encoded is " << RLE.openFile("encode_simple.txt") << endl;
		input = RLE.openFile("encode_simple.txt"); //!< using the openFile function to return a string of the .txt files contents and assign that to the input variable.
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		system("pause");
		return 0;
	}

	cout << "Implementing RLE encoding on the above data..." << "\n" << "RLE encoded data as follows: " << RLE.encode(input) << endl;
	cout << "The compression rate of this file is " << RLE.getCR() << endl;
	encodedInput = RLE.encode(input);
	cout << "Decompressing RLE encoded data to give original data stream of " << RLE.decode(encodedInput) << endl;
	
	system("pause");

	return 0;
}
