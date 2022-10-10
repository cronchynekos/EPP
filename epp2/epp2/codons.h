//My approach to this was to first lay out two important variables, the entire dna sequence (which combines two if presented with more than one) 
//as well as the length of the combined string. Both of these were accomplished in the readString function. Then the function getCount simply
//takes a portion of the combined string and compares it to the given codon too see if it is a match. If it is then int count increments by one.

#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Codons
{
	string dna;
	int length;
public:
	Codons();
	void readString(string sequence)
	{
		dna = dna.append(sequence);
		length = sequence.length();
		//cout << "length = " << length << endl; //test to make sure the string passes correctly
		//cout << "string = " << dna << endl;
	}
	int getCount(string codon)
	{
		int count = 0;
		for (int i = 0; i <= length; i++)
		{
			if (dna.substr(i, 3) == codon) 
			{
				count++;
			}
		}
		return count;
	}
};
Codons::Codons()
{
}