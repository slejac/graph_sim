/**
 * @file SimulatorView.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "SimulatorView.h"
#include "ids.h"

/**
 * Initializes SimulatorView class.
 *
 * @param parent The parent window.
 */
void SimulatorView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    mSimulation.Load("data/graph1.xml");
}