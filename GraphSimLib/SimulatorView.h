/**
 * @file SimulatorView.h
 *
 * @author Jack Sleeman
 *
 * A view within the window of the SimulatorView.
 */

#ifndef GRAPHSIM_SIMULATORVIEW_H
#define GRAPHSIM_SIMULATORVIEW_H

#include <wx/wx.h>
#include "Simulator.h"

class SimulatorView : public wxWindow {
private:
    /// The simulation object used
    Simulator mSimulation;

    void OnPaint(wxPaintEvent& event);

public:
    void Initialize(wxFrame* parent);
};

#endif //GRAPHSIM_SIMULATORVIEW_H