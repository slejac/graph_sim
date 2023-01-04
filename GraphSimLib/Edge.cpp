/**
 * @file Edge.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Edge.h"

/**
 * Draw the edge
 *
 * @param dc The context we are drawing on
 */
void Edge::Draw(wxDC* dc)
{
    dc->SetPen(wxPen(*wxBLACK, 5, wxSOLID));
    dc->DrawLine(mStartX, mStartY, mEndX, mEndY);
}