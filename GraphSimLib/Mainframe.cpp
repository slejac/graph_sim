/**
 * @file Mainframe.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Mainframe.h"
#include "SimulatorView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 *
 * @return
 */
void Mainframe::Initialize()
{
    Create(nullptr, wxID_ANY, L"Graphing SimulatorView",wxDefaultPosition,  wxSize(1000, 1000 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    auto view = new SimulatorView();
    view->Initialize(this);

    sizer->Add(view, 1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto graphBar = new wxMenuBar( );

    // Add menu selection item
    auto graph = new wxMenu();
    auto alg = new wxMenu();

    // Append menu bar item
    graphBar->Append(graph, L"&Graph");
    graphBar->Append(alg, L"&Algorithm");

    graph->Append(IDM_SIM1, L"&Graph 1",
            "Generate Graph One");
    graph->Append(IDM_SIM2, L"&Graph 2",
            "Generate Graph Two");
    graph->Append(IDM_SIM3, L"&Graph 3",
            "Generate Graph Three");
    graph->Append(IDM_SIM4, L"&Graph 4",
            "Generate Graph Four");
    graph->Append(IDM_SIM5, L"&Graph 5",
            "Generate Graph Five");

    alg->Append(IDM_BFS, L"&BFS", "Breadth-First Search");

    SetMenuBar( graphBar );
}