#include <iostream>
#include <string>
#include "Codons.h"

using std::string;
using std::cout;

template <typename T>
bool testAnswer(const string& nameOfTest, const T& received, const T& expected);

int main() {
    {
        Codons codons;
        cout << "Reading one string: TCTCCCTGACCC\n";
        codons.readString("TCTCCCTGACCC");
        testAnswer("count(TCT)", codons.getCount("TCT"), 1);
        testAnswer("count(CCC)", codons.getCount("CCC"), 2);
        testAnswer("count(TGA)", codons.getCount("TGA"), 1);
        testAnswer("count(TGT)", codons.getCount("TGT"), 0);
    }
    {
        Codons codons;
        cout << "Reading one string: TCTCCCTGACCCTCTCCCTCT\n";
        codons.readString("TCTCCCTGACCCTCTCCCTCT");
        testAnswer("count(TCT)", codons.getCount("TCT"), 3);
        testAnswer("count(CCC)", codons.getCount("CCC"), 3);
        testAnswer("count(TGA)", codons.getCount("TGA"), 1);
        testAnswer("count(TGT)", codons.getCount("TGT"), 0);
    }
    {
        Codons codons;
        cout << "Reading two strings: TCTCCCTGACCC and TCTCCCTGACCCTCTCCCTCT\n";
        codons.readString("TCTCCCTGACCC");
        codons.readString("TCTCCCTGACCCTCTCCCTCT");
        testAnswer("count(TCT)", codons.getCount("TCT"), 4);
        testAnswer("count(CCC)", codons.getCount("CCC"), 5);
        testAnswer("count(TGA)", codons.getCount("TGA"), 2);
        testAnswer("count(TGT)", codons.getCount("TGT"), 0);
    }
    {
        Codons codons;
        cout << "Reading two strings: TCTCCCTGACCC and TCTCCCTGACCCTCTCCCTCT\n";
        codons.readString("TCTCCCTGACCC");
        codons.readString("TCTCCCTGACCCTCTCCCTCT");
        testAnswer("count(TCT)", codons.getCount("TCT"), 4);
        testAnswer("count(CCC)", codons.getCount("CCC"), 5);
        testAnswer("count(TGA)", codons.getCount("TGA"), 2);
        testAnswer("count(TGT)", codons.getCount("TGT"), 0);
        cout << "Reading third string: ACCAGGCAGACTTGGCGGTAGGTCCTAGTG\n";
        codons.readString("ACCAGGCAGACTTGGCGGTAGGTCCTAGTG");
        testAnswer("count(TCT)", codons.getCount("TCT"), 4);
        testAnswer("count(CCC)", codons.getCount("CCC"), 5);
        testAnswer("count(TGA)", codons.getCount("TGA"), 2);
        testAnswer("count(TAG)", codons.getCount("TAG"), 1);
        testAnswer("count(GGG)", codons.getCount("GGG"), 0);
    }
}

template <typename T>
bool testAnswer(const string& nameOfTest, const T& received, const T& expected) {
    if (received == expected) {
        cout << "PASSED " << nameOfTest << ": expected and received " << received << "\n";
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << "\n";
    return false;
}
