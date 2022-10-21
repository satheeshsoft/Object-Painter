// paintvw.cpp : implementation of the CPaintobjView class
//

#include "stdafx.h"
#include "paintobj.h"
#include "mainfrm.h"

#include "paintdoc.h"
#include "paintvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintobjView

IMPLEMENT_DYNCREATE(CPaintobjView, CScrollView)

BEGIN_MESSAGE_MAP(CPaintobjView, CScrollView)
	//{{AFX_MSG_MAP(CPaintobjView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_VIEW_SCROLL, OnViewScroll)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SCROLL, OnUpdateViewScroll)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOMFIT, OnUpdateViewZoomfit)
	ON_COMMAND(ID_VIEW_ZOOMFIT, OnViewZoomfit)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintobjView construction/destruction

CPaintobjView::CPaintobjView()
{
	CWinApp* pApp = AfxGetApp();

	m_bZoomMode = FALSE;
	m_bTracking = FALSE;
	m_hcurArrow = pApp->LoadStandardCursor(IDC_ARROW);
	m_hcurCross = pApp->LoadStandardCursor(IDC_CROSS);
	m_pActive = NULL;

	ASSERT(m_hcurArrow != NULL);
	ASSERT(m_hcurCross != NULL);

	// Win95 has IDC_SIZEALL, WinNT 3.51 has IDC_SIZE
	m_hcurSize = pApp->LoadStandardCursor(IDC_SIZEALL);
	if (m_hcurSize == NULL)
		pApp->LoadStandardCursor(IDC_SIZE);
	ASSERT(m_hcurSize != NULL);
}

CPaintobjView::~CPaintobjView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CPaintobjView drawing

void CPaintobjView::OnDraw(CDC* pDC)
{
	CPaintobjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	POSITION pos;
	pos = pDoc->m_Objects.GetHeadPosition();

	while (pos != NULL)
	{
		CPainted* pPainter = (CPainted*) pDoc->m_Objects.GetNext(pos);
		ASSERT(pPainter->IsKindOf(RUNTIME_CLASS(CPainted)));

		if (m_pActive != pPainter)
			pPainter->Draw(pDC);
		else
			pPainter->DrawSelected(pDC);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPaintobjView printing

BOOL CPaintobjView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaintobjView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaintobjView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaintobjView diagnostics

#ifdef _DEBUG
void CPaintobjView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPaintobjView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPaintobjDoc* CPaintobjView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintobjDoc)));
	return (CPaintobjDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintobjView message handlers

void CPaintobjView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CPaintobjDoc* pDoc = (CPaintobjDoc*) GetDocument();

	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	ClientDC.DPtoLP(&point);

	if (pDoc->m_pSelectedTool == NULL)
	{
		POSITION 	pos;
		CPainted*	pPainted;
		CPainted*	pHit;
		pos = pDoc->m_Objects.GetHeadPosition();

		pHit = NULL;
		while (pos != NULL)
		{
			pPainted = (CPainted*) pDoc->m_Objects.GetNext(pos);

			if (pPainted->IsHit(point))
			{
				pHit = pPainted;
				break;
			}
		}

		if (pHit != NULL)
		{
			if (m_pActive != NULL)
			{
				CRect rectInvalid;

				m_pActive->GetBoundingRect(&rectInvalid);
				rectInvalid.InflateRect(1, 1);
				InvalidateRect(&rectInvalid);
			}
			
			m_pActive = pHit;
			m_pActive->DrawSelected(&ClientDC);
		}

		return;
	}

	SetCapture();
	m_bTracking = TRUE;

	pDoc->m_pSelectedTool->OnDown(point);
	CScrollView::OnLButtonDown(nFlags, point);
}

void CPaintobjView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CPaintobjDoc* pDoc = (CPaintobjDoc*) GetDocument();
	ASSERT(pDoc != NULL);

	if (m_bTracking)
	{
		ASSERT(pDoc->m_pSelectedTool != NULL);
		pDoc->m_pSelectedTool->OnUp(point, this);

		CRect rect;
		pDoc->m_pSelectedTool->GetBoundingRect(&rect);
		pDoc->ExpandBounds(&rect);

		pDoc->m_Objects.AddTail(pDoc->m_pSelectedTool);
		pDoc->m_pSelectedTool = NULL;
		pDoc->m_nSelectedTool = ID_TOOL_SELECTOR;

		m_bTracking = FALSE;
		ReleaseCapture();
		
		CMainFrame* pMain = (CMainFrame*) AfxGetApp()->m_pMainWnd;
		pMain->ClearPositionText();
  	}

	CScrollView::OnLButtonUp(nFlags, point);
}

void CPaintobjView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC ClientDC(this);
	OnPrepareDC(&ClientDC);
	ClientDC.DPtoLP(&point);

	CPaintobjDoc* pDoc = (CPaintobjDoc*) GetDocument();
	ASSERT(pDoc != NULL);

	if (pDoc->m_pSelectedTool == NULL)
	{
		::SetCursor(m_hcurArrow);
		return;
	}

	::SetCursor(m_hcurCross);

	if (!m_bTracking)
		return;

	CMainFrame* pMain = (CMainFrame*) AfxGetApp()->m_pMainWnd;
	pMain->SetPositionText(point);
	
	pDoc->m_pSelectedTool->DragDraw(&ClientDC, point);
	CScrollView::OnMouseMove(nFlags, point);
}


void CPaintobjView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	CPaintobjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CSize siz;
	pDoc->GetBounds(&siz);
	
	m_bZoomMode = FALSE;
	SetScrollSizes(MM_TEXT, siz);
	SetScrollSizes(MM_TEXT, siz);
}

void CPaintobjView::OnViewScroll() 
{
	CPaintobjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CSize siz;
	pDoc->GetBounds(&siz);
	
	m_bZoomMode = FALSE;
	SetScrollSizes(MM_TEXT, siz);
}

void CPaintobjView::OnUpdateViewScroll(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(!m_bZoomMode);
}

void CPaintobjView::OnUpdateViewZoomfit(CCmdUI* pCmdUI) 
{
	CPaintobjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	POSITION pos;
	pos = pDoc->m_Objects.GetHeadPosition();

	pCmdUI->SetCheck(m_bZoomMode);
	pCmdUI->Enable(pos != NULL);
}

void CPaintobjView::OnViewZoomfit() 
{
	CPaintobjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CSize siz;
	pDoc->GetBounds(&siz);
	m_bZoomMode = TRUE;
	SetScaleToFitSize(siz);
}


void CPaintobjView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pActive != NULL);
}

void CPaintobjView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pActive != NULL);
}

void CPaintobjView::OnEditCut() 
{
	ASSERT(m_pActive != NULL);

	CPaintobjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	POSITION 	pos;
	CRect		rectUpdate;
	CPainted*	pPainted;
	BOOL		bFoundIt = FALSE;
	pos = pDoc->m_Objects.GetHeadPosition();

	while (pos != NULL)
	{
		pPainted = (CPainted*) pDoc->m_Objects.GetAt(pos);
		if (pPainted == m_pActive)
		{
			bFoundIt = TRUE;
			break;
		}
		pDoc->m_Objects.GetNext(pos);
	}

	ASSERT(bFoundIt == TRUE);
	if (bFoundIt == TRUE)
	{
		pDoc->m_Objects.RemoveAt(pos);
		m_pActive->GetBoundingRect(&rectUpdate);
		rectUpdate.InflateRect(1, 1);
		delete m_pActive;
		m_pActive = NULL;

		InvalidateRect(&rectUpdate);
	}

	pDoc->RecalcBoundary();

	if (m_bZoomMode)
		OnViewZoomfit();
	else
		OnViewScroll();

	return;
}
