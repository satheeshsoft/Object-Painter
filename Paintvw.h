// paintvw.h : interface of the CPaintobjView class
//
/////////////////////////////////////////////////////////////////////////////

class CPaintobjView : public CScrollView
{
protected: // create from serialization only
	CPaintobjView();
	DECLARE_DYNCREATE(CPaintobjView)

	HCURSOR	m_hcurCross;
	HCURSOR	m_hcurArrow;
	HCURSOR m_hcurSize;

	BOOL	m_bTracking;
	BOOL	m_bZoomMode;

	CRect	rectBounds;

// Attributes
public:
	CPaintobjDoc* GetDocument();
	CPainted* m_pActive;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintobjView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaintobjView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaintobjView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnViewScroll();
	afx_msg void OnUpdateViewScroll(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewZoomfit(CCmdUI* pCmdUI);
	afx_msg void OnViewZoomfit();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in paintvw.cpp
inline CPaintobjDoc* CPaintobjView::GetDocument()
   { return (CPaintobjDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
