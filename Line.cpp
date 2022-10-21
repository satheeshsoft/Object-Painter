// line.cpp : implementation of the CPaintLine class
//

#include "stdafx.h"
#include "line.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintLine

IMPLEMENT_SERIAL(CPaintLine, CPainted, VERSIONABLE_SCHEMA)

void CPaintLine::Draw(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	pDrawPen;

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->MoveTo(m_pointPrimary);
	pDC->LineTo(m_pointEnd);

	pDC->SelectObject(pOldPen);
}

void CPaintLine::DragDraw(CDC* pDC, CPoint& pointDragged)
{
	pDC->SetROP2(R2_NOT);
	
	CPen*	pOldPen;
	CPen	pDrawPen;

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->MoveTo(m_pointPrimary);
	pDC->LineTo(m_pointEnd);

	pDC->MoveTo(m_pointPrimary);
	pDC->LineTo(pointDragged);

	m_pointEnd = pointDragged;
	pDC->SelectObject(pOldPen);
}

void CPaintLine::DrawSelected(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	pDrawPen;

	pDrawPen.CreatePen(PS_DASH, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->MoveTo(m_pointPrimary);
	pDC->LineTo(m_pointEnd);

	pDC->SelectObject(pOldPen);
}

void CPaintLine::OnDown(CPoint& pointDown)
{
	m_pointEnd = m_pointPrimary = pointDown;
}

void CPaintLine::OnUp(CPoint& pointUp, CWnd* pWnd)
{
	m_pointEnd = pointUp;
 	NormalizePoints(m_pointPrimary, m_pointEnd);
}

BOOL CPaintLine::IsHit(CPoint& pointBang)
{
	// Warning: this routine was written by a fellow
	// who does not own a good book on graphics algorithms.
	// It would be much more efficient to do thi with integers...

	if (!((m_pointPrimary.x < pointBang.x) && (pointBang.x < m_pointEnd.x) &&
		  (m_pointPrimary.y < pointBang.y) && (pointBang.y < m_pointEnd.y)))
	{
		return FALSE;
	}

	double dSlope;
	double b;

	if (m_pointPrimary.x == m_pointEnd.x)
	{
		if (abs(pointBang.x - m_pointPrimary.x) < (5+m_nWidth))
		{
			if (pointBang.y <= m_pointEnd.y &&
				pointBang.y >= m_pointPrimary.y)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		dSlope = ((double) m_pointEnd.y - m_pointPrimary.y) /
				 ((double) m_pointEnd.x - m_pointPrimary.x);

		b = m_pointPrimary.y - dSlope*m_pointPrimary.x;

		if (fabs((pointBang.y - dSlope*pointBang.x) - b) <= (10+m_nWidth))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

}

void CPaintLine::GetBoundingRect(CRect* pRect)
{
	pRect->left = m_pointPrimary.x;
	pRect->top = m_pointPrimary.y;
	pRect->right = m_pointEnd.x;
	pRect->bottom = m_pointEnd.y;
}

void CPaintLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_pointEnd;
	}
	else
	{
		ar >> m_pointEnd;
	}

	CPainted::Serialize(ar);
}

