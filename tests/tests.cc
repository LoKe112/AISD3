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

TEST(bubble_sort, aboba) {
	int seed = 983747;
	fill_file_random_seed(1, "E:\\AISD3\\rand_data_bubble_sort.txt", 2, seed, 2);	
}

TEST(shaker_sort, aboba) {
	int seed = 983747;
	fill_file_random_seed(2, "E:\\AISD3\\rand_data_shaker_sort.txt", 2, seed, 2);
}

/*TEST(natural_two_way_sort, aboba) {
	int seed = 983747;
	fill_file_random_seed(3, "E:\\AISD3\\rand_data_natural_two_way_sort.txt", 1, seed, 2);
}*/

/*TEST(bubble_sort, aboba_1) {
	int seed = 983747;
	fill_file_random_seed(1, "E:\\AISD3\\sorted_data_bubble_sort.txt", 1, seed, 0);
}

TEST(shaker_sort, aboba_1) {
	int seed = 983747;
	fill_file_random_seed(2, "E:\\AISD3\\sorted_data_shaker_sort.txt", 1, seed, 0);
}

TEST(natural_two_way_sort, aboba_1) {
	int seed = 983747;
	fill_file_random_seed(3, "E:\\AISD3\\sorted_data_natural_two_way_sort.txt", 1, seed, 0);
}
*/
/*TEST(bubble_sort, aboba_1) {
	int seed = 983747;
	fill_file_random_seed(1, "E:\\AISD3\\unsorted_data_bubble_sort.txt", 1, seed, 1);
}

TEST(shaker_sort, aboba_1) {
	int seed = 983747;
	fill_file_random_seed(2, "E:\\AISD3\\unsorted_data_shaker_sort.txt", 1, seed, 1);
}

TEST(natural_two_way_sort, aboba_1) {
	int seed = 983747;
	fill_file_random_seed(3, "E:\\AISD3\\unsorted_data_natural_two_way_sort.txt", 1, seed, 1);
}*/