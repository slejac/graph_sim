/**
 * @file SimulatorView.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "SimulatorView.h"

// Via https://www.geeksforgeeks.org/sleep-function-in-cpp/
#include <chrono>
#include <thread>

#include <wx/dcbuffer.h>

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
        auto res = mSimulation.BFS();
        auto adjacency = mSimulation.GetAdjacencyList();
        std::vector<double> visited(adjacency.size(), 0);
        std::vector<std::tuple<double, double>> edges;
        for (auto vertex : res)
        {
            visited[vertex - 1] = 1;

            // Print node and neighbors
            mSimulation.HighlightVertex(vertex);
            for (auto neighbor : adjacency[vertex - 1])
            {
                if (visited[neighbor - 1] == 0)
                {
                    edges.emplace_back(vertex, neighbor);
                }
            }
            for (auto link : edges)
            {
                mSimulation.HighlightEdge(std::get<0>(link), std::get<1>(link));
            }
            Refresh();
            Update();

            // Drawing out neighbors in order
            for (int i = 0; i < edges.size(); i++)
            {
                mSimulation.HighlightVertex(std::get<1>(edges[i]));
                for (int j = i; j < edges.size(); j++)
                {
                    mSimulation.HighlightEdge(std::get<0>(edges[j]), std::get<1>(edges[j]));
                }
                Refresh();
                Update();
            }
            mSimulation.CompletedVertex(vertex);
            edges.clear();
        }
    }
    Refresh();
    Update();

    // Thread delayed for 5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    mSimulation.Clear();
    mSimulation.Load(mGraph);
}
