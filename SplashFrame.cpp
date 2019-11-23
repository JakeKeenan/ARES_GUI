#include "SplashFrame.h"
SplashFrame::SplashFrame(std::string windowTitle, int width, int height, std::string image) 
	:wxFrame(NULL, wxID_ANY, windowTitle, wxDefaultPosition, wxSize(width, height))
{
	add(new wxMenuBar());
	
	wxInitAllImageHandlers();
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	

	this->logoDisplay = new LogoPanel(this, wxT("" + image), wxBITMAP_TYPE_PNG);
	
	sizer->Add(logoDisplay, 1, wxEXPAND);
	this->SetSizer(sizer);
	//add(new ApproachInputsPanel());
	//add(new InputsPanel());
}
SplashFrame::SplashFrame(std::string windowTitle, wxSize size, std::string image)
	:wxFrame(NULL, wxID_ANY, windowTitle, wxDefaultPosition, size)
{	
	add(new wxMenuBar());
	wxInitAllImageHandlers();
	//wxBoxSizer* Hsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* layout = new wxBoxSizer(wxVERTICAL);

	this->logoDisplay = new LogoPanel(this, image, wxBITMAP_TYPE_PNG);
	layout->Add(logoDisplay, 1, wxEXPAND);
	
	this->approachDisplay = new ApproachPanel(this);
	layout->Add(approachDisplay, 1, wxEXPAND);
	//add(new ApproachInputsPanel());
	//add(new InputsPanel());
	//Layout();
	//GetSize(int *w, int *h);
	//SetMinSize();
	//Hsizer->Add(Vsizer, 1, wxEXPAND);
	this->SetSizer(layout);
}


SplashFrame::~SplashFrame() {

}

void SplashFrame::add(wxMenuBar* menuBar) {
	wxMenu* fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT);
	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT);
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");
	SetMenuBar(menuBar);
	Bind(wxEVT_MENU, &SplashFrame::onAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &SplashFrame::onExit, this, wxID_EXIT);
}

void SplashFrame::add(wxPanel* splashComponent) {

}

void SplashFrame::onExit(wxCommandEvent& event) {

}

void SplashFrame::onAbout(wxCommandEvent& event) {

}