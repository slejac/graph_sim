/**
 * @file Edge.h

 * @author Jack Sleeman
 *
 * Class representing edge in simulator.
 */

#ifndef GRAPHSIM_EDGE_H
#define GRAPHSIM_EDGE_H

class Edge {
private:
    /// Starting edge x coordinate
    double mStartX = 0;

    /// Starting edge y coordinate
    double mStartY = 0;

    /// Ending edge x coordinate
    double mEndX = 0;

    /// Ending edge y coordinate
    double mEndY = 0;

public:
    /// Default constructor
    Edge() {};
    
    /// Copy constructor (disabled)
    Edge(const Edge &) = delete;
    
    /// Assignment operator
    void operator=(const Edge &) = delete;

    void Draw(wxDC* dc);

    /**
     * Set Starting Vertex
     *
     * @param x
     *
     * @param y
     */
    void SetStartVertex(double x, double y) { mStartX = x, mStartY = y; }

    /**
     * Set Ending Vertex
     *
     * @param x
     *
     * @param y
     */
    void SetEndVertex(double x, double y) { mEndX = x, mEndY = y; }
};

#endif //GRAPHSIM_EDGE_H