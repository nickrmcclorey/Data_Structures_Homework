#include <string>

class EmptyQueueException {
    public:
        std::string message;
        EmptyQueueException() {
            message = "Queue is empty";
        }
};