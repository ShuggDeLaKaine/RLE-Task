#include "RLE.h"

RLE::RLE()
{

}

RLE::~RLE()
{

}

string RLE::encode(const string &str)
{
	int dataLength = str.length();
	float charCount = 0;
	compressionRatio = 0;

	for (int i = 0; i < dataLength; ++i)
	{
		int count = 1;
		while (str[i] == str[i + 1])
		{
			count++;
			i++;
			charCount++;
		}
		encoding += std::to_string(count);
		encoding.push_back(str[i]);
	}

	compressionRatio = charCount / encoding.length();
	cout << "Length of unencoded string is " << charCount << endl;
	cout << "Length of encoded string is " << encoding.length() << endl;
	cout << "Compression Ratio is " << compressionRatio << endl;

	return encoding;
}

string RLE::decode()
{

	return decoding;
}

/*
Opens the required file, take the data out as a string, pass into 'inputStr' var and then return the 'inputStr' var.
*/
string RLE::openFile(string file)
{
	inputFile.open(file);

	// .eof looks for the 'end of file' marker, if it finds it it returns true.
	// so below, while have not found end of file, continuing passing the data into the inputStr var.
	while (!inputFile.eof())
	{
		inputFile >> inputStr;
	}

	return inputStr;
}