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

class Simulator {
private:
    /// All of the vertices to include in the simulator
    //std::vector<std::shared_ptr<Item>> mVertices;

    /// All of the edges to include in the simulator
    //std::vector<std::shared_ptr<Item>> mVertices;

    void XmlVertex(wxXmlNode *node);
    void XmlEdge(wxXmlNode *node);
public:
    Simulator();

    void Clear();
    void Load(const wxString &filename);
};

#endif //GRAPHSIM_SIMULATOR_H
