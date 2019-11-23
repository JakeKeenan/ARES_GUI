#include "ApproachPanel.h"
ApproachPanel::ApproachPanel(wxFrame *parent):
	wxPanel(parent)
{
	wxStaticBoxSizer* container = new wxStaticBoxSizer(wxHORIZONTAL, this, "Approach Pattern Inputs");

	wxStaticBoxSizer* toggleLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), TOGGLE_INPUTS);
	//caseList = getCases();
	patternToggle = new wxComboBox(toggleLabel->GetStaticBox(), PATTERN_TOGGLE_ID, TOGGLE_INPUTS);
	toggleLabel->Add(patternToggle, wxEXPAND);
	container->Add(toggleLabel, 3, wxEXPAND, 200);

	wxBoxSizer* patternInputsContainer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticBoxSizer* gainLabel = new wxStaticBoxSizer(wxHORIZONTAL, this, "Closure Rate Gain");
	closureRate = new wxTextCtrl(gainLabel->GetStaticBox(), CLOSURE_RATE_ID, "1.0");
	gainLabel->Add(closureRate, wxEXPAND);
	patternInputsContainer->Add(gainLabel, wxEXPAND);
	wxStaticBoxSizer* offsetLabel = new wxStaticBoxSizer(wxVERTICAL, this, "Initial Position Offset");
	xField = new wxTextCtrl(offsetLabel->GetStaticBox(), wxID_ANY, "0.0");
	yField = new wxTextCtrl(offsetLabel->GetStaticBox(), wxID_ANY, "0.0");
	zField = new wxTextCtrl(offsetLabel->GetStaticBox(), wxID_ANY, "0.0");
	offsetLabel->Add(xField, wxEXPAND);
	offsetLabel->Add(yField, wxEXPAND);
	offsetLabel->Add(zField, wxEXPAND);
	patternInputsContainer->Add(offsetLabel, wxEXPAND);

	container->Add(patternInputsContainer, 5, wxEXPAND, 200);
	


	
	this->SetSizer(container);
}