#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Sorting
{
private:
	int valueSorted;
	int compares;
	int dataMoves;
public:
	Sorting()
	{
		valueSorted = 0;
		compares = 0;
		dataMoves = 0;
	}
	int getDataMoves()
	{
		return dataMoves;
	}
	int getCompares()
	{
		return compares;
	}

	template <typename E, typename C>
	void insertionSort(vector<E>& arr, const C& less)
	{
		int i, j;
		compares = 0;
		dataMoves = 0;
		for (i = 1; i < arr.size(); i++)
		{
			auto key = arr[i].first;
			j = i - 1;
			while (j >= 0 && !less(arr[j].first, key))
			{
				compares += 1;
				arr[j + 1] = arr[j];
				j = j - 1;
				dataMoves++;
			}
			arr[j + 1].first = key;
			dataMoves++;
		}
		if (arr.size() > 10005)
		{
			return;
		}
	}


	template <typename E, typename C> // merge-sort S 
	void mergeSort(std::vector<E>& S, const C& less)
	{
		dataMoves = 0;
		compares = 0;
		typedef vector<E> vect;
		int n = S.size();
		vect v1(S);
		vect* in = &v1; // initial input vector 
		vect v2(n);
		vect* out = &v2; // initial output vector 
		for (int m = 1; m < n; m *= 2) { // list sizes doubling 
			for (int b = 0; b < n; b += 2 * m) { // beginning of list 
				merge(*in, *out, less, b, m); // merge sublists 
			}
			swap(in, out); // swap input with output 
			dataMoves += 3;
		}
		S = *in; // copy sorted array to S 
	}

	// merge in[b..b+m-1] and in[b+m..b+2*m-1] 
	template <typename E, typename C>
	void merge(std::vector<E>& in, std::vector<E>& out, const C& less, int b, int m)
	{
		int i = b; // index into run #1 
		int j = b + m; // index into run #2 
		int n = in.size();
		int e1 = min(b + m, n); // end of run #1 
		int e2 = min(b + 2 * m, n); // end of run #2 
		int k = b;
		while ((i < e1) && (j < e2))
		{
			if (!less(in[j].first, in[i].first)) // append smaller to S 
			{
				out[k++] = in[i++];
			}
			else
			{
				out[k++] = in[j++];
			}
			compares++;
			dataMoves++;
		}
		while (i < e1) // copy rest of run 1 to S 
		{
			out[k++] = in[i++];
			dataMoves++;
		}
		while (j < e2) // copy rest of run 2 to S 
		{
			out[k++] = in[j++];
			dataMoves++;
		}
	}

	template <typename E, typename C>			// quick-sort S
	void quickSort(std::vector<E>& S, const C& less)
	{
		dataMoves = 0;
		compares = 0;
		if (S.size() <= 1)
			return;				// already sorted
		quickSortStep(S, 0, S.size() - 1, less);		// call sort utility
	}

	template <typename E, typename C>
	void quickSortStep(std::vector<E>& S, int a, int b, const C& less) {
		if (a >= b)
			return;					// 0 or 1 left? done
		auto pivot = S[b].first;					// select last as pivot
		int l = a; 						// left edge
		int r = b - 1;					// right edge
		while (l <= r) {
			while (l <= r && !less(pivot, S[l].first))
			{
				l++;		// scan right till larger
				compares++;
			}
			while (r >= l && !less(S[r].first, pivot))
			{
				r--;		// scan left till smaller
				compares++;
			}
			if (l < r)					// both elements found
			{
				std::swap(S[l], S[r]);
				dataMoves += 3;
			}
		}							// until indices cross
		std::swap(S[l], S[b]);				// store pivot at l
		dataMoves += 3;
		quickSortStep(S, a, l - 1, less);			// recur on both sides
		quickSortStep(S, l + 1, b, less);
	}

	int generateNum(int n)
	{
		int randomNum = rand() % n;
		return randomNum;
	}

	template <typename E, typename C>			// quick-sort S
	void quickSort3(std::vector<E>& S, const C& less)
	{
		compares = 0;
		dataMoves = 0;
		if (S.size() <= 1)
			return;				// already sorted
		quickSortStep3(S, 0, S.size() - 1, less);		// call sort utility
	}

	template <typename E, typename C>
	void quickSortStep3(std::vector<E>& S, int a, int b, const C& less) {
		if (a >= b)
			return;					// 0 or 1 left? done
		int l = a; 						// left edge
		int r = b - 1;					// right edge
		int mid = (b - l + 1) / 2;
		int index = middleOfThree(S, a, mid, b);
		compares += 3;
		swap(S[index], S[b]);
		dataMoves += 3;
		auto pivot = S[b].first;
		while (l <= r) {
			while (l <= r && !less(pivot, S[l].first))
			{
				l++;		// scan right till larger
				compares++;
			}
			while (r >= l && !less(S[r].first, pivot))
			{
				r--;		// scan left till smaller
				compares++;
			}
			if (l < r)					// both elements found
			{
				std::swap(S[l], S[r]);
				dataMoves += 3;
			}
		}							// until indices cross
		std::swap(S[l], S[b]);				// store pivot at l
		dataMoves += 3;
		quickSortStep3(S, a, l - 1, less);			// recur on both sides
		quickSortStep3(S, l + 1, b, less);
	}

	int middleOfThree(vector<pair<int, string>>& S, int a, int b, int c)
	{
		// x is positive if a is greater than b.  
		// x is negative if b is greater than a. 
		int x = S[a].first - S[b].first;
		int y = S[b].first - S[c].first;  // Similar to x 
		int z = S[a].first - S[c].first;  // Similar to x and y. 

		// Checking if b is middle (x and y both 
		// are positive) 
		if (x * y > 0)
			return b;

		// Checking if c is middle (x and z both 
		// are positive) 
		else if (x * z > 0)
			return c;
		else
			return a;
	}

	int middleOfThree(vector<pair<string, int>>& S, int a, int b, int c)
	{
		// x is positive if a is greater than b.  
		// x is negative if b is greater than a. 
		int x = S[a].second - S[b].second;
		int y = S[b].second - S[c].second;  // Similar to x 
		int z = S[a].second - S[c].second;  // Similar to x and y. 

		// Checking if b is middle (x and y both 
		// are positive) 
		if (x * y > 0)
			return b;

		// Checking if c is middle (x and z both 
		// are positive) 
		else if (x * z > 0)
			return c;
		else
			return a;
	}

	template <typename E>
	void print1(const vector<E> v, ofstream& outfile);


	///////////////////////       Extra Credit        ///////////////////////////////



};

template <typename E>
void Sorting::print1(const vector<E> v, ofstream& outfile)
{
	for (int i = 0; i < 5; i++)
	{
		outfile << v[i].first << " ";
	}
	outfile << "...";
	for (int i = v.size() - 5; i < v.size(); i++)
	{
		outfile << v[i].first << " ";
	}
	outfile << endl;
}