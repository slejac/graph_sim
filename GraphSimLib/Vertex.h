/**
 * @file Vertex.h
 * 
 * @author Jack Sleeman
 *
 * Class representing a vertex in our graph.
 */

#ifndef GRAPHSIM_VERTEX_H
#define GRAPHSIM_VERTEX_H

class Vertex {
private:
    /// ID of Vertex
    wxString mID;

    /// X Coordinate of Location
    double mX = 0;

    /// Y Coordinate of Location
    double mY = 0;

public:
    /// Default constructor (disabled)
    Vertex() = delete;
    
    /// Copy constructor (disabled)
    Vertex(const Vertex &) = delete;
    
    /// Assignment operator
    void operator=(const Vertex &) = delete;

    /**
     * Constructor
     *
     * @param id
     */
    Vertex(const wxString &id) { mID = id; }

    void Draw(wxDC* dc, double radius);

    /**
     * Setter for the vertex location
     *
     * @param x

     * @param y
     */
    void SetLocation(double x, double y) { mX = x, mY = y; }

    /**
     * Getter for vertex x coordinate
     *
     * @return
     */
    double GetX() const { return mX; }

    /**
     * Getter for vertex y coordinate
     *
     * @return
     */
     double GetY() const { return mY; }
};

#endif //GRAPHSIM_VERTEX_H
