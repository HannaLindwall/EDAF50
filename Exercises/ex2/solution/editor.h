#ifndef EDITOR_H
#define EDITOR_H

#include <string>

class Editor {
public:
	/* Creates a text editor containing the text t */
	Editor(const std::string& t) : text(t) {}
	
	/* 
	 * Text[pos] contains a right parentheses. Returns the position of
	 * the corresponding left parentheses, or string::npos if there
	 * is no match.
	 */
	std::string::size_type find_left_par(std::string::size_type pos) const;
	 
	 // ... functions to edit the text (insert and delete characters)
private:
	std::string text;
};

#endif
