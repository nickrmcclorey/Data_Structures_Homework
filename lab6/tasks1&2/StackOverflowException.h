#include <string>
using namespace std;

class StackOverflowException {
	public:
		string message;
		StackOverflowException(int maxSize) {
			message = "Stack Overflow Error: max size is " + to_string(maxSize);
		}
};
