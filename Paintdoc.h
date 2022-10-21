// paintdoc.h : interface of the CPaintobjDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CPaintobjDoc : public CDocument
{
protected: // create from serialization only
	CPaintobjDoc();
	DECLARE_DYNCREATE(CPaintobjDoc)
 
	CSize m_size;

// Attributes
public:

// Operations
public:
	void GetBounds(CSize* siz);
	void ExpandBounds(CRect* pRect);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintobjDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaintobjDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	UINT		m_nSelectedTool;
	CPainted*	m_pSelectedTool;
	CObList		m_Objects;

	void GenerateTool();
	void RecalcBoundary();

// Generated message map functions
protected:
	//{{AFX_MSG(CPaintobjDoc)
	afx_msg void OnToolCircle();
	afx_msg void OnToolLine();
	afx_msg void OnToolRectangle();
	afx_msg void OnToolSquare();
	afx_msg void OnToolEllipse();
	afx_msg void OnToolFcircle();
	afx_msg void OnToolFellipse();
	afx_msg void OnToolFrectangle();
	afx_msg void OnToolFsquare();
	afx_msg void OnUpdateToolCheck(CCmdUI* pCmdUI);
	afx_msg void OnToolSelector();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
