// mainfrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "paintobj.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DRAWTOOLS, OnUpdateViewToolbar)
	//}}AFX_MSG_MAP
	ON_COMMAND_EX(ID_VIEW_TOOLBAR, OnViewToolbar)
	ON_COMMAND_EX(ID_VIEW_DRAWTOOLS, OnViewToolbar)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars
	
static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	0,                      // mouse position indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndShapeBar.Create(this,
		WS_CHILD | WS_VISIBLE | CBRS_TOP, ID_VIEW_DRAWTOOLS) ||
		!m_wndShapeBar.LoadToolBar(IDR_DRAWTOOLS))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

//	UINT  nOldID;
//	int nOldImage;
//	UINT nOldStyle;
//	m_wndToolBar.GetButtonInfo(1, nOldID, nOldStyle, nOldImage);
//	m_wndToolBar.SetButtonInfo(1, nOldID, TBBS_CHECKBOX, nOldImage);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	UINT		uID;
	UINT		uStyle;
	int 		nWidth;
	CDC			*pDC;
	CRect		rectArea;

	m_wndStatusBar.GetPaneInfo(1, uID, uStyle, nWidth);
	pDC = m_wndStatusBar.GetDC();
	pDC->SelectObject(m_wndStatusBar.GetFont());
	pDC->DrawText(_T("X=9999, Y=9999"), -1, rectArea, DT_SINGLELINE | DT_CALCRECT);
	m_wndStatusBar.ReleaseDC(pDC);
	m_wndStatusBar.SetPaneInfo(1, uID, uStyle, rectArea.Width());

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_wndShapeBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	FloatControlBar(&m_wndShapeBar, CPoint(0,0));

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndShapeBar.SetBarStyle(m_wndShapeBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

void CMainFrame::ClearPositionText()
{
	m_wndStatusBar.SetPaneText(1, NULL);
}

void CMainFrame::SetPositionText(CPoint& point)
{
	CString strPosition;
	strPosition.Format(_T("X=%d, Y=%d"), point.x, point.y);
	m_wndStatusBar.SetPaneText(1, strPosition);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::OnViewToolbar(UINT nID)
{
	CControlBar* pBar = GetControlBar(nID);
	if (pBar != NULL)
	{
		ShowControlBar(pBar, (pBar->GetStyle() & WS_VISIBLE) == 0, FALSE);
		return TRUE;
	}
	return FALSE;
}

void CMainFrame::OnUpdateViewToolbar(CCmdUI* pCmdUI) 
{
	CControlBar* pBar = GetControlBar(pCmdUI->m_nID);
	if (pBar != NULL)
	{
		pCmdUI->SetCheck((pBar->GetStyle() & WS_VISIBLE) != 0);
        return;
	}
	pCmdUI->ContinueRouting();
}

