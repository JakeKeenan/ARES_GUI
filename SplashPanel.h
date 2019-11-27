#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "LogoPanel.h"
#include "ApproachPanel.h"
#include "InputsPanel.h"
#include "InputFilePanel.h"
#include "Data.h"
#include "test.h"
class SplashPanel :
	public wxPanel
{
public:
	SplashPanel(wxWindow* parent, wxBoxSizer* container, std::string image);
	~SplashPanel();
private:
	enum {
		START_ARES_ID
	};

	wxBoxSizer* container;

	LogoPanel* logoDisplay;
	ApproachPanel* approachDisplay;
	InputsPanel* inputsDisplay;
	InputFilePanel* inputFilesDisplay;
	wxPanel* startButtonPanel;
	wxButton* startButton;

	void onStart(wxCommandEvent& event);
};

