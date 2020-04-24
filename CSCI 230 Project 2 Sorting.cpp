#include <iostream>
#include <fstream>
#include <string>
#include "Sorting.h"
#include "Ascending.h"
#include <chrono>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	Ascending ascend;
	string File = "C:\\Users\\joeje\\Desktop\\small1k.txt";
	string outputFile = "C:\\Users\\joeje\\Desktop\\Output1k.txt";

	for (int i = 0; i < 2; i++)
	{
		outfile.open(outputFile);
		if (i == 0)
		{
			outfile << "\t\tFile: Small1k.txt" << endl;
		}
		if (i == 1)
		{
			outfile << "\t\tFile: Large100k.txt" << endl;
		}
		infile.open(File);
		if (!infile)
		{
			cout << "Cannot find file!" << endl;
			return 0;
		}

		vector<pair<int, string>> myVint1;
		vector<pair<string, int>> myVstring1;

		int num;
		string str;

		while (!infile.eof())
		{
			infile >> num;
			str = to_string(num);
			myVint1.push_back(make_pair(num, str));
			myVstring1.push_back(make_pair(str, num));
		}

		vector<pair<int, string>> myVint2 = myVint1;
		vector<pair<string, int>> myVstring2 = myVstring1;
		vector<pair<int, string>> myVint3 = myVint1;
		vector<pair<string, int>> myVstring3 = myVstring1;
		vector<pair<int, string>> myVint4 = myVint1;
		vector<pair<string, int>> myVstring4 = myVstring1;

		Sorting Sort;
		///////////////////////      INSERTION SORT        ///////////////////////////////
		if (i == 0)
		{
			outfile << "Insertion Sort:" << endl;
			auto start = chrono::high_resolution_clock::now();
			Sort.insertionSort(myVint1, ascend);
			auto fin = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast <chrono::milliseconds>(fin - start);
			outfile << "Integer: " << endl << "\tTime: " << duration.count() << " milliseconds" << endl;
			outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
			outfile << "\tCompares: " << Sort.getCompares() << endl;
			outfile << "\tFirst and Last Five: ";
			Sort.print1(myVint1, outfile);

			start = chrono::high_resolution_clock::now();
			Sort.insertionSort(myVstring1, ascend);
			fin = chrono::high_resolution_clock::now();
			duration = chrono::duration_cast <chrono::milliseconds>(fin - start);
			outfile << "String: " << endl << "\tTime: " << duration.count() << " milliseconds" << endl;
			outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
			outfile << "\tCompares: " << Sort.getCompares() << endl;
			outfile << "\tFirst and Last Five: ";
			Sort.print1(myVstring1, outfile);
			outfile << endl;
		}


		///////////////////////      MERGE SORT        ///////////////////////////////
		outfile << "Merge Sort:" << endl;
		auto start1 = chrono::high_resolution_clock::now();
		Sort.mergeSort(myVint2, ascend);
		auto fin1 = chrono::high_resolution_clock::now();
		auto duration1 = chrono::duration_cast <chrono::milliseconds>(fin1 - start1);
		outfile << "Integer: " << endl << "\tTime: " << duration1.count() << " milliseconds" << endl;
		outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
		outfile << "\tCompares: " << Sort.getCompares() << endl;
		outfile << "\tFirst and Last Five: ";
		Sort.print1(myVint2, outfile);

		start1 = chrono::high_resolution_clock::now();
		Sort.mergeSort(myVstring2, ascend);
		fin1 = chrono::high_resolution_clock::now();
		duration1 = chrono::duration_cast <chrono::milliseconds>(fin1 - start1);
		outfile << "String: " << endl << "\tTime: " << duration1.count() << " milliseconds" << endl;
		outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
		outfile << "\tCompares: " << Sort.getCompares() << endl;
		outfile << "\tFirst and Last Five: ";
		Sort.print1(myVstring2, outfile);
		outfile << endl;


		///////////////////////      QUICK SORT        ///////////////////////////////
		outfile << "Quick Sort:" << endl;
		start1 = chrono::high_resolution_clock::now();
		Sort.quickSort(myVint3, ascend);
		fin1 = chrono::high_resolution_clock::now();
		duration1 = chrono::duration_cast <chrono::milliseconds>(fin1 - start1);
		outfile << "Integer: " << endl << "\tTime: " << duration1.count() << " milliseconds" << endl;
		outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
		outfile << "\tCompares: " << Sort.getCompares() << endl;
		outfile << "\tFirst and Last Five: ";
		Sort.print1(myVint3, outfile);

		start1 = chrono::high_resolution_clock::now();
		Sort.quickSort(myVstring3, ascend);
		fin1 = chrono::high_resolution_clock::now();
		duration1 = chrono::duration_cast <chrono::milliseconds>(fin1 - start1);
		outfile << "String: " << endl << "\tTime: " << duration1.count() << " milliseconds" << endl;
		outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
		outfile << "\tCompares: " << Sort.getCompares() << endl;
		outfile << "\tFirst and Last Five: ";
		Sort.print1(myVstring3, outfile);
		outfile << endl;


		///////////////////////       QUICK SORT 3       ///////////////////////////////
		outfile << "Quick Sort 3:" << endl;
		start1 = chrono::high_resolution_clock::now();
		Sort.quickSort3(myVint4, ascend);
		fin1 = chrono::high_resolution_clock::now();
		duration1 = chrono::duration_cast <chrono::milliseconds>(fin1 - start1);
		outfile << "Integer: " << endl << "\tTime: " << duration1.count() << " milliseconds" << endl;
		outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
		outfile << "\tCompares: " << Sort.getCompares() << endl;
		outfile << "\tFirst and Last Five: ";
		Sort.print1(myVint3, outfile);

		start1 = chrono::high_resolution_clock::now();
		Sort.quickSort3(myVstring4, ascend);
		fin1 = chrono::high_resolution_clock::now();
		duration1 = chrono::duration_cast <chrono::milliseconds>(fin1 - start1);
		outfile << "String: " << endl << "\tTime: " << duration1.count() << " milliseconds" << endl;
		outfile << "\tData Moves: " << Sort.getDataMoves() << endl;
		outfile << "\tCompares: " << Sort.getCompares() << endl;
		outfile << "\tFirst and Last Five: ";
		Sort.print1(myVstring3, outfile);
		outfile << endl;


		File = "C:\\Users\\joeje\\Desktop\\large100k.txt";
		outputFile = "C:\\Users\\joeje\\Desktop\\Output100k.txt";
		outfile.close();
		infile.close();
	}

	return 0;
}

