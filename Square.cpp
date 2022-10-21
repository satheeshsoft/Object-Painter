// square.cpp : implementation of the CPaintSquare and CPaintRect classes
//

#include "stdafx.h"
#include "square.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintSquare

IMPLEMENT_SERIAL(CPaintSquare, CPainted, VERSIONABLE_SCHEMA)

CPaintSquare::CPaintSquare(BOOL bFilled)
{
	m_bFilled = bFilled;
	m_rgbInside = RGB(127, 127, 127);
}

void CPaintSquare::Draw(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	pDrawPen;
	CBrush 	DrawBrush;
	CBrush* pOldBrush;

	if (m_bFilled)
	{
		DrawBrush.CreateSolidBrush(m_rgbInside);
		pOldBrush = pDC->SelectObject(&DrawBrush);
	}
	else
	{
		pOldBrush = (CBrush*) pDC->SelectStockObject(HOLLOW_BRUSH);
	}

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->Rectangle(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void CPaintSquare::DragDraw(CDC* pDC, CPoint& pointDragged)
{
	pDC->SetROP2(R2_NOT);
	
	CPen*	pOldPen;
	CPen	DrawPen;

	DrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&DrawPen);

	pDC->MoveTo(m_pointPrimary.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointPrimary.y);

	m_pointLower = m_pointPrimary;

	int nXOffset = max(
		abs(m_pointPrimary.x - pointDragged.x),
		abs(m_pointPrimary.y - pointDragged.y));
	int nYOffset = nXOffset;
	m_pointLower = m_pointPrimary;

	if (m_pointPrimary.x > pointDragged.x)
	{
		nXOffset = -nXOffset;
	}

	if (m_pointPrimary.y > pointDragged.y)
	{
		nYOffset = -nYOffset;
	}

	m_pointLower.Offset(nXOffset, nYOffset);

	pDC->MoveTo(m_pointPrimary.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointPrimary.y);
	pDC->SelectObject(pOldPen);
}

void CPaintSquare::DrawSelected(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	pDrawPen;
	CBrush 	DrawBrush;
	CBrush* pOldBrush;

	DrawBrush.CreateHatchBrush(HS_FDIAGONAL, 0);
	pOldBrush = pDC->SelectObject(&DrawBrush);

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->Rectangle(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void CPaintSquare::OnDown(CPoint& pointDown)
{
	m_pointLower = m_pointPrimary = pointDown;
}

void CPaintSquare::OnUp(CPoint& pointUp, CWnd* pWnd)
{
	NormalizePoints(m_pointPrimary, m_pointLower);

	CClientDC DrawDC(pWnd);
	Draw(&DrawDC);
}

void CPaintSquare::GetBoundingRect(CRect* pRect)
{
	pRect->top = m_pointPrimary.y;
	pRect->left = m_pointPrimary.x;
	pRect->bottom = m_pointLower.y;
	pRect->right = m_pointLower.x;
}

BOOL CPaintSquare::IsHit(CPoint& pointBang)
{
	CRect rect(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);
 	return rect.PtInRect(pointBang);
}


void CPaintSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_pointLower;
		ar << m_rgbInside;
	}
	else
	{
		ar >> m_pointLower;
		ar >> m_rgbInside;
	}

	CPainted::Serialize(ar);
}


/////////////////////////////////////////////////////////////////////////////
// CPaintRect

IMPLEMENT_SERIAL(CPaintRect, CPainted, VERSIONABLE_SCHEMA)

CPaintRect::CPaintRect(BOOL bFilled)
{
	m_bFilled = bFilled;
	m_rgbInside = RGB(127, 127, 127);
}

void CPaintRect::Draw(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	pDrawPen;
	CBrush 	DrawBrush;
	CBrush* pOldBrush;

	if (m_bFilled)
	{
		DrawBrush.CreateSolidBrush(m_rgbInside);
		pOldBrush = pDC->SelectObject(&DrawBrush);
	}
	else
	{
		pOldBrush = (CBrush*) pDC->SelectStockObject(HOLLOW_BRUSH);
	}

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->Rectangle(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void CPaintRect::DragDraw(CDC* pDC, CPoint& pointDragged)
{
	pDC->SetROP2(R2_NOT);
	
	CPen*	pOldPen;
	CPen	pDrawPen;

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->MoveTo(m_pointPrimary.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointPrimary.y);

	m_pointLower = pointDragged;

	pDC->MoveTo(m_pointPrimary.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointLower.y);
	pDC->LineTo(m_pointLower.x, m_pointPrimary.y);
	pDC->LineTo(m_pointPrimary.x, m_pointPrimary.y);
	pDC->SelectObject(pOldPen);
}

void CPaintRect::DrawSelected(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	pDrawPen;
	CBrush 	DrawBrush;
	CBrush* pOldBrush;

	DrawBrush.CreateHatchBrush(HS_FDIAGONAL, 0);
	pOldBrush = pDC->SelectObject(&DrawBrush);

	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->Rectangle(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void CPaintRect::OnDown(CPoint& pointDown)
{
	m_pointLower = m_pointPrimary = pointDown;
}

void CPaintRect::OnUp(CPoint& pointUp, CWnd* pWnd)
{
 	NormalizePoints(m_pointPrimary, m_pointLower);

	CClientDC DrawDC(pWnd);
	Draw(&DrawDC);
}

void CPaintRect::GetBoundingRect(CRect* pRect)
{
	pRect->top = m_pointPrimary.y;
	pRect->left = m_pointPrimary.x;
	pRect->bottom = m_pointLower.y;
	pRect->right = m_pointLower.x;
}

BOOL CPaintRect::IsHit(CPoint& pointBang)
{
	CRect rect(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);
 	return rect.PtInRect(pointBang);
}

void CPaintRect::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_pointLower;
		ar << m_rgbInside;
	}
	else
	{
		ar >> m_pointLower;
		ar >> m_rgbInside;
	}

	CPainted::Serialize(ar);
}
