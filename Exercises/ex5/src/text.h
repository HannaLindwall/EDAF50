#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Text {
public:

	void addLine(const std::string& line) { lines.push_back(line); for(auto s : lines) cout << s << endl; }
	//creating iterator
	class TextIterator {
	public:
		TextIterator(std::vector<std::string>* l, size_t start_l) : lines(l), line(start_l), pos(0) {}
		bool operator!=(const TextIterator& ti) const{
			return lines != ti.lines || ti.pos != pos || ti.line != line;
		}
		TextIterator& operator++(){
			pos++;
			if(pos == (*lines)[line].size()) {
				pos = 0;
				line++;
			}
			return *this;
		}
		char& operator*() const{return (*lines)[line].at(pos);}
	private:
		std::vector<std::string>* lines;
		std::size_t line;
		std::string::size_type pos;
	};
	//using iterator
	using iterator = TextIterator;
	iterator begin(){ return iterator(&lines, 0);}
	iterator end(){ return iterator(&lines, lines.size());}

private:
	std::vector<std::string> lines;
};

#endif
