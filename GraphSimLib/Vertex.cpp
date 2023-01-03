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
    dc->DrawText(mID, mX - (25/2 - 3), mY - (25/2 + 5));
}
