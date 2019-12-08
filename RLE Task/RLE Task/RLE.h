/*!
\file RLE.h
*/
/*! class RLE
\brief Holds the functions and variables for the RLE class.
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class RLE
{
public:
	RLE(); //!< Constructor function for the RLE class, used to initalise variables. 
	~RLE(); //!< Deconstructor function for RLE.
	string encode(const string &str); //!< Function to take the input string for the opened file and run the RLE encode loop upon that string, returning a string of that encoded data.
	string decode(const string &str); //!< Function to take the input string for the encoded data and run the RLE decode loop, returning a string of the original unencoded data.
	string openFile(string file); //!< Function to take a file name in the parameter, open that file and put the contained data in a string which it returns.
	float getCR(); //!< Function to get the compression ratio of the encoded data. Given its own function to allow for future expansion and different types of equations to give different ratios. 
private:
	string encoding; //!< string used to contain the returning value of encode().
	string decoding; //!< string used to contain returning value of decode().
	string inputStr; //!< string used to contain the returned information taken from the opened file in openFile().
	ifstream inputFile; //!< input stream to operate on opened file in openFile(). 
	float compressionRatio; //!< float used to contain returning value of getCR();
	float inputDataLength; //!< float used to contain length of string in encode(), used within encode() and the getCR();
	float outputDataLength; //!< float used to contain length of string in the decode().
};