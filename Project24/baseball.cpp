#include "stdexcept"
#include <string>

using std::string;
using std::exception;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3)
			throw std::length_error("Must be three letters.");

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9')
				throw std::invalid_argument("Must be number");
		}
	}
};