#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <list>

class LogItemEnd { };

class LogList
{
public: 
    typedef std::ostream& (*Manipulator)(std::ostream&);
    typedef std::ios_base& (*Flags)(std::ios_base&);

    LogList() : printOn(false) {}

    LogList& operator<<(LogItemEnd&&);

    // template<class T>
    // LogList& operator<<(const T& msg);
    template<class T>
    LogList& operator<<(T&& msg) { // int, float, std::string, user defined etc.
        currentlog << msg;
        return *this;
    }
    LogList& operator<<(Manipulator manipFunc) { // endl, flush, setfill, ...
        manipFunc(currentlog);
        return *this;
    }
    LogList& operator<<(Flags flagFunc) { // setiosflags, resetiosflags
        flagFunc(currentlog);
        return *this;
    }

    void end();

    void SetPrint(bool s) {
        printOn = s;
    }

private: 
    void Print(const std::string& str) const;

private: 
    bool printOn;
    std::string type;
    std::stringstream currentlog;
    std::list<std::string> loglist;
};

LogList& LogList::operator<<(LogItemEnd&&) {
    end();
    return *this;
}

void LogList::Print(const std::string& str) const {
    if(printOn) {
        std::cout << str << std::endl;
    }
}

void LogList::end() {
    const std::string& str = currentlog.str();
    loglist.push_back(str);
    Print(str);
    currentlog.str(std::string()); //clear buffer
    currentlog.clear(); //set state
}

// class Logger 
// {
// public: 
//     static Logger& GetInstance() {
//         static Logger instance;
//         return instance;
//     }
//     void SetPrintAll(bool s) {
//         defaultPrintOn = s;

//     }
//     OLog_T& operator[](const std::string& group) {

//     }

// private: 
//     Logger() : defaultPrintOn(false)
//     {
//     }
// private: 
//     bool defaultPrintOn;
//     std::unordered_map< std::string, std::list<Log_T> > logGroup;
//     std::unordered_map< std::string, OLog_T > logGroupOutput;
//     std::unordered_map< std::string, bool > logGroupPrintOn;

// };

#endif