#ifndef WORDTRANSFORM
#define WORDTRANSFORM

using namespace std;

#include<map>
#include<fstream>
#include<string>

void wordTransform(std::ifstream &, std::ifstream &);
const std::string& transform(const std::string&, const std::map<std::string,std::string> &);
std::map<std::string,std::string> buildMap(std::ifstream&);

#endif
