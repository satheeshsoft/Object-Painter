// circle.cpp : implementation of the CPaintCircle and CPaintEllipse classes
//

#include "stdafx.h"
#include "circle.h"

#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintCircle
			   
IMPLEMENT_SERIAL(CPaintCircle, CPainted, VERSIONABLE_SCHEMA)

CPaintCircle::CPaintCircle(BOOL bFilled)
{
	m_rgbInside = RGB(127, 127, 127);
	m_bFilled = bFilled;
}

void CPaintCircle::Draw(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	DrawPen;
	CBrush*	pOldBrush;
	CBrush	DrawBrush;

	DrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&DrawPen);

	if (m_bFilled)
	{
		DrawBrush.CreateSolidBrush(m_rgbInside);
		pOldBrush = pDC->SelectObject(&DrawBrush);
	}
	else
	{
		pOldBrush = (CBrush*) pDC->SelectStockObject(HOLLOW_BRUSH);
	}

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
 			m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CPaintCircle::DragDraw(CDC* pDC, CPoint& pointDragged)
{
	int nOldROPMode = pDC->SetROP2(R2_NOT);
	int nOldBkMode=  pDC->SetBkMode(TRANSPARENT);
	
	CPen*	pOldPen;
	CPen	pDrawPen;

	pDC->SelectStockObject(HOLLOW_BRUSH);
	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
				m_pointLower.x, m_pointLower.y);

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

	pDC->SetROP2(nOldROPMode);
	pDC->SetBkMode(nOldBkMode);

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
				m_pointLower.x, m_pointLower.y);
	pDC->SelectObject(pOldPen);
}

void CPaintCircle::DrawSelected(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	DrawPen;
	CBrush*	pOldBrush;
	CBrush	DrawBrush;

	DrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&DrawPen);

	DrawBrush.CreateHatchBrush(HS_FDIAGONAL, 0);
	pOldBrush = pDC->SelectObject(&DrawBrush);

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
 			m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CPaintCircle::OnDown(CPoint& pointDown)
{
	m_pointPrimary = m_pointLower = pointDown;
}

void CPaintCircle::OnUp(CPoint& pointUp, CWnd* pWnd)
{
 	NormalizePoints(m_pointPrimary, m_pointLower);

	CClientDC tempDC(pWnd);
	Draw(&tempDC);
}

BOOL CPaintCircle::IsHit(CPoint& pointBang)
{
	CRect rect(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);
 	
 	if (!rect.PtInRect(pointBang))
		return FALSE;

	// warning!  Another function written by a guy without a good
	// graphics algorithims book!  I shamelessly use doubles;
	// an equivalent integer-math algorithm would be much smaller and faster.

	double dCenterX = (double) rect.left+rect.Width()/2.0;
	double dCenterY = (double) rect.top+rect.Height()/2.0 ;

	double dDist = pow(((double) pointBang.x - dCenterX) / (rect.Width()/2.0), 2.0) +
				   pow(((double) pointBang.y - dCenterY) / (rect.Height()/2.0), 2.0);

	if (dDist <= 1.0000)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void CPaintCircle::GetBoundingRect(CRect* pRect)
{
	pRect->top = m_pointPrimary.y;
	pRect->left = m_pointPrimary.x;
	pRect->bottom = m_pointLower.y;
	pRect->right = m_pointLower.x;
}

void CPaintCircle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_pointLower;
		ar << m_rgbInside;
		ar << (WORD&) m_bFilled;
	}
	else
	{
		ar >> m_pointLower;
		ar >> m_rgbInside;
		ar >> (WORD&) m_bFilled;
	}

	CPainted::Serialize(ar);
}


/////////////////////////////////////////////////////////////////////////////
// CPaintCircle
			   
IMPLEMENT_SERIAL(CPaintEllipse, CPainted, VERSIONABLE_SCHEMA)

CPaintEllipse::CPaintEllipse(BOOL bFilled)
{
	m_rgbInside = RGB(127, 127, 127);
	m_bFilled = bFilled;
}


void CPaintEllipse::Draw(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	DrawPen;
	CBrush*	pOldBrush;
	CBrush	DrawBrush;

	DrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&DrawPen);

	if (m_bFilled)
	{
		DrawBrush.CreateSolidBrush(m_rgbInside);
		pOldBrush = pDC->SelectObject(&DrawBrush);
	}
	else
	{
		pOldBrush = (CBrush *) pDC->SelectStockObject(HOLLOW_BRUSH);
	}

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
 			m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CPaintEllipse::DragDraw(CDC* pDC, CPoint& pointDragged)
{
	int nOldROPMode = pDC->SetROP2(R2_NOT);
	int nOldBkMode=  pDC->SetBkMode(TRANSPARENT);
	
	CPen*	pOldPen;
	CPen	pDrawPen;
	CBrush	DrawBrush;

	pDC->SelectStockObject(HOLLOW_BRUSH);
	pDrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&pDrawPen);

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
				m_pointLower.x, m_pointLower.y);

	m_pointLower = pointDragged;

	pDC->SetROP2(nOldROPMode);
	pDC->SetBkMode(nOldBkMode);

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
				m_pointLower.x, m_pointLower.y);
	pDC->SelectObject(pOldPen);
}

void CPaintEllipse::DrawSelected(CDC* pDC)
{
	CPen*	pOldPen;
	CPen	DrawPen;
	CBrush*	pOldBrush;
	CBrush	DrawBrush;

	DrawPen.CreatePen(PS_SOLID, m_nWidth, m_rgbPrimary);
	pOldPen = pDC->SelectObject(&DrawPen);

	DrawBrush.CreateHatchBrush(HS_FDIAGONAL, 0);
	pOldBrush = pDC->SelectObject(&DrawBrush);

	pDC->Ellipse(m_pointPrimary.x, m_pointPrimary.y,
 			m_pointLower.x, m_pointLower.y);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CPaintEllipse::OnDown(CPoint& pointDown)
{
	m_pointPrimary = m_pointLower = pointDown;
}

void CPaintEllipse::OnUp(CPoint& pointUp, CWnd* pWnd)
{
 	NormalizePoints(m_pointPrimary, m_pointLower);

	CClientDC tempDC(pWnd);
	Draw(&tempDC);
}

BOOL CPaintEllipse::IsHit(CPoint& pointBang)
{
	CRect rect(m_pointPrimary.x, m_pointPrimary.y, m_pointLower.x, m_pointLower.y);
 	
 	if (!rect.PtInRect(pointBang))
		return FALSE;

	// warning!  Another function written by a guy without a good
	// graphics algorithims book!  I shamelessly use doubles;
	// an equivalent integer-math algorithm would be much smaller and faster.

	double dCenterX = (double) rect.left+rect.Width()/2.0;
	double dCenterY = (double) rect.top+rect.Height()/2.0 ;

	double dDist = pow(((double) pointBang.x - dCenterX) / (rect.Width()/2.0), 2.0) +
				   pow(((double) pointBang.y - dCenterY) / (rect.Height()/2.0), 2.0);

	if (dDist <= 1.0000)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


void CPaintEllipse::GetBoundingRect(CRect* pRect)
{
	pRect->top = m_pointPrimary.y;
	pRect->left = m_pointPrimary.x;
	pRect->bottom = m_pointLower.y;
	pRect->right = m_pointLower.x;
}

void CPaintEllipse::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_pointLower;
		ar << m_rgbInside;
		ar << (WORD) m_bFilled;
	}
	else
	{
		ar >> m_pointLower;
		ar >> m_rgbInside;
		ar >> (WORD&) m_bFilled;
	}

	CPainted::Serialize(ar);
}
