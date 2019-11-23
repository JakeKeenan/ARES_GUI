#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class LogoPanel :
	public wxPanel
{
public:
	LogoPanel(wxFrame* parent, wxString file, wxBitmapType format);

	void paintEvent(wxPaintEvent & evt);
	void paintNow();
	void OnSize(wxSizeEvent& evt);
	void render(wxDC& dc);

	DECLARE_EVENT_TABLE()
private:
	wxBitmap resized;
	wxImage image;
	int width, height;
};

