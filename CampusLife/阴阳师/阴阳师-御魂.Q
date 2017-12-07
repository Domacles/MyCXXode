[General]
SyntaxVersion=2
BeginHotkey=121
BeginHotkeyMod=0
PauseHotkey=0
PauseHotkeyMod=0
StopHotkey=123
StopHotkeyMod=0
RunOnce=1
EnableWindow=
MacroID=513b8221-2b6d-4165-b4d8-9b3b68669666
Description=ÒõÑôÊ¦-Óù»ê
Enable=1
AutoRun=0
[Repeat]
Type=0
Number=1
[SetupUI]
Type=2
QUI=
[Relative]
SetupOCXFile=
[Comment]

[Script]
Function gainEquipment(level, loops)
    Dim Hwnd, sText, sRect
    Dim time, winLen, winHigh
    time = 0
    winLen = -1
    winHigh = -1 
    Hwnd = Plugin.Window.Foreground()
    While True
        If loops > 0 And time >= loops Then 
            Exit Function
        End If
        sText = Plugin.Window.GetTextEx(Hwnd, 0)
        If StrComp(sText, "Bluestacks App Player") = 0 Then 
            If time = 0 Then
                MessageBox "Start Function gainEquipment " & sText
                time = time + 1
                Call Plugin.Window.Size(Hwnd, 800, 600)
            Else 
                time = time + 1
            End If
            sRect = Plugin.Window.GetClientRect(Hwnd)
            Dim sWinSize
            sWinSize = Split(sRect, "|")
            Dim x1, y1, x2, y2
            x1 = Clng(sWinSize(0))
            y1 = Clng(sWinSize(1))
            x2 = Clng(sWinSize(2))
            y2 = Clng(sWinSize(3))
            If winLen < 0 And winHigh < 0 Then 
                winLen = x2 - x1
                winHigh = y2 - y1
            ElseIf x2 - x1 <> winLen Or y2 - y1 <> winHigh Then
                Call Plugin.Window.Size(Hwnd, 800, 600)
            End If
            Dim mySecond, XY, iZB, X, Y, rx, ry
            Randomize
            mySecond = Int(1500 + (300 * Rnd))
            Randomize
            rx = Int(5 * Rnd)
            Randomize
            ry = Int(5 * Rnd)
            XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, "D:\VSProgram\mySrc\bmp\yuhun.bmp", 0, 0.9)
            iZB = InStr(XY, "|")
            X = CLng(Left(XY, iZB - 1))
            Y = CLng(Right(XY, Len(XY) - iZB))
            If X >= 0 And Y >= 0 Then
                MoveTo X, Y
                LeftClick 1
                Delay mySecond
                Goto nextStep
            End If
            'XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, "D:\VSProgram\mySrc\bmp\yuhunExit.bmp", 0, 0.9)
            'iZB = InStr(XY, "|")
            'X = CLng(Left(XY, iZB - 1))
            'Y = CLng(Right(XY, Len(XY) - iZB))
            'If X >= 0 And Y >= 0 Then
            '	MoveTo X, Y
            '	Delay mySecond
            '	Goto nextStep
            'End If
            Dim levelName
            levelName = Join(Array("D:\VSProgram\mySrc\bmp\yuhun", CStr(level), ".bmp"), "")
            XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, levelName, 0, 0.9)
            iZB = InStr(XY, "|")
            X = CLng(Left(XY, iZB - 1))
            Y = CLng(Right(XY, Len(XY) - iZB))
            If X >= 0 And Y >= 0 Then
                MoveTo X + rx, Y + ry
                LeftClick 1
                Delay mySecond
                XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, "D:\VSProgram\mySrc\bmp\Start.bmp", 0, 0.9)
                iZB = InStr(XY, "|")
                X = CLng(Left(XY, iZB - 1))
                Y = CLng(Right(XY, Len(XY) - iZB))
                If X >= 0 And Y >= 0 Then
                    MoveTo X + rx, Y + ry
                    LeftClick 1
                    Delay mySecond
                    Goto nextStep
                End If
                Goto nextStep
            End If
            XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, "D:\VSProgram\mySrc\bmp\yuhunOK.bmp", 0, 0.9)
            iZB = InStr(XY, "|")
            X = CLng(Left(XY, iZB - 1))
            Y = CLng(Right(XY, Len(XY) - iZB))
            If X >= 0 And Y >= 0 Then
                MoveTo X + 50 + rx, Y - 50 + ry
                LeftClick 1
                Delay mySecond
                Goto nextStep
            End If
            XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, "D:\VSProgram\mySrc\bmp\Win.bmp", 0, 0.9)
            iZB = InStr(XY, "|")
            X = CLng(Left(XY, iZB - 1))
            Y = CLng(Right(XY, Len(XY) - iZB))
            If X >= 0 And Y >= 0 Then
                MoveTo X + rx, Y + ry
                LeftClick 1
                Delay 1000
                LeftClick 1
                Delay 1000 + mySecond
                Goto nextStep
            End If
            XY = Plugin.Pic.FindMultiPic(x1, y1, x2, y2, "D:\VSProgram\mySrc\bmp\WinOK.bmp", 0, 0.9)
            iZB = InStr(XY, "|")
            X = CLng(Left(XY, iZB - 1))
            Y = CLng(Right(XY, Len(XY) - iZB))
            If X >= 0 And Y >= 0 Then
                MoveTo X + rx, Y + ry
                LeftClick 1
                Delay mySecond
                Goto nextStep
            End If
            Rem nextStep 
        End If
    Wend
End Function
Call gainEquipment(5, -1)
