#include "stdexcept"
#include <string>

using std::string;
using std::exception;

class Baseball {
public:
	void guess(const string& string) {
		if (string.length() != 3)
			throw std::length_error("Must be three letters.");
	}
};