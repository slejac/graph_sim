/**
 * @file Simulator.h
 *
 * @author Jack Sleeman
 *
 * The simulator itself.
 */

#ifndef GRAPHSIM_SIMULATOR_H
#define GRAPHSIM_SIMULATOR_H

#include <wx/xml/xml.h>
#include "Vertex.h"
#include "Edge.h"

class Simulator {
private:
    /// All of the vertices to include in the simulator
    std::vector<std::shared_ptr<Vertex>> mVertices;

    /// All of the edges to include in the simulator
    std::vector<std::shared_ptr<Edge>> mEdges;

    /// Highlighted Vertices
    std::vector<std::shared_ptr<Vertex>> mHighlightedVertices;

    /// Highlighted Edges
    std::vector<std::shared_ptr<Edge>> mHighlightedEdges;

    /// Nodes we are "done" with
    std::vector<std::shared_ptr<Vertex>> mCompletedVertices;

    /// Adjacency list representing graph
    std::vector<std::vector<double>> mAdjacencyList;

    /// Radius of the vertices
    double mRadii = 35;

    /// Text to be drawn on screen
    wxString mMessage;

    void XmlVertex(wxXmlNode *node);
    void XmlEdge(wxXmlNode *node);

public:
    /**
     * Constructor
     */
    Simulator() {}

    void OnDraw(wxDC *dc);
    void Clear();
    void Load(const wxString &filename);
    std::vector<double> BFS();
    void HighlightEdge(double start, double end);

    /**
     * Add a Vertex to be Highlighted
     *
     * @param index
     */
    void HighlightVertex(double index) { mHighlightedVertices.push_back(mVertices[index - 1]); }

    /**
     * Complete use of a Vertex
     *
     * @param index
     */
     void CompletedVertex(double index) { mCompletedVertices.push_back(mVertices[index - 1]); }

    /**
     * Getter for adjacency list
     *
     * @return Adjacency List of this graph
     */
    std::vector<std::vector<double>> GetAdjacencyList() { return mAdjacencyList; }
};

#endif //GRAPHSIM_SIMULATOR_H
