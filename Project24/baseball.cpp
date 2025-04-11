#include "stdexcept"
#include <string>

using std::string;
using std::exception;

class Baseball {
public:
	void guess(const string& string) {
		throw std::length_error("Must be three letters.");
	}
};