#pragma once
#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "SplashPanel.h"
class MainFrame :
	public wxFrame
{
public:
	MainFrame(std::string windowTitle, wxSize size, std::string image, wxFrame** pointer);
private:
	wxBoxSizer* container;


	void add(wxMenuBar* menuBar);
	void onExit(wxCommandEvent& event);
	void onAbout(wxCommandEvent& event);
};

