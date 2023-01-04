/**
 * @file Mainframe.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Mainframe.h"
#include "SimulatorView.h"

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

    auto menuBar = new wxMenuBar( );

    // Add menu selection item
    auto menu = new wxMenu();

    // Append menu bar item
    menuBar->Append(menu, L"&Menu");

    // Commented out method required to regenerate graph
    // menu->Append(IDM_GENERATE, L"&Generate Graph",
            "Generate a Graph One!";

    SetMenuBar( menuBar );
}