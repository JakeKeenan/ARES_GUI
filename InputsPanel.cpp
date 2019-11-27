#include "InputsPanel.h"

InputsPanel::InputsPanel(wxWindow* parent) :
	wxPanel(parent) 
{
	wxStaticBoxSizer* container = new wxStaticBoxSizer(wxHORIZONTAL, this, "Input Properties");
	
	wxStaticBoxSizer* hoseAeroLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), "Hose Aero Gain");
	hoseAeroGain = new wxTextCtrl(hoseAeroLabel->GetStaticBox(), wxID_ANY, "1.0");
	hoseAeroLabel->Add(hoseAeroGain, wxEXPAND);
	container->Add(hoseAeroLabel, wxEXPAND);

	wxStaticBoxSizer* drogueAeroLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), "Drogue Aero Gain");
	drogueAeroGain = new wxTextCtrl(drogueAeroLabel->GetStaticBox(), wxID_ANY, "1.0");
	drogueAeroLabel->Add(drogueAeroGain, wxEXPAND);
	container->Add(drogueAeroLabel, wxEXPAND);

	wxStaticBoxSizer* hoseStiffnessLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), "Hose Stiffness Gain");
	hoseStiffnessGain = new wxTextCtrl(hoseStiffnessLabel->GetStaticBox(), wxID_ANY, "1.0");
	hoseStiffnessLabel->Add(hoseStiffnessGain, wxEXPAND);
	container->Add(hoseStiffnessLabel, wxEXPAND);

	wxStaticBoxSizer* hoseDampingLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), "Hose Damping Gain");
	hoseDampingGain = new wxTextCtrl(hoseDampingLabel->GetStaticBox(), wxID_ANY, "1.0");
	hoseDampingLabel->Add(hoseDampingGain, wxEXPAND);
	container->Add(hoseDampingLabel, wxEXPAND);

	this->SetSizer(container);
}

Data::InputProperties InputsPanel::getInputProperties() {
	Data::InputProperties retVal;
	retVal.hoseAeroGain = convertToDouble(hoseAeroGain->GetValue());
	retVal.drogueAeroGain = convertToDouble(drogueAeroGain->GetValue());
	retVal.hoseStiffnessGain = convertToDouble(hoseStiffnessGain->GetValue());
	retVal.hoseDampingGain = convertToDouble(hoseDampingGain->GetValue());
	return retVal;
}

double InputsPanel::convertToDouble(wxString str) {
	double retVal;
	if (!str.ToDouble(&retVal)) {
		//error handle
	}
	return retVal;
}
