#include <iostream>
#include <cstring>
#include <vector>


int main() {

	struct functions {
		int id;
		const char * name;
	} funcs;

	std::vector<struct functions> fcs;
	funcs.id = 1;
	funcs.name = "hello";
	fcs.push_back(funcs);
	funcs.id = 2;
	funcs.name = "nameq";
	fcs.push_back(funcs);

	std::vector<struct functions>::iterator n;
	for(n=fcs.begin(); n!=fcs.end(); n++)
		std::cout << n->name << std::endl;



	return 0;
}
