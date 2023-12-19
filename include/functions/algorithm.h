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
	
    std::vector<int> merge_ascending(std::vector<int> left, std::vector<int> right) {
        std::vector<int> result;

        int i = 0, j = 0;

        if (left.size() > right.size() && left.back() == right.back())
            left.pop_back();
        else if (right.size() > left.size() && left.back() == right.back())
            right.pop_back();

        while (i < left.size() && j < right.size()) {
            int item = left[i] <= right[j] ? left[i++] : right[j++];
            if (!result.empty() && item == result.back())
                continue;

            result.push_back(item);
        }

        result.insert(result.end(), left.begin() + i, left.end());
        result.insert(result.end(), right.begin() + j, right.end());

        return result;
    }

    std::vector<int> merge_descending(const std::vector<int>& left, const std::vector<int>& right) {
        std::vector<int> result = merge_ascending(left, right);

        for (int i = 0; i < result.size()/2; i++) {
            int temp = result[i];
            result[i]= result[result.size() - i - 1];
            result[result.size() - i - 1] = temp;
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
                } while (left < list.size() - 1 && left + 1 < right && list[left] <= list[left + 1]);

                series.push_back(one_series);

                one_series.clear();

                do {
                    right--;
                    one_series.push_back(list[right]);
                } while (right > 1 && left - 1 < right && list[right - 1] >= list[right]);

                series.push_back(one_series);
            }

            if (series.size() == 2 && series[1].size() == 1)
                break;

            std::vector<std::vector<int>> result_left;
            std::vector<std::vector<int>> result_right;

            int current_series = 0;

            while (current_series < series.size() - 1) {
                result_left.push_back(merge_ascending(series[current_series], series[current_series + 1]));
                current_series += 2;

                if (current_series >= series.size() - 1)
                    break;

                result_right.insert(result_right.begin(), merge_descending(series[current_series], series[current_series + 1]));
                current_series += 2;
            }

            list.clear();
            for (auto& s : result_left)
                list.insert(list.end(), s.begin(), s.end());
            for (auto& s : result_right)
                list.insert(list.end(), s.begin(), s.end());
        }

        return cur_stat;
    }
}
	