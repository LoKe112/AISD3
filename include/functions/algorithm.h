#pragma once

#include<vector>
#include<iostream>
#include<random>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

namespace algorithm {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};

    stats bubble_sort(vector<int>& mass) {
        int temp;
        stats cur_stat;
        for (int i = 0; i < mass.size() - 1; i++) {
            for (int j = 0; j < mass.size() - i - 1; j++) {
                cur_stat.comparison_count++;
                if (mass[j] > mass[j + 1]) {
                    cur_stat.copy_count++;
                    temp = mass[j];
                    mass[j] = mass[j + 1];
                    mass[j + 1] = temp;
                }
            }
        }
        return cur_stat;
    }

    stats shaker_sort(vector<int>& mass) {
        stats cur_stat;
        int control = static_cast<int>(mass.size() - 1);
        int left = 0, right = control;
        do {
            for (int i = left; i < right; i++) {
                cur_stat.comparison_count++;
                if (mass[i] > mass[i + 1]) {
                    cur_stat.copy_count++;
                    std::swap(mass[i], mass[i + 1]);
                    control = i;
                }
            }
            right = control;
            for (int i = right; i > left; i--) {
                cur_stat.comparison_count++;
                if (mass[i] < mass[i - 1]) {
                    cur_stat.copy_count++;
                    std::swap(mass[i], mass[i - 1]);
                    control = i;
                }
            }
            left = control;
        } while (left < right);
        return cur_stat;
    }

    std::vector<int> merge_ascending(std::vector<int> left, std::vector<int> right, stats& cur_stat) {
        std::vector<int> result;

        int i = 0, j = 0;

        if (left.size() > right.size() && left.back() == right.back())
            left.pop_back();
        else if (right.size() > left.size() && left.back() == right.back())
            right.pop_back();

        while (i < left.size() && j < right.size()) {
            cur_stat.comparison_count++;
            int item = left[i] <= right[j] ? left[i++] : right[j++];
            if (!result.empty() && item == result.back())
                continue;

            result.push_back(item);
            cur_stat.copy_count++;
        }

        cur_stat.copy_count += left.size() - i;
        cur_stat.copy_count += right.size() - j;

        result.insert(result.end(), left.begin() + i, left.end());
        result.insert(result.end(), right.begin() + j, right.end());

        return result;
    }

    std::vector<int> merge_descending(const std::vector<int>& left, const std::vector<int>& right, stats& cur_stat) {
        std::vector<int> result = merge_ascending(left, right, cur_stat);

        for (int i = 0; i < result.size() / 2; i++) {
            int temp = result[i];
            result[i] = result[result.size() - i - 1];
            result[result.size() - i - 1] = temp;
            cur_stat.copy_count += 2;
        }

        return result;
    }

    stats natural_two_way_sort(std::vector<int>& list) {
        stats cur_stat;

        if (list.size() < 2)
            return cur_stat;

        while (true) {
            std::vector<std::vector<int>> series;

            int left = -1,
                right = list.size();

            while (left < right) {
                std::vector<int> one_series;

                do {
                    left++;
                    one_series.push_back(list[left]);
                    cur_stat.copy_count++;
                    if (left < list.size() - 1 && left + 1 < right) {
                        cur_stat.comparison_count++;
                    }
                } while (left < list.size() - 1 && left + 1 < right && list[left] <= list[left + 1]);

                series.push_back(one_series);

                one_series.clear();

                do {
                    right--;
                    one_series.push_back(list[right]);
                    cur_stat.copy_count++;
                    if (right > 1 && left - 1 < right) {
                        cur_stat.comparison_count++;
                    }
                } while (right > 0 && left - 1 < right && list[right - 1] >= list[right]);

                series.push_back(one_series);
            }

            if (series.size() == 2 && series[1].size() == 1)
                break;

            std::vector<std::vector<int>> result_left;
            std::vector<std::vector<int>> result_right;

            int current_series = 0;

            while (current_series < series.size() - 1) {
                result_left.push_back(merge_ascending(series[current_series], series[current_series + 1], cur_stat));
                current_series += 2;

                if (current_series >= series.size() - 1)
                    break;

                result_right.insert(result_right.begin(), merge_descending(series[current_series], series[current_series + 1], cur_stat));
                current_series += 2;
            }

            list.clear();
            for (auto& s : result_left) {
                list.insert(list.end(), s.begin(), s.end());
                cur_stat.copy_count += s.size();
            }
            for (auto& s : result_right)
            {
                list.insert(list.end(), s.begin(), s.end());
                cur_stat.copy_count += s.size();
            }
        }

        return cur_stat;
    }

    vector<stats> test_func(int sort_type, int arr_size, int count, int mass_type, int seed) {
        int seed_helper = 0;
        vector<stats> results;
        for (int i = 0; i < count ; i++) {
            vector<int> mass;
            switch (mass_type)
            {
            case 0:
                for (int j = 0; j < arr_size; j++) {
                    mass.push_back(j);
                }
                break;
            case 1:
                for (int j = 0; j < arr_size; j++) {
                    mass.push_back(arr_size - j);
                }
                break;
            case 2:
                mt19937 mt(seed);
                uniform_int_distribution<int> distribution(0, arr_size);

                for (int j = 0; j < arr_size; j++) {
                    mass.push_back(distribution(mt));
                    seed_helper++;
                }
                break;
            }

            if (sort_type == 1) {
                results.push_back(bubble_sort(mass));
            }
            else if (sort_type == 2) {
                results.push_back(shaker_sort(mass));
            }
            else if (sort_type == 3) {
                results.push_back(natural_two_way_sort(mass));
            }
        }
        return results;
    }

    stats average(vector<stats> mass) {
        stats stat;
        for (int i = 0; i < mass.size(); i++) {
            stat.comparison_count += mass[i].comparison_count;
            stat.copy_count += mass[i].copy_count;
        }
        stat.comparison_count /= mass.size();
        stat.copy_count /= mass.size();
        return stat;
    }

    void fill_file(int type, string path, int count, int seed, int sort_type) {
        fstream file;
        file.open(path, std::ios::app);
        vector<int> vals = { 1,2,3,4,5,6,7,8,9,10,25,50,100 };
        if (file) {
            for (int i = 0; i < vals.size(); i++) {                
                vector<stats> res = test_func(type, vals[i] * 1000, count, sort_type, seed);
                file << vals[i] * 1000 << " ";
                stats s = average(res);
                file << s.copy_count << " " << s.comparison_count << endl;
            }
        }
        else {
            cout << "ERROR";
        }
        file.close();
    }

	
}