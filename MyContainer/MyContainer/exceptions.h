#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <exception>
#include <string>


class base_exception: public std::exception
{
    public:
        explicit base_exception() = default;
        explicit base_exception(const std::string msg)
        {
            message = msg;
        }
        explicit base_exception(const char* msg)
        {
            message = msg;
        }
        explicit base_exception(const base_exception& other)
        {
            message = other.message;
        }

    protected:
        std::string message;
};


class bad_alloc: public base_exception
{
    public:
        explicit bad_alloc() = default;
        explicit bad_alloc(const std::string& msg): base_exception(msg) {}
        explicit bad_alloc(const char* msg): base_exception(msg) {}

        virtual const char* what() const noexcept
        {
            if (message.empty()) {
                return "Allocation error.";
            }
            else {
                return message.c_str();
            }
        }
};


class out_of_range: public base_exception
{
    public:
        explicit out_of_range() = default;
        explicit out_of_range(const std::string& msg): base_exception(msg) {}
        explicit out_of_range(const char* msg): base_exception(msg) {}

        virtual const char* what() const noexcept
        {
            if (message.empty()) {
                return "Access to position out of range.";
            }
            else {
                return message.c_str();
            }
        }
};


class logical_error: public base_exception
{
    public:
        explicit logical_error() = default;
        explicit logical_error(const std::string& msg): base_exception(msg) {}
        explicit logical_error(const char* msg): base_exception(msg) {}

        virtual const char* what() const noexcept
        {
            if (message.empty()) {
                return "Logic error.";
            }
            else {
                return message.c_str();
            }
        }
};

class reading_error: public base_exception
{
    public:
        explicit reading_error() = default;
        explicit reading_error(const std::string& msg): base_exception(msg) {}
        explicit reading_error(const char* msg): base_exception(msg) {}

        virtual const char* what() const noexcept
        {
            if (message.empty()) {
                return "Reading error.";
            }
            else {
                return message.c_str();
            }
        }
};

#endif // EXCEPTIONS_H
