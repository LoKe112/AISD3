#include <gtest/gtest.h>
#include <functions/algorithm.h>

using namespace std;
using namespace algorithm;

TEST(bubble_sort, test_1) {
	int seed = 983747;
	vector<stats> a = test_func(1, 100, 2, 2, seed);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].comparison_count << " " << a[i].copy_count << endl;
		
	}
}

TEST(shaker_sort, test_1) {
	int seed = 983747;
	vector<stats> a = test_func(2, 100, 2, 2, seed);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].comparison_count << " " << a[i].copy_count << endl;
	}
}

TEST(natural_two_way_sort, test_1) {
	int seed = 983747;
	vector<stats> a = test_func(3, 100, 2, 2, seed);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].comparison_count << " " << a[i].copy_count << endl;
	}
	
}

