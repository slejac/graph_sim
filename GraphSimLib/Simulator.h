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

    /// Radius of the vertices
    double mRadii = 35;

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
};

#endif //GRAPHSIM_SIMULATOR_H
