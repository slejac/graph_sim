/**
 * @file pch.h
 *
 * @author Jack Sleeman
 *
 * Allows us to pre-compile headers.
 *
 * Pre-compiling headers here saves time in the future.
 */

#ifndef GRAPHSIM_PCH_H
#define GRAPHSIM_PCH_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/xml/xml.h>
#include <wx/graphics.h>

#endif //GRAPHSIM_PCH_H