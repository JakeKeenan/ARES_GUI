#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class test :
	public wxFrame
{
public: 
	test(std::string windowTitle, int width, int height);
private:
};

