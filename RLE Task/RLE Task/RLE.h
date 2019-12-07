/*!
\file RLE.h
*/
/*! \class RLE
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
	RLE(); //!< Constructor function for the RLE class with a single parameter.
	~RLE(); //!< Deconstructor function for RLE.
	string encode(const string &str); //!< Function to ...
	string decode(); //!< Function to ...
	string openFile(string file); //!< Function to ...
private:
	string encoding; //!< 
	string decoding; //!< 
	string inputStr; //!< 
	ifstream inputFile; //!< 
	float compressionRatio; //!< 
};