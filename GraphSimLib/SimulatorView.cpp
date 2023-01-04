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

    Bind(wxEVT_PAINT, &SimulatorView::OnPaint, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SimulatorView::OnGraphOne, this, IDM_SIM1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SimulatorView::OnGraphTwo, this, IDM_SIM2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SimulatorView::OnGraphThree, this, IDM_SIM3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SimulatorView::OnGraphFour, this, IDM_SIM4);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SimulatorView::OnGraphFive, this, IDM_SIM5);

    Refresh();
}

/**
 * Draw the graph simulator.
 *
 * @param event
 */
void SimulatorView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    mSimulation.OnDraw(&dc);
}

/**
 * Draw Graph 1
 *
 * @param event
 */
void SimulatorView::OnGraphOne(wxCommandEvent& event)
{
    mSimulation.Clear();
    mSimulation.Load("data/graph1.xml");
    Refresh();
}

/**
 * Draw Graph 2
 *
 * @param event
 */
void SimulatorView::OnGraphTwo(wxCommandEvent& event)
{
    mSimulation.Clear();
    mSimulation.Load("data/graph2.xml");
    Refresh();
}

/**
 * Draw Graph 3
 *
 * @param event
 */
void SimulatorView::OnGraphThree(wxCommandEvent& event)
{
    mSimulation.Clear();
    mSimulation.Load("data/graph3.xml");
    Refresh();
}

/**
 * Draw Graph 4
 *
 * @param event
 */
void SimulatorView::OnGraphFour(wxCommandEvent& event)
{
    mSimulation.Clear();
    mSimulation.Load("data/graph4.xml");
    Refresh();
}

/**
 * Draw Graph 5
 *
 * @param event
 */
void SimulatorView::OnGraphFive(wxCommandEvent& event)
{
    mSimulation.Clear();
    mSimulation.Load("data/graph5.xml");
    Refresh();
}