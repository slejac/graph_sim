/**
 * @file GraphSimApp.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "GraphSimApp.h"
#include "Mainframe.h"

/**
 * Initialize the application
 *
 * @return
 */
bool GraphSimApp::OnInit()
{
    if (!wxApp::OnInit())
    {
        return false;
    }

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new Mainframe();
    frame->Initialize();
    frame->Show(true);

    return true;
}