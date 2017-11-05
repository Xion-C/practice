#include <iostream>
#include <cstring>


class string {
public:
	string() :
	buf(new char[1]) {
		buf[0] = '\0';
		std::cout << "default " << strlen(buf) <<std::endl;
	}
	string(const char* s) :
	buf(new char[strlen(s)+1]) {
		//buf[0] = '\0'; //seems no need
		strcpy(buf, s);
		std::cout << "conversion" <<std::endl;
		if (buf[6]=='\0') std::cout << "end \\0 yes" <<std::endl;
		else std::cout << "no" <<std::endl;
	}
    //explicit string(const string & s) :
	string(const string & s) :
	buf(new char(strlen(s.buf)+1)) {
		strcpy(buf, s.buf);
		std::cout << "copy" <<std::endl;
	}
	~string() {
		std::cout << "delete : " << buf <<std::endl;
		delete [] buf;
	}
  string& operator=(const string & rhs) {
      if(this == &rhs) return *this;
      delete [] buf;
      buf = new char[strlen(rhs.buf)+1];  // here we can use rhs.buf because this is inside the same string class
      strcpy(buf, rhs.buf);
      return *this;
  }
  //int aaa(int a) const { a=2;int b;b=5;return b;}
  //int bbb(int c) const { c=2;c=aaa(10);iii;return c;}

private:
	char *buf;
    //const int iii=11;
};

int main() {

	std::cout << "----------" << std::endl;
	//string a;
	std::cout << "----------" << std::endl;
	string b("abcde");
	std::cout << "----------" << std::endl;
	//string c(b);
	std::cout << "----------" << std::endl;
	//string d;
	std::cout << "----------" << std::endl;
	string e;
	//e = b;
	//std::cout << "----------" << e.aaa(1) <<std::endl;
	//e.bbb(2);


	//std::cout << "string " << a << std::endl;
	//std::cout << "string " << b << std::endl;
	//std::cout << "string " << c << std::endl;
	//std::cout << "string " << d << std::endl;

	return 0;
}
