#include "SplashPanel.h"
SplashPanel::SplashPanel(wxWindow * parent, wxBoxSizer* container, std::string image)
	:wxPanel(parent)
{	
	this->container = container;
	wxInitAllImageHandlers();
	//wxBoxSizer* Hsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* layout = new wxBoxSizer(wxVERTICAL);

	this->logoDisplay = new LogoPanel(this, image, wxBITMAP_TYPE_PNG);
	layout->Add(logoDisplay, 1, wxEXPAND);

	wxBoxSizer* settingsLayout = new wxBoxSizer(wxVERTICAL);

	this->inputFilesDisplay = new InputFilePanel(this);
	settingsLayout->Add(inputFilesDisplay, 0, wxEXPAND);
	
	this->approachDisplay = new ApproachPanel(this);
	settingsLayout->Add(approachDisplay, 0, wxEXPAND);

	this->inputsDisplay = new InputsPanel(this);
	settingsLayout->Add(inputsDisplay, 0, wxEXPAND);

	wxBoxSizer* startButtonLayout = new wxBoxSizer(wxHORIZONTAL);
	this->startButtonPanel = new wxPanel(this);
	this->startButton = new wxButton(startButtonPanel, START_ARES_ID, "Start ARES");
	wxBoxSizer* badName = new wxBoxSizer(wxVERTICAL);
	badName->Add(startButton, 0, wxALIGN_CENTER);
	this->startButtonPanel->SetSizer(badName);
	startButtonLayout->Add(startButtonPanel, 1, wxEXPAND);
	//startButtonLayout->Add(startButton, 0, wxEXPAND);
	settingsLayout->Add(startButtonLayout, 1, wxEXPAND);

	layout->Add(settingsLayout, 1, wxEXPAND);

	this->SetSizer(layout);

	this->startButton->Bind(wxEVT_BUTTON, &SplashPanel::onStart, this, START_ARES_ID);
	//add(new InputsPanel());
	//Layout();
	//GetSize(int *w, int *h);
	//SetMinSize();
	//Hsizer->Add(Vsizer, 1, wxEXPAND);
	
}


SplashPanel::~SplashPanel() {

}



void SplashPanel::onStart(wxCommandEvent& event) {
	Data::APPROACH_PATTERN_INPUTS = approachDisplay->getPatternInputs();
	Data::INPUT_PROPERTIES = inputsDisplay->getInputProperties();
	Data::INPUT_TANKER_FILE = inputFilesDisplay->getTankerFile();
	Data::INPUT_RECEIVER_FILE = inputFilesDisplay->getReceiverFile();

	container->Hide(this);
	container->Detach(this);
	container->Add(new wxPanel(this->GetParent()));
	container->Layout();
	
}
