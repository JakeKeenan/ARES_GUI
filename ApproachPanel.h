#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <iostream>
#include <sstream>
#include "Data.h"

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
	ApproachPanel(wxWindow *parent);
	
	~ApproachPanel();

	Data::ApproachPatternInputs getPatternInputs();
private:
	const wxString TOGGLE_INPUTS = wxString("Select Approach Pattern");

	wxPanel* patternInputs = nullptr;

	//std::vector<std::string> caseArray;
	wxArrayString caseArray;
	wxComboBox* patternToggle = nullptr;
	wxTextCtrl* closureRate = nullptr;

	wxTextCtrl* xField = nullptr;
	wxTextCtrl* yField = nullptr;
	wxTextCtrl* zField = nullptr;

	wxArrayString getCases();
	
	double convertToDouble(wxString);
};

