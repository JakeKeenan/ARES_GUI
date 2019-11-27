#include "test.h"


test::test(std::string windowTitle, int width, int height) :
	wxFrame(NULL, wxID_ANY, windowTitle, wxDefaultPosition, wxSize(width, height)) 
{
	this->Show(true);
}