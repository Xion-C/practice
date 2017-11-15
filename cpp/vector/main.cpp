#include <iostream>
#include <vector>
#include <cstring>
class Token {
public:
	Token() :
	name(new char[strlen("default value")+1]) {
		strcpy(name, "default value");
		std::cout << "default" << std::endl;
	}

	Token(const char * n) :
	name(new char[strlen(n)+1]) {
		strcpy(name, n);
		std::cout << "convert:" << name << std::endl;
	}

	// Token() {
	// 	std::cout << "default" << std::endl;
	// }
	// Token(const char * n) {
	// 	std::cout << "convert:" << n << std::endl;
	// }

	Token(const Token & t) :
	name(new char[strlen(t.name)+2]) {
		strcpy(name, t.name);
		name[strlen(name)] = '*';
		std::cout << "copy";
		printf(":%s\n", name);
	}
	~Token() {
		std::cout << "destruct";
		printf(":%s\n", name);
		//delete [] name;
	}
	Token & operator=(const Token &) {
		std::cout << "assign" << std::endl;
		return *this;
	}
private:
	char * name;
};

class TokenDB {
public:
	TokenDB(const char * name) {
		token = Token(name);
	}
private:
	Token token;
};

int main() {
	//TokenDB db("IDENT");
	std::vector<Token> tokens;
	//tokens.push_back("IDENT");
	//tokens.push_back("FLOAT");
	tokens.emplace_back("IDENT");
	tokens.emplace_back("FLOAT");
}
