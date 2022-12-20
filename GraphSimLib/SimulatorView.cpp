/**
 * @file SimulatorView.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "SimulatorView.h"

/**
 * Initializes SimulatorView class.
 *
 * @param parent The parent window.
 */
void SimulatorView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Refresh();
}