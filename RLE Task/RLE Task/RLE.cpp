#include "RLE.h"

RLE::RLE()
{
	compressionRatio = 0;
}

RLE::~RLE()
{

}

string RLE::encode(const string &str)
{
	dataLength = str.length();

	for (int i = 0; i < dataLength; ++i)
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
	/*
	compressionRatio = dataLength / encoding.length();
	cout << "Length of unencoded string is " << dataLength << endl;
	cout << "Length of encoded string is " << encoding.length() << endl;
	cout << "Compression Ratio is " << compressionRatio << endl;
	*/
	return encoding;
}

float RLE::getCR()
{
	cout << "Length of original data string is " << dataLength << endl;
	cout << "Length of compressed data string is " << encoding.length() << endl;
	compressionRatio = dataLength / encoding.length();
	return compressionRatio;
}

string RLE::decode()
{

	return decoding;
}

string RLE::openFile(string file)
{
	inputFile.open(file);

	// While having not found end of file, continuing passing the data into the inputStr var.
	while (!inputFile.eof())
	{
		inputFile >> inputStr;
	}

	return inputStr;
}