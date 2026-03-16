#ifndef EXCEPTION_H
#define EXCEPTION_H



class Exception : public std::exception {
private:
    const char* message;
public:
    explicit Exception(const char* message) : message(message) {}
    const char* what() const noexcept override {
        return message;
    }
};



#endif //EXCEPTION_H
