#include "MainFrame.h"

MainFrame::MainFrame(std::string windowTitle, wxSize size, std::string image, wxFrame** pointer)
	:wxFrame(NULL, wxID_ANY, windowTitle, wxDefaultPosition, size)
{
	add(new wxMenuBar());

	container = new wxBoxSizer(wxVERTICAL);

	
	container->Add(new SplashPanel(this, this->container, image), 1, wxEXPAND);

	this->SetSizer(container);
}

void MainFrame::add(wxMenuBar* menuBar) {
	wxMenu* fileMenu = new wxMenu;
	//Temporary items
	//Tanker TextFile
	//Receiver TextFile 
	//Temporary items

	fileMenu->Append(wxID_EXIT);

	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT);
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");
	SetMenuBar(menuBar);
	Bind(wxEVT_MENU, &MainFrame::onAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::onExit, this, wxID_EXIT);
}

void MainFrame::onExit(wxCommandEvent& event) {

}

void MainFrame::onAbout(wxCommandEvent& event) {

}