#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "LogoPanel.h"
#include "ApproachPanel.h"
class SplashFrame :
	public wxFrame
{
public:
	SplashFrame(std::string windowTitle, int width, int height, std::string image);
	SplashFrame(std::string windowTitle, wxSize size, std::string image);
	~SplashFrame();
private:
	LogoPanel* logoDisplay;
	ApproachPanel* approachDisplay;

	void add(wxMenuBar* menuBar);
	void add(wxPanel* splashPanel);

	void onExit(wxCommandEvent& event);
	void onAbout(wxCommandEvent& event);
};

