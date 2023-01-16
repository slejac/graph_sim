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

/// Graph One Path
const wxString GraphOne = "data/graph1.xml";

/// Graph Two Path
const wxString GraphTwo = "data/graph2.xml";

/// Graph Three Path
const wxString GraphThree = "data/graph3.xml";

/// Graph Four Path
const wxString GraphFour = "data/graph4.xml";

/// Graph Five Path
const wxString GraphFive = "data/graph5.xml";


class SimulatorView : public wxWindow {
private:
    /// The simulation object used
    Simulator mSimulation;

    /// Current Graph
    wxString mGraph;

    void OnPaint(wxPaintEvent& event);

    void OnGraphOne(wxCommandEvent& event);
    void OnGraphTwo(wxCommandEvent& event);
    void OnGraphThree(wxCommandEvent& event);
    void OnGraphFour(wxCommandEvent& event);
    void OnGraphFive(wxCommandEvent& event);

    void OnBFS(wxCommandEvent& event);
    void OnDFS(wxCommandEvent& event);
    void OnDetectCycle(wxCommandEvent& event);
public:
    void Initialize(wxFrame* parent);
};

#endif //GRAPHSIM_SIMULATORVIEW_H