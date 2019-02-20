#include <iostream>
#include <math.h>
#include <stdio.h>

template <class vector>

void shuffle(vector<int> &a) 
{
	int N = a.size();
	for (int i = N - 1; i>0; --i) {  // gist, note, i>0 not i>=0
		int r = rand() % (i + 1); // gist, note, i+1 not i. "rand() % (i+1)" means 
								  // generate rand numbers from 0 to i
		swap(a[i], a[r]);
	}
}

// the implementation in C++ STL
template <class RandomAccessIterator, class RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
	RandomNumberGenerator& gen)
{
	iterator_traits<RandomAccessIterator>::difference_type i, n;
	n = (last - first);
	for (i = n - 1; i>0; --i) {
		swap(first[i], first[gen(i + 1)]);
	}
}
int main()
{
	int a[] = { 11, 22, 33, 44, 55 };
	
	shuffle(<&a);


	return 0;
}