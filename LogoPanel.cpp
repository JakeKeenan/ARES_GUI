#include "LogoPanel.h"
LogoPanel::LogoPanel(wxWindow* parent, wxString file, wxBitmapType format) :
	wxPanel(parent) {
	if (image.LoadFile(file, format)) {
		width = -1;
		height = -1;
	}
}

void LogoPanel::paintEvent(wxPaintEvent& evt) {
	wxPaintDC dc(this);
	render(dc);
}

void LogoPanel::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void LogoPanel::render(wxDC& dc) {
	int newWidth, newHeight;
	dc.GetSize(&newWidth, &newHeight);

	if (newWidth != width || newHeight != height){
		resized = wxBitmap(image.Scale(newWidth, newHeight));
		width = newWidth;
		height = newHeight;
		dc.DrawBitmap(resized, 0, 0, false);
	}
	else {
		dc.DrawBitmap(resized, 0, 0, false);
	}
}

void LogoPanel::OnSize(wxSizeEvent& event) {
	Refresh();
	event.Skip();
}

BEGIN_EVENT_TABLE(LogoPanel, wxPanel)

EVT_PAINT(LogoPanel::paintEvent)

EVT_SIZE(LogoPanel::OnSize)

END_EVENT_TABLE();