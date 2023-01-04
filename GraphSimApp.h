/**
 * @file GraphSimApp.h
 *
 * @author Jack Sleeman
 *
 * The main application class of our program.
 *
 * Initializes program, allowing creation of the simulator
 */

#ifndef GRAPHSIM_GRAPHSIMAPP_H
#define GRAPHSIM_GRAPHSIMAPP_H

/**
 * Main application class
 */
class GraphSimApp : public wxApp {
public:
    bool OnInit() override;
};

#endif //GRAPHSIM_GRAPHSIMAPP_H