/**
 * @file Simulator.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Simulator.h"

/**
 * Constructor for the simulator
 */
Simulator::Simulator()
{

}

/**
 * Reset the simulation
 */
void Simulator::Clear()
{

}

/**
 * Load a graph to demonstrate upon
 *
 * @param filename The path of the file we are using
 */
void Simulator::Load(const wxString& filename)
{
    wxXmlDocument xmlDoc;
    if (!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load level file");
        return;
    }

    Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto subroot = root->GetChildren();
    auto child = subroot->GetChildren();
    for( ; child; child=child->GetNext())
    {
        XmlVertex(child);
    }
    subroot = subroot->GetNext();
    child = subroot->GetChildren();
    for( ; child; child=child->GetNext())
    {
        //XmlEdge(child);
    }
}

void Simulator::XmlVertex(wxXmlNode* node)
{

}

void Simulator::XmlEdge(wxXmlNode* node)
{

}
