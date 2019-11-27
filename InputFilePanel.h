#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Data.h"
class InputFilePanel :
	public wxPanel
{
public:
	InputFilePanel(wxWindow *parent);
	~InputFilePanel();

	std::string getTankerFile();
	std::string getReceiverFile();
private:
	enum {
		SEARCH_TANKER_ID,
		SEARCH_RECEIVER_ID
	};

	wxTextCtrl* tankerFile = nullptr;
	wxButton* searchTankerFile = nullptr;
	wxTextCtrl* receiverFile = nullptr;
	wxButton* searchReceiverFile = nullptr;
	
	wxFileDialog* selectFileDialog = nullptr;

	void onSearchTanker(wxCommandEvent& event);
	void onSearchReceiver(wxCommandEvent& event);
};

