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

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SimulatorView::OnBFS, this, IDM_BFS);

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
    mGraph = GraphOne;
    mSimulation.Load(mGraph);
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
    mGraph = GraphTwo;
    mSimulation.Load(mGraph);
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
    mGraph = GraphThree;
    mSimulation.Load(mGraph);
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
    mGraph = GraphFour;
    mSimulation.Load(mGraph);
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
    mGraph = GraphFive;
    mSimulation.Load(mGraph);
    Refresh();
}

/**
 * BFS Simulation
 *
 * @param event
 */
void SimulatorView::OnBFS(wxCommandEvent& event)
{
    if (!mGraph.empty())
    {
        std::vector<double> res;
        res = mSimulation.BFS();
    }
    Refresh();
}
