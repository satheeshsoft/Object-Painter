// painted.cpp : implementation of the CPainted class
//

#include "stdafx.h"
#include "line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPainted

IMPLEMENT_DYNAMIC(CPainted, CObject)

CPainted::CPainted()
{
	m_rgbPrimary = RGB(0, 0, 0);		// blue
	m_nWidth = 1;

	m_pointPrimary = CPoint(0,0);
}


void CPainted::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD) m_nWidth;
		ar << m_rgbPrimary;
		ar << m_pointPrimary;
	}
	else
	{
		ar >> (WORD&) m_nWidth;
		ar >> m_rgbPrimary;
		ar >> m_pointPrimary;
	}
}

void CPainted::NormalizePoints(CPoint& pointTopLeft, CPoint& pointBottomRight)
{
	if (pointTopLeft.x > pointBottomRight.x &&
		pointTopLeft.y > pointBottomRight.y)
	{
		int swap;

		swap = pointBottomRight.y;
		pointBottomRight.y = pointTopLeft.y;
		pointTopLeft.y = swap;

		swap = pointBottomRight.x;
		pointBottomRight.x = pointTopLeft.x;
		pointTopLeft.x = swap;
 	}
}

