#include <gtest/gtest.h>
#include <functions/algorithm.h>

using namespace std;
using namespace algorithm;

TEST(bubble_sort, test_1) {
	vector<int> mass;
	for (int i = 100; i > 0; i--) {
		mass.push_back(i);
	}
	for (int i = 0; i < 100; i++) {
		cout << mass[i] << " ";
	}
	stats stat = bubble_sort(mass);
	cout << "\n";
	for (int i = 0; i < 100; i++) {
		cout << mass[i] << " ";
	}
	cout << "\n\n" << stat.comparison_count << " " << stat.copy_count;
}

TEST(shaker_sort, test_1) {
	vector<int> mass;
	for (int i = 100; i > 0; i--) {
		mass.push_back(i);
	}
	for (int i = 0; i < 100; i++) {
		cout << mass[i] << " ";
	}
	stats stat = shaker_sort(mass);
	cout << "\n";
	for (int i = 0; i < 100; i++) {
		cout << mass[i] << " ";
	}
	cout << "\n\n" << stat.comparison_count << " " << stat.copy_count;
}
