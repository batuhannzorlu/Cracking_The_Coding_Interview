// sorting_and_searching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include <iostream>
#include<string>
#include<algorithm>
#include <unordered_map>
#include <map>

using namespace std;


//10.1 Merge 2 sorted array

void merge_two_sorted_arr(int A[], int B[],int size_A,int size_B) {

	int merged_index = size_A + size_B - 1;
	int index_A = size_A - 1;
	int index_B = size_B - 1;

	//for (size_t i = 0; i < index_B; i++)
	//{
	//	if (A[i] > B[i]) {
	//		A[merged_index]=
	//	}
	//}


}


// 10.2  grup Anagrams
bool IsAnagram(string s1, string s2) {

	//if (s1.size() < s2.size())
	//    return true;

	//return false;
  /*  s1.*/
	return s1 == s2 ? true : false;
	string::iterator it = s1.begin();
	string::iterator it2 = s2.begin();
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < s1.size(); i++)
	{
		sum1 += (int)(*it);
		it++;
	}


	for (int i = 0; i < s2.size(); i++)
	{
		sum2 += (int)(*it2);
		it2++;
	}

	if (sum1 < sum2)
		return true;
	else
		return false;

}
void sort_anagram(string s_arr[], int size) {

	/* for (size_t i = 0; i < size; i++)
		 sort(s_arr[i].begin(), s_arr[i].end());*/

	sort(s_arr, s_arr + (size), IsAnagram);
}

//Hashmap version(better)
void sort_anagramv2(vector<string> string_arr) {

	multimap<string, string> anagram_set;

	typename vector<string>::iterator it = string_arr.begin();
	for (; it != string_arr.end(); it++)
	{
		string t_s = (*it);
		sort((t_s).begin(), (t_s).end());
		anagram_set.insert(pair<string, string>(t_s, (*it)));
	}


	typename multimap<string, string>::iterator it2 = anagram_set.begin();
	vector<string>old_keys;
	for (; it2 != anagram_set.end(); it2++)
	{
		std::pair<multimap<string, string>::iterator, multimap<string, string>::iterator> result = anagram_set.equal_range(it2->first);

		//Iterate over the range
		for (multimap<string, string>::iterator it = result.first; it != result.second; it++) {
			if (old_keys.end() == find(old_keys.begin(), old_keys.end(), it->second))
				old_keys.push_back(it->second);
		}

	}
	typename vector<string>::iterator itx = old_keys.begin();
	for(; itx != old_keys.end(); itx++)
		cout << *itx <<" "<< endl;
	
}


//10.8 you only have 4kilobytes of memory and range 0-32000

void swap(short* xp, short* yp)
{
	short temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort 
void bubbleSort(unique_ptr<vector<short>>& arr, short n)
{
	short i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place 
		for (j = 0; j < n - i - 1; j++)
			if (arr->at(j) > arr->at(j + 1))
				swap(&arr->at(j), &arr->at(j+1));
}

vector<short> find_duplicates(unique_ptr<vector<short>>&s_arr) {

	vector<short> duplicate_arr;
	bubbleSort(s_arr,s_arr->size());
	vector<short>::iterator it = adjacent_find(s_arr->begin(), s_arr->end());
	while (it != s_arr->end())
	{
		duplicate_arr.push_back(*it);
		it = adjacent_find(it+1, s_arr->end());
		
	}


	return duplicate_arr;
	
}



int main()
{



	srand(time(NULL)); // Seed the time

	unique_ptr<vector<short>> s_arr = make_unique<vector<short>>(3200);

	for (size_t i = 0; i < 3200; i++)
	{
		s_arr->push_back(rand() % (32)+1);
		cout << s_arr->back() << " " << endl;;
	}

	//vector<short> my_d_arr = find_duplicates(s_arr);
	//vector<short>::iterator it;
	//for(it = my_d_arr.begin(); it != my_d_arr.end(); it++)
	//{
	//	cout << *it << " " << endl;
	//}
	/*string s_arr[] = { "asd","lok","poi","dsa","offffkm" };

	vector<string>string_arr = { "asd","lok","poi","dsa","fkm","ads","iop","pio" };
	sort_anagramv2(string_arr);*/


	//sort_anagram(s_arr,5);
	//for (size_t i = 0; i < 5; i++) { cout << s_arr[i] << " "; }
	_CrtDumpMemoryLeaks();
}


