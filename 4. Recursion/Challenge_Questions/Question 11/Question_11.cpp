#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::vector<int>> ListToSpecifiedSum(std::vector<int> array, int specifiedSum) {
	if (array.size() == 0) {
		return {};
	};

	std::vector<std::vector<int>> listOfCombinations = {};

	int formerFirstElementOfArray = array[0];

	array.erase(array.begin());


	if (formerFirstElementOfArray == specifiedSum) {
		listOfCombinations.push_back({ formerFirstElementOfArray });
	}

	else {
		for (int i = 0; i < array.size(); i++) {
			int currentSum = formerFirstElementOfArray + array[i];

			if (currentSum < specifiedSum) {
				int k = i;

				for (int j = 0; j < ((array.size() - i) - 1); j++) {
					if ((currentSum + array[++k]) == specifiedSum) {
						listOfCombinations.push_back({ formerFirstElementOfArray, array[i], array[k] });
					};
				};
			}

			else if (currentSum == specifiedSum) {
				listOfCombinations.push_back({ formerFirstElementOfArray, array[i] });
			}
		};
	};


	std::vector<std::vector<int>> returnVector = ListToSpecifiedSum(array, specifiedSum);

	for (int z = 0; z < returnVector.size(); z++) {
		listOfCombinations.push_back(returnVector[z]);
	};

	return listOfCombinations;
};


int main(void) {
	std::vector<std::vector<int>> array = ListToSpecifiedSum({ 2, 4, 6, 8 }, 8);

	for (int i = 0; i < array.size(); i++) {
		for (int j = 0; j < array[i].size(); j++) {
			std::cout << (array[i])[j];
		};

		std::cout << std::endl;
	};

	return 0;
};