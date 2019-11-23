#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
enum inputIDs {
	PATTERN_TOGGLE_ID,
	PATTERN_INPUTS_ID,
	CLOSURE_RATE_ID,
	INITIAL_OFFSET_ID
};

class ApproachPanel :
	public wxPanel
{
public:
	ApproachPanel(wxFrame *parent);
private:
	const wxString TOGGLE_INPUTS = wxString("Select Approach Pattern");

	wxPanel* patternInputs = nullptr;
	wxComboBox* patternToggle = nullptr;
	wxTextCtrl* closureRate = nullptr;

	wxTextCtrl* xField = nullptr;
	wxTextCtrl* yField = nullptr;
	wxTextCtrl* zField = nullptr;
};

