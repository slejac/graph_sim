/**
 * @file Vertex.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Vertex.h"

/**
 * Draw the vertex
 *
 * @param dc Context we are drawing on
 */
void Vertex::Draw(wxDC* dc, double radius)
{
    dc->SetBrush(*wxBLACK_BRUSH);
    dc->DrawCircle(mX, mY, radius);

    wxFont font(25,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->SetFont(font);

    // Arbitrary Offset Values, equation likely can be devised to
    // improve manner of offsetting
    dc->DrawText(mID, mX - (25/2 - 3), mY - (25/2 + 5));
}

/**
 * Draw Highlighted Vertex
 *
 * @param dc Context Drawn Upon
 *
 * @param radius Radius of Vertex
 */
void Vertex::Highlight(wxDC* dc, double radius)
{
    dc->SetBrush(*wxYELLOW_BRUSH);
    dc->DrawCircle(mX, mY, radius);

    wxFont font(25,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->SetFont(font);

    // Arbitrary Offset Values, equation likely can be devised to
    // improve manner of offsetting
    dc->DrawText(mID, mX - (25/2 - 3), mY - (25/2 + 5));
}

/**
 * Mark a Vertex as Completed
 *
 * @param dc Context Drawn Upon
 *
 * @param radius Radius of a Vertex
 */
void Vertex::Completed(wxDC* dc, double radius)
{
    // This line prevents yellow borders being drawn around overlapping elements
    dc->SetPen(wxPen(*wxBLACK, 5, wxSOLID));

    dc->SetBrush(*wxRED_BRUSH);
    dc->DrawCircle(mX, mY, radius);

    wxFont font(25,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->SetFont(font);

    // Arbitrary Offset Values, equation likely can be devised to
    // improve manner of offsetting
    dc->DrawText(mID, mX - (25/2 - 3), mY - (25/2 + 5));
}
