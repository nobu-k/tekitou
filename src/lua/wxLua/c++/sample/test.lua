require "wx"

function init(window)
  sizer = wx.wxBoxSizer(wx.wxVERTICAL)
  
  pushMe = wx.wxButton(window, -1, "Push me!!")
  pushMe:Connect(wx.wxEVT_COMMAND_BUTTON_CLICKED,
                 function (event) wx.wxMessageBox("ktkr") end)
  sizer:Add(pushMe)
  sizer:Add(wx.wxButton(window, 10, "Hoge"))
  window:SetSizer(sizer)
end