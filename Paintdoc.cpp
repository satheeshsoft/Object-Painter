// paintdoc.cpp : implementation of the CPaintobjDoc class
//

#include "stdafx.h"
#include "paintobj.h"
#include "line.h"
#include "square.h"
#include "circle.h"

#include "paintdoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintobjDoc

IMPLEMENT_DYNCREATE(CPaintobjDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaintobjDoc, CDocument)
	//{{AFX_MSG_MAP(CPaintobjDoc)
	ON_COMMAND(ID_TOOL_CIRCLE, OnToolCircle)
	ON_COMMAND(ID_TOOL_LINE, OnToolLine)
	ON_COMMAND(ID_TOOL_RECTANGLE, OnToolRectangle)
	ON_COMMAND(ID_TOOL_SQUARE, OnToolSquare)
	ON_COMMAND(ID_TOOL_ELLIPSE, OnToolEllipse)
	ON_COMMAND(ID_TOOL_FCIRCLE, OnToolFcircle)
	ON_COMMAND(ID_TOOL_FELLIPSE, OnToolFellipse)
	ON_COMMAND(ID_TOOL_FRECTANGLE, OnToolFrectangle)
	ON_COMMAND(ID_TOOL_FSQUARE, OnToolFsquare)
	ON_UPDATE_COMMAND_UI(ID_TOOL_CIRCLE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_LINE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_RECTANGLE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SQUARE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ELLIPSE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_FCIRCLE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_FELLIPSE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_FRECTANGLE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_FSQUARE, OnUpdateToolCheck)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SELECTOR, OnUpdateToolCheck)
	ON_COMMAND(ID_TOOL_SELECTOR, OnToolSelector)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintobjDoc construction/destruction

CPaintobjDoc::CPaintobjDoc()
{
	m_size = CSize(10, 10);
	m_nSelectedTool = ID_TOOL_LINE;
	m_pSelectedTool = new CPaintLine;
}

CPaintobjDoc::~CPaintobjDoc()
{
	if (m_pSelectedTool != NULL)
		delete m_pSelectedTool;
	DeleteContents();
}

BOOL CPaintobjDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CPaintobjDoc serialization

void CPaintobjDoc::Serialize(CArchive& ar)
{
	m_Objects.Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_size;
	}
	else
	{
		ar >> m_size;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPaintobjDoc diagnostics

#ifdef _DEBUG
void CPaintobjDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaintobjDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintobjDoc commands


void CPaintobjDoc::OnToolCircle() 
{
	m_nSelectedTool = ID_TOOL_CIRCLE;
	GenerateTool();
}

void CPaintobjDoc::OnToolLine() 
{
	m_nSelectedTool = ID_TOOL_LINE;
	GenerateTool();
}

void CPaintobjDoc::OnToolRectangle() 
{
	m_nSelectedTool = ID_TOOL_RECTANGLE;
	GenerateTool();
}

void CPaintobjDoc::OnToolSquare() 
{
	m_nSelectedTool = ID_TOOL_SQUARE;
	GenerateTool();
}

void CPaintobjDoc::DeleteContents() 
{
	while (!m_Objects.IsEmpty())
	{
		CObject* pObj = m_Objects.GetHead();
		delete pObj;
		m_Objects.RemoveHead();
	}
		
	CDocument::DeleteContents();
}

void CPaintobjDoc::GenerateTool()
{
	if (m_pSelectedTool != NULL)
   {
      delete m_pSelectedTool;
      m_pSelectedTool = NULL;
   }

	switch (m_nSelectedTool)
	{
		case ID_TOOL_SELECTOR:
			// okay - just delete m_pSelectedTool
			break;

		case ID_TOOL_SQUARE:
			m_pSelectedTool = new CPaintSquare(FALSE);
			break;

		case ID_TOOL_FSQUARE:
			m_pSelectedTool = new CPaintSquare(TRUE);
			break;

		case ID_TOOL_RECTANGLE:
			m_pSelectedTool = new CPaintRect(FALSE);
			break;

		case ID_TOOL_FRECTANGLE:
			m_pSelectedTool = new CPaintRect(TRUE);
			break;

		case ID_TOOL_ELLIPSE:
			m_pSelectedTool = new CPaintEllipse(FALSE);
			break;

		case ID_TOOL_FELLIPSE:
			m_pSelectedTool = new CPaintEllipse(TRUE);
			break;
			  
		case ID_TOOL_CIRCLE:
			m_pSelectedTool = new CPaintCircle(FALSE);
			break;

		case ID_TOOL_FCIRCLE:
			m_pSelectedTool = new CPaintCircle(TRUE);
			break;

		case ID_TOOL_LINE:
			m_pSelectedTool = new CPaintLine;
			break;

		default:
			// unknown tool ID!
			ASSERT(FALSE);
	}

	return;
}

void CPaintobjDoc::OnToolEllipse() 
{
	m_nSelectedTool = ID_TOOL_ELLIPSE;
	GenerateTool();
}

void CPaintobjDoc::OnToolFcircle() 
{
	m_nSelectedTool = ID_TOOL_FCIRCLE;
	GenerateTool();
}

void CPaintobjDoc::OnToolFellipse() 
{
	m_nSelectedTool = ID_TOOL_FELLIPSE;
	GenerateTool();
}

void CPaintobjDoc::OnToolFrectangle() 
{
	m_nSelectedTool = ID_TOOL_FRECTANGLE;
	GenerateTool();
}

void CPaintobjDoc::OnUpdateToolCheck(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_nSelectedTool == pCmdUI->m_nID);
}

void CPaintobjDoc::OnToolFsquare() 
{
	m_nSelectedTool = ID_TOOL_FSQUARE;
	GenerateTool();
}

void CPaintobjDoc::OnToolSelector() 
{
	m_nSelectedTool = ID_TOOL_SELECTOR;
	GenerateTool();
}

void CPaintobjDoc::ExpandBounds(CRect* pRect)
{
	m_size.cx = max(m_size.cx, pRect->right);
	m_size.cy = max(m_size.cy, pRect->bottom);
}

void CPaintobjDoc::GetBounds(CSize* pSize)
{
	*pSize = m_size;
}

void CPaintobjDoc::RecalcBoundary()
{
	m_size.cy = m_size.cx = 0;

	POSITION	pos;
	CRect		rect;
	CPainted*	pPainted;

	pos = m_Objects.GetHeadPosition();

	while (pos != NULL)
	{
		pPainted = (CPainted*) m_Objects.GetNext(pos);
		pPainted->GetBoundingRect(&rect);

		m_size.cy = max(m_size.cy, rect.bottom);
		m_size.cx = max(m_size.cx, rect.right);
	}
}
