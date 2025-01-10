#include <vector>
#include <iostream>
#include <unistd.h>
#include <algorithm>

void printing(std::vector<std::vector<std::string>>& vec)noexcept {
	for (int i = 0; i < vec.size();++i) {
		for (int j = 0; j < vec.size();++j) {
			std::cout << vec[i][j] << " ";

			if (j == vec.size() - 1) {
				std::cout << '\n';
			}
		}
		//(void)getchar();
	}
	usleep(10000);
	system("clear");
}

void change_to_star(std::vector<std::vector<std::string>>& vec, size_t i = 0, size_t j = 0) {
	size_t count = 0;

	bool bool_spec = false;
	while (count < vec.size() / 2 + 1) {
		bool_spec = false;
		while (j < vec.size() - count) {
			if (bool_spec) printing(vec);
			else bool_spec = true;
			vec.at(i).at(j) = "*";
			++j;
		}
		--j;
		//std::cout << j << " j";
			//(void)getchar();
		bool_spec = false;
		while (i < vec.size() - count) {
			if (bool_spec) printing(vec);
			else bool_spec = true;
			//printing(vec);
			vec.at(i).at(j) = "*";
			++i;
			//(void)getchar();
		}
		--i;
		//std::cout << i << " i";
		while (j > count) {
			vec.at(i).at(j) = "*";
			--j;
			printing(vec);
		}
		//std::cout << j << " j";
		while (i > count) {
			vec.at(i).at(j) = "*";
			--i;
			printing(vec);
		}
		//std::cout << i << "\n i\n";
		++count;
		i = count;
		j = count;
	}
}

int main() {
	using std::vector, std::cout, std::cin, std::string, std::fill;

	size_t x;
	cout << "Enter number for side: ";
	cin >> x;


	vector<string> vec_in(x);
	vector<vector<string>> vec_big(x);
	fill(vec_in.begin(), vec_in.end(), " ");
	fill(vec_big.begin(), vec_big.end(), vec_in);

	try {
		change_to_star(vec_big);
	}
	catch (std::exception& ec) {
		cout << ec.what();
	}


}