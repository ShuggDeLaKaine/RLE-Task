/*! 
\file RLE.cpp
 * Contains the entry point for the application, references to classes and the main run of the application.
 */
#include "RLE.h"


//!Funtion RLE() - to initalise values of variables.
RLE::RLE()
{
	//initialising the value of the variables.
	compressionRatio = 0.0f; 
	inputDataLength = 0.0f;
	outputDataLength = 0.0f;
}


//!Funtion ~RLE() - deconstructor ready to go; currently unused.
RLE::~RLE()
{
}


//! Function encode() - used to take a string and use RLE encoding upon it and return the encoded data as a string.
/*!
\param &str - a string which contains the data requiring RLE encoding.
\returning encoding - string containing the encoded data.
*/
string RLE::encode(const string &str)
{
	//resetting and clearing 'encode' string from any previous data.
	encoding = "";
	//taking the length of the string which requires encoding. Used within the below loop but also passed to getCR() to work out compression ratios.
	inputDataLength = str.length();

	//
	for (int i = 0; i < inputDataLength; ++i)
	{
		//temp var to contain count of each character, intitalised to 1 as it will always start at 1.
		int count = 1;

		//while char at str[n] is the same as the char at str[n + 1], whilst it's the same character next.
		while (str[i] == str[i + 1])
		{
			// +1 to the count of the current character and move to the next step in the str array.
			count++;
			i++;
		}
		//creating the newly encoded string by adding the total count of character to the string and then adding the character which has been counted. 
		encoding += to_string(count);
		encoding.push_back(str[i]);
	}
	//returing the string encoding, containing the encoded data.
	return encoding;
}


//! Function getCR() - a function to work out the compression ratio, created for further expansion of different ratios. 
/*!
\ returning compressionRatio - a float containing the compression ratio between the original and encoded datas. 
NOTE - could have been placed within encode() but given own function for future expansion if different compression ratios required, such as Space Saving or Data Rate Saving. 
*/
float RLE::getCR()
{
	//resetting compressionRatio from last use.
	compressionRatio = 0;
	//taking the lengths of the original string and the encoded string
	cout << "Length of original data string is " << inputDataLength << endl;
	cout << "Length of compressed data string is " << encoding.length() << endl;
	//implementing the equation to get the compression ratio
	compressionRatio = inputDataLength / encoding.length();
	//returning the float containing the compression ratio.
	return compressionRatio;
}


//! Function decode() - to take a string of encoded data and run hrough a decoding loop to get the original data.
/*!
/param &str - a string variable to take the string of data that requires decoding.
/return decoding - a string that now contains the decoded data of the original data.
*/
string RLE::decode(const string &str)
{
	//resetting and clearing 'decode' string from any previous data.
	decoding = "";
	//taking the length of the inputted string to use with the loop and potentially for compression ratio checks.
	outputDataLength = str.length();

	//temp var c to contain a char.
	char c;
	//temp var count to contain an int; initialising it to the string point in the string which if RLE encoded should be the first number.
	int count = str.at(0);

	for (int i = 0; i < outputDataLength; ++i)
	{

		//if the char at position [i] in the string is not alphabetic nor punctuation, so therefore a number.
		//if (str[i] == !isalpha && str[i] == !ispunct)
		if (!isalpha(str[i]) && !ispunct(str[i]))
		{
			cout << "str[" << i << "] is a number" << endl; //***DEBUG - REMEMBER TO REMOVE***
			cout << "that number is " << count << endl; //***DEBUG - REMEMBER TO REMOVE***
			//assign number at position [i] in the string to variable 'count'.
			count = str.at(i);
			//else, if it's not a number, must be alphabetic or punctuation, so...
		} else {
			cout << "str[" << i << "] is a letter" << endl; //***DEBUG - REMEMBER TO REMOVE***
			//assign the char at position [i] in the string to variable c.
			c = str.at(i);
			cout << "that letter is " << c << endl; //***DEBUG - REMEMBER TO REMOVE***
			//for loop used to print the 'char c' for as long as the the 'int count'.
			for (int j = 0; j < count; j++) 
			{
				//passing char from c to decoding string to be returned.
				decoding += std::to_string(char(c));
			}
		}
	}
	// return the string containing the decoded string.
	return decoding;
}


//! Function openFile() - to take string of file name reuired to be opened, open it and return a string containing the data from the text file.
/*!
\param file - a string var to take the name of the text file required to be opened.
\return string inputStr - a string containing the data contained within the text file.
\NOTE - did not use (!inputFile.eof()) as experiencing problems with files containing " " spaces, only returning the last part of the data within the text file.
*/
string RLE::openFile(string file)
{
	//temporary variable to store each char from the text file before passing it to the 'inputStr' string.
	char c;
	//opening the text file from the parameters.
	inputFile.open(file);

	//while loop taking each char from inputFile and feeding into var c
	while (inputFile >> c)
	{
		//updating the 'inputStr' by adding each 'char c' to the string
		inputStr = inputStr + c; //!< 
	}
	//returning the value of the string variable 'inputStr'
	return inputStr;
}