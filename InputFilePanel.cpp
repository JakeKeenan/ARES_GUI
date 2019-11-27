#include "InputFilePanel.h"

InputFilePanel::InputFilePanel(wxWindow* parent) 
	:wxPanel(parent)
{
	//wxDirDialog dlg(this, "Choose input directory", "",
	//	wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	//dlg.ShowModal();

	selectFileDialog = new wxFileDialog(this, "Select File For Input", "", "",
		"TXT files (*.txt)|*.txt", wxFD_OPEN|wxFD_FILE_MUST_EXIST);


	wxStaticBoxSizer* container = new wxStaticBoxSizer(wxHORIZONTAL, this, "Input Files");

	wxStaticBoxSizer* tankerFileLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), "Tanker Position Input File");
	tankerFile = new wxTextCtrl(tankerFileLabel->GetStaticBox(), wxID_ANY, "...");
	tankerFileLabel->Add(tankerFile, wxEXPAND);
	searchTankerFile = new wxButton(tankerFileLabel->GetStaticBox(), SEARCH_TANKER_ID, "Search");

	tankerFileLabel->Add(searchTankerFile, 0, wxEXPAND);
	container->Add(tankerFileLabel, wxEXPAND);
	
	wxStaticBoxSizer* receiverFileLabel = new wxStaticBoxSizer(wxHORIZONTAL, container->GetStaticBox(), "Receiver Positions Input File");
	receiverFile = new wxTextCtrl(receiverFileLabel->GetStaticBox(), wxID_ANY, "...");
	receiverFileLabel->Add(receiverFile, wxEXPAND);
	searchReceiverFile = new wxButton(receiverFileLabel->GetStaticBox(), SEARCH_RECEIVER_ID, "Search");

	receiverFileLabel->Add(searchReceiverFile, 0, wxEXPAND);
	container->Add(receiverFileLabel, wxEXPAND);

	this->SetSizer(container);

	//this->startButton->Bind(wxEVT_BUTTON, &SplashFrame::onStart, this, START_ARES_ID);
	this->Bind(wxEVT_BUTTON, &InputFilePanel::onSearchTanker, this, SEARCH_TANKER_ID);
	this->Bind(wxEVT_BUTTON, &InputFilePanel::onSearchReceiver, this, SEARCH_RECEIVER_ID);
}

InputFilePanel::~InputFilePanel() {
	delete selectFileDialog;
}

void InputFilePanel::onSearchTanker(wxCommandEvent& event)
{
	selectFileDialog->SetMessage("Select Tanker Input File");
	if (selectFileDialog->ShowModal() != wxID_CANCEL) {
		tankerFile->SetValue(selectFileDialog->GetPath());
		tankerFile->ShowPosition(tankerFile->GetLineLength(0));
	}
}
void InputFilePanel::onSearchReceiver(wxCommandEvent& event)
{
	selectFileDialog->SetMessage("Select Receiver Input File");
	if (selectFileDialog->ShowModal() != wxID_CANCEL) {
		receiverFile->SetValue(selectFileDialog->GetPath());
		receiverFile->ShowPosition(tankerFile->GetLineLength(0));
	}
}

std::string InputFilePanel::getTankerFile() {
	return std::string(tankerFile->GetValue().mb_str());
}

std::string InputFilePanel::getReceiverFile() {
	return std::string(receiverFile->GetValue().mb_str());
}