/**
 * @file Simulator.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Simulator.h"
#include "Vertex.h"
#include "Edge.h"

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
    root->GetAttribute(L"radii").ToDouble(&mRadii);

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
        XmlEdge(child);
    }
}

/**
 * Creating a vertex using an XML Node
 *
 * @param node
 */
void Simulator::XmlVertex(wxXmlNode* node)
{
    auto id = node->GetAttribute(L"id");
    double x;
    node->GetAttribute(L"x").ToDouble(&x);
    double y;
    node->GetAttribute(L"y").ToDouble(&y);
    std::shared_ptr<Vertex> vert = std::make_shared<Vertex>(id);
    vert->SetLocation(x, y);
    mVertices.push_back(vert);
}

/**
 * Creating an edge using an XML Node
 *
 * @param node
 */
void Simulator::XmlEdge(wxXmlNode* node)
{

}

/**
 * Draw the graph
 *
 * @param dc The context we are drawing on.
 */
void Simulator::OnDraw(wxDC* dc)
{
    for (auto v : mVertices)
    {
        v->Draw(dc, mRadii);
    }
}
