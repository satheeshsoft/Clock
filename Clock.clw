; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClockView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Clock.h"
LastPage=0

ClassCount=5
Class1=CClockApp
Class2=CClockDoc
Class3=CClockView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg

[CLS:CClockApp]
Type=0
HeaderFile=Clock.h
ImplementationFile=Clock.cpp
Filter=N

[CLS:CClockDoc]
Type=0
HeaderFile=ClockDoc.h
ImplementationFile=ClockDoc.cpp
Filter=N

[CLS:CClockView]
Type=0
HeaderFile=ClockView.h
ImplementationFile=ClockView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_TYPE_DIGITAL

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=Clock.cpp
ImplementationFile=Clock.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_TYPE_ANALOG
Command3=ID_TYPE_DIGITAL
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

