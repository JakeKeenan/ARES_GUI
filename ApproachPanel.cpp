#include "ApproachPanel.h"
ApproachPanel::ApproachPanel(wxWindow *parent):
	wxPanel(parent)
{
	wxStaticBoxSizer* container = new wxStaticBoxSizer(wxHORIZONTAL, this, "Approach Pattern Inputs");

	wxStaticBoxSizer* toggleLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), TOGGLE_INPUTS);
	caseArray = getCases();
	std::string caseSelect;
	if (caseArray.size() == 0) {
		caseSelect = "No Cases Found";
	}
	else {
		caseSelect = caseArray.back();
	}
	patternToggle = new wxComboBox(toggleLabel->GetStaticBox(), PATTERN_TOGGLE_ID, caseSelect);
	patternToggle->Append(caseArray);
	toggleLabel->Add(patternToggle, wxEXPAND);



	container->Add(toggleLabel, 3, wxEXPAND);

	wxBoxSizer* patternInputsContainer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticBoxSizer* gainLabel = new wxStaticBoxSizer(wxHORIZONTAL, this, "Closure Rate Gain");
	closureRate = new wxTextCtrl(gainLabel->GetStaticBox(), CLOSURE_RATE_ID, "1.0");
	gainLabel->Add(closureRate, wxEXPAND);
	patternInputsContainer->Add(gainLabel, wxEXPAND);

	wxStaticBoxSizer* offsetLabel = new wxStaticBoxSizer(wxVERTICAL, this, "Initial Position Offset");

	wxBoxSizer* xAxisHolder = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* xLabel = new wxStaticText(offsetLabel->GetStaticBox(), wxID_ANY, "x");
	xField = new wxTextCtrl(offsetLabel->GetStaticBox(), wxID_ANY, "0.0");
	xAxisHolder->Add(xLabel, 2, wxEXPAND);
	xAxisHolder->Add(xField, 10, wxEXPAND);
	wxBoxSizer* yAxisHolder = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* yLabel = new wxStaticText(offsetLabel->GetStaticBox(), wxID_ANY, "y");
	yField = new wxTextCtrl(offsetLabel->GetStaticBox(), wxID_ANY, "0.0");
	yAxisHolder->Add(yLabel, 2, wxEXPAND);
	yAxisHolder->Add(yField, 10, wxEXPAND);
	wxBoxSizer* zAxisHolder = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* zLabel = new wxStaticText(offsetLabel->GetStaticBox(), wxID_ANY, "z");
	zField = new wxTextCtrl(offsetLabel->GetStaticBox(), wxID_ANY, "0.0");
	zAxisHolder->Add(zLabel, 2, wxEXPAND);
	zAxisHolder->Add(zField, 10, wxEXPAND);

	offsetLabel->Add(xAxisHolder, wxEXPAND);
	offsetLabel->Add(yAxisHolder, wxEXPAND);
	offsetLabel->Add(zAxisHolder, wxEXPAND);
	patternInputsContainer->Add(offsetLabel, wxEXPAND);

	container->Add(patternInputsContainer, 5, wxEXPAND);

	this->SetSizer(container);
}

ApproachPanel::~ApproachPanel() {
}

wxArrayString ApproachPanel::getCases() {
	wxArrayString retVal;
	for (int i = 3; i > 0; i--) {
		retVal.push_back("Case " + std::to_string(i));
	}
	return retVal;
}

Data::ApproachPatternInputs ApproachPanel::getPatternInputs() {
	Data::ApproachPatternInputs retVal;
	retVal.approachPattern = patternToggle->GetSelection();
	retVal.closureRateGain = convertToDouble(closureRate->GetValue());
	retVal.locationVector.x = convertToDouble(xField->GetValue());
	retVal.locationVector.y = convertToDouble(yField->GetValue());
	retVal.locationVector.z = convertToDouble(zField->GetValue());
	return retVal;

}

double ApproachPanel::convertToDouble(wxString str) {
	double retVal;
	if (!str.ToDouble(&retVal)) {
		//error handle
	}
	return retVal;
}