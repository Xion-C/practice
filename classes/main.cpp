#include <iostream>
#include <cstring>


class string {
public:
	string() : 
	buf(new char[1]) {
		buf[0] = '\0';
		std::cout << "default" << strlen(buf) <<std::endl;
	}
	string(const char* s) : 
	buf(new char[strlen(s)+1]) {
		//buf[0] = '\0'; //seems no need
		strcpy(buf, s);
		std::cout << "conversion" <<std::endl;
		if (buf[6]=='\0') std::cout << "yes" <<std::endl;
		else std::cout << "no" <<std::endl;
	}
	string(const string & s) : 
	buf(new char(strlen(s.buf)+1)) {
		strcpy(buf, s.buf);
		std::cout << "copy" <<std::endl;
	}

	~string() {
		std::cout << "delete : " << buf <<std::endl;
		delete [] buf;
	}

private:
	char *buf;
};

int tryconst(int m)
{
	return m+1;
}

int main() {

	string a;
	string b("abcde");
	std::cout << "string " << "" << std::endl;
	//std::cout << "char " << b << std::endl;
	int m1=10;
	const int m2=20;
	tryconst(m1);
	tryconst(m2);

	return 0;
} 
