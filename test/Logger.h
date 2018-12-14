#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <list>

#include <vector>

class LogItemEnd { };

typedef LogItemEnd LEND;

class LogList
{
public: 
    typedef std::ostream& (*Manipulator)(std::ostream&);
    typedef std::ios_base& (*Flags)(std::ios_base&);

    LogList(const std::string& tp = "") : 
        printOn(false), 
        type(tp),
        currentlog(),
        loglist()
    {}

    LogList(const LogList& ls) {
        printOn = ls.printOn;
        type = ls.type;
        currentlog.str(ls.currentlog.str());
        loglist = ls.loglist;
    }

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

    void SetType(const std::string& tp) {
        type = tp;
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
        std::string prefix;
        if(type.length() > 0) {
            prefix = "[" + type + "]" + " ";
        }
        std::cout << prefix << str << std::endl;
    }
}

void LogList::end() {
    const std::string& str = currentlog.str();
    loglist.push_back(str);
    Print(str);
    currentlog.str(std::string()); //clear buffer
    currentlog.clear(); //set state
}

class Logger 
{
public: 
    static Logger& GetInstance() {
        static Logger instance;
        return instance;
    }
    void SetAllPrint(bool s) {
        defaultPrintOn = s;
        // for(auto& p : logGroupPrint) {
        //     p.second = s;
        // }
        for(auto& ls : logGroup) {
            ls.second.SetPrint(s);
        }
    }
    void SetPrint(const std::string& group, bool s) {
        logGroup[group].SetPrint(s);
    }

    LogList& operator[](const std::string& group) {
        auto iter = logGroup.find(group);
        if(iter == logGroup.end()) {
            logGroup[group].SetType(group);
            logGroup[group].SetPrint(defaultPrintOn);
        }
        return logGroup[group];
    }

private: 
    Logger() : 
        defaultPrintOn(false),
        logGroup()
    {
    }
private: 
    bool defaultPrintOn;
    std::unordered_map< std::string, LogList> logGroup;
    //std::unordered_map< std::string, bool > logGroupPrint;

};

#endif