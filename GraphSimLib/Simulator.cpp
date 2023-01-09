/**
 * @file Simulator.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Simulator.h"

// Via https://www.geeksforgeeks.org/sleep-function-in-cpp/
#include <chrono>
#include <thread>

#include "Vertex.h"
#include "Edge.h"

/**
 * Draw the graph
 *
 * @param dc The context we are drawing on.
 */
void Simulator::OnDraw(wxDC* dc)
{
    // Start with edges to avoid overlap
    for (auto e: mEdges)
    {
        e->Draw(dc);
    }

    for (auto v : mVertices)
    {
        v->Draw(dc, mRadii);
    }

    // Draw Highlighted Edges and Vertices Over
    for (auto e2 : mHighlightedEdges)
    {
        e2->Highlight(dc);
    }

    for (auto v2 : mHighlightedVertices)
    {
        v2->Highlight(dc, mRadii);
    }

    for (auto v3 : mCompletedVertices)
    {
        v3->Completed(dc, mRadii);
    }

    // Draw Text
    wxFont font(75,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetTextForeground(wxColour(64, 64, 64));
    dc->SetFont(font);

    // Arbitrary Offset Values, equation likely can be devised to
    // improve manner of offsetting
    dc->DrawText(mMessage, 300, 750);

    mHighlightedEdges.clear();
    mHighlightedVertices.clear();

    // Thread delayed for 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

/**
 * Reset the simulation
 */
void Simulator::Clear()
{
    mVertices.clear();
    mEdges.clear();
    mAdjacencyList.clear();
    mMessage.clear();
    mCompletedVertices.clear();
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

    std::vector<double> temp;
    mAdjacencyList.push_back(temp);
}

/**
 * Creating an edge using an XML Node
 *
 * @param node
 */
void Simulator::XmlEdge(wxXmlNode* node)
{
    double start;
    node->GetAttribute(L"start").ToDouble(&start);
    double end;
    node->GetAttribute(L"end").ToDouble(&end);
    double startX, startY, endX, endY;

    // Indexing system depends on vertex ordering
    startX = mVertices[start - 1]->GetX();
    startY = mVertices[start - 1]->GetY();

    endX = mVertices[end - 1]->GetX();
    endY = mVertices[end - 1]->GetY();

    std::shared_ptr<Edge> e = std::make_shared<Edge>();
    e->SetStartVertex(startX, startY);
    e->SetEndVertex(endX, endY);
    mEdges.push_back(e);

    // Populate Adjacency List
    mAdjacencyList[start - 1].push_back(end);
    mAdjacencyList[end - 1].push_back(start);
}

/**
 * Breadth-First Search
 *
 * @return BFS Results
 */
std::vector<double> Simulator::BFS()
{
    std::vector<double> res;
    std::vector<int> visited(mVertices.size(), 0);
    std::vector<double> queue;

    queue.push_back(1);
    while (!queue.empty())
    {
        double cur = queue.back();
        queue.pop_back();
        if (visited[cur - 1] == 0)
        {
            visited[cur - 1] = 1;
            res.push_back(cur);
            for (double neighbor : mAdjacencyList[cur - 1])
            {
                if (visited[neighbor - 1] == 0)
                {
                    // Prepend
                    queue.insert(queue.begin(), neighbor);
                }
            }
        }
    }

    // Add to Message Text
    for (auto val : res)
    {
        mMessage.append(std::to_string(int(val)));
        mMessage.append(" ");
    }

    return res;
}

/**
 * Highlights an Edge
 *
 * @param start
 *
 * @param end
 */
void Simulator::HighlightEdge(double start, double end)
{
    for (auto edge : mEdges)
    {
        if ((edge->GetStartX() == mVertices[start - 1]->GetX() &&
                edge->GetStartY() == mVertices[start - 1]->GetY() &&
                edge->GetEndX() == mVertices[end - 1]->GetX() &&
                edge->GetEndY() == mVertices[end - 1]->GetY()) ||
                (edge->GetStartX() == mVertices[end - 1]->GetX() &&
                    edge->GetStartY() == mVertices[end - 1]->GetY() &&
                    edge->GetEndX() == mVertices[start - 1]->GetX() &&
                    edge->GetEndY() == mVertices[start - 1]->GetY()))
        {
            mHighlightedEdges.push_back(edge);
            break;
        }
    }
}
