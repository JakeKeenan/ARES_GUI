#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Data.h"
class InputsPanel :
	public wxPanel
{
public:
	InputsPanel(wxWindow *parent);
	Data::InputProperties getInputProperties();
private:

	wxTextCtrl* hoseAeroGain = nullptr;
	wxTextCtrl* drogueAeroGain = nullptr;
	wxTextCtrl* hoseStiffnessGain = nullptr;
	wxTextCtrl* hoseDampingGain = nullptr;

	double convertToDouble(wxString);
};

