#ifndef TRANSTEXT
#define TRANSTEXT

#include<memory>
#include<map>
#include<string>

std::shared_ptr<std::map<std::string,std::string>> BuildMap(char* );
bool transText(char* ,std::shared_ptr<std::map<std::string,std::string>>,char *);

#endif
