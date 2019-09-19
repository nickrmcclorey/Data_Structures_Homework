#include <string>
using namespace std;

class StackUnderflowException {
	public:
		string message;
		StackUnderflowException() {
			message = "Stack Underflow error. Stack is already empty"; 
		}
};
