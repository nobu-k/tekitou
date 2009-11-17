#!/usr/bin/lua

require "wx"

frame = wx.wxFrame(wx.NULL, wx.wxID_ANY, "wxLua Minimal Demo",
		   wx.wxDefaultPosition, wx.wxSize(450, 450),
		   wx.wxDEFAULT_FRAME_STYLE)

local fileMenu = wx.wxMenu()
fileMenu:Append(wx.wxID_EXIT, "E&xit", "Quit the program")

local helpMenu = wx.wxMenu()
helpMenu:Append(wx.wxID_ABOUT, "&About",
		"About the wxLua Minimal Application")

local menuBar = wx.wxMenuBar()
menuBar:Append(fileMenu, "&File")
menuBar:Append(helpMenu, "&Help")

frame:SetMenuBar(menuBar)

frame:CreateStatusBar(1)
frame:SetStatusText("Welcome to wxLua.")

frame:Connect(wx.wxID_EXIT, wx.wxEVT_COMMAND_MENU_SELECTED,
	      function (event) frame:Close(true) end)
frame:Connect(wx.wxID_ABOUT, wx.wxEVT_COMMAND_MENU_SELECTED,
	      function (event)
		wx.wxMessageBox('This is The "About" dialog of the Minimal wxLua sample.',
				"About wxLua",
				wx.wxOK + wx.wxICON_INFORMATION,
				frame)
	      end)

frame:Show(true)

wx.wxGetApp():MainLoop()
