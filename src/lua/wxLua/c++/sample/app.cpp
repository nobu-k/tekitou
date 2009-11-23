// compile: g++ -O2 -I/usr/local/include/wxbind/setup `wx-config --libs` `wx-config --cflags` app.cpp -lwxlua_gtk2u_wxbindcore-2.8
#include <boost/shared_ptr.hpp>
#include <wx/wx.h>
#include <wxlua/include/wxlstate.h>
#include <wxbind/include/wxbinddefs.h>
#include <wxbind/include/wxcore_bind.h>
WXLUA_DECLARE_BIND_WXCORE

class Frame : public wxFrame {
  DECLARE_EVENT_TABLE()
public:
  Frame() : wxFrame(NULL, -1, wxT("test"), wxDefaultPosition, wxDefaultSize) {}
  void OnHogePushed(wxCommandEvent& event);
};

BEGIN_EVENT_TABLE(Frame, wxFrame)
  EVT_BUTTON(10, Frame::OnHogePushed)
END_EVENT_TABLE()

void Frame::OnHogePushed(wxCommandEvent& event) {
  wxMessageBox(wxT("hoge!!"));
}

class App : public wxApp {
public:
  virtual bool OnInit();

private:
  boost::shared_ptr<wxLuaState> state;
};

IMPLEMENT_APP(App);

bool App::OnInit() {
  WXLUA_IMPLEMENT_BIND_WXCORE

  Frame* frame = new Frame();

  state.reset(new wxLuaState(true));
  if (state->LuaDoFile(wxT("test.lua")) != 0) return false;
  state->lua_GetGlobal("init");
  state->wxluaT_PushUserDataType(frame, wxluatype_wxFrame, true);
  if (state->LuaPCall(1, 0) != 0) return false;

  frame->Show(true);
  SetTopWindow(frame);
  return true;
}
