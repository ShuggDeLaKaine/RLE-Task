#include "RLE.h"

RLE::RLE()
{
	compressionRatio = 0; //!< initialising the value of the 'compressionRatio' variable.
}

RLE::~RLE()
{
}

string RLE::encode(const string &str)
{
	inputDataLength = str.length();
	for (int i = 0; i < inputDataLength; ++i)
	{
		int count = 1;
		while (str[i] == str[i + 1])
		{
			count++;
			i++;
		}
		encoding += std::to_string(count);
		encoding.push_back(str[i]);
	}
	return encoding;
}

float RLE::getCR()
{
	cout << "Length of original data string is " << inputDataLength << endl;
	cout << "Length of compressed data string is " << encoding.length() << endl;
	compressionRatio = inputDataLength / encoding.length();
	return compressionRatio;
}

string RLE::decode(const string &str)
{
	outputDataLength = str.length();
	int j = 0;

	for (int i = 0; i < outputDataLength; i++)
	{
		string counter;
		int letterCoefficient = 0;
		if (!isalpha(str[i]))
			continue;
		else
		{
			counter = str.substr()[j, i - j];
			j = i + 1;
			istringstream(j) >> letterCoefficient;
			for (int k = 0; k < letterCoefficient; k++)
			{
				decoding += str[i];
			}
		}
	}
	return decoding;
}

string RLE::openFile(string file)
{
	char c; //!< temporary variable to store each char from the text file before passing it to the 'inputStr' string.
	inputFile.open(file); //!< opening the text file from the parameters.

	/*
	// While having not found end of file, continuing passing the data into the inputStr var.
	while (!inputFile.eof())
	{
		inputFile >> inputStr;
	}
	*/
	//DEBUG NOTE - had used the above here, was having issues with spaces and only giving the data past the last space in the text file.
	while (inputFile >> c)
	{
		inputStr = inputStr + c;
	}

	return inputStr; //!< returning the value of the string variable 'inputStr'
}