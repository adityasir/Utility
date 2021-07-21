#include<iostream>
#include <vector>
#include <iostream>
using namespace std;

auto tokenize(std::string const &str, const char delim)
{
    size_t start;
    size_t end = 0;
	std::vector<std::string> out; 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
	return out;
}

int main() {
	const auto delim =',';
	const auto str ="23,44,55,44,33,22,44,55";
	const auto out = tokenize(str,delim); 	
	for(const auto item:out){
	std::cout<<item<<" ";
	}
return 1;
}
