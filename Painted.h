// painted.h : interface of the CPaintLine class
//
/////////////////////////////////////////////////////////////////////////////

class CPainted : public CObject
{
public:
	CPainted();

	virtual void Draw(CDC* pCDC) = 0;
	virtual void DragDraw(CDC* pCDC, CPoint& pointDragged) = 0;
	virtual void DrawSelected(CDC* pCDC) = 0;

	virtual void OnDown(CPoint& pointDown) = 0;
	virtual void OnUp(CPoint& pointUp, CWnd* pWnd) = 0;

	virtual BOOL IsHit(CPoint& pointBang) = 0;
	virtual void GetBoundingRect(CRect* pRect) = 0;

	virtual void Serialize(CArchive& ar);
	void NormalizePoints(CPoint& pointTopLeft, CPoint& pointBottomRight);
 
protected:
	DECLARE_DYNAMIC(CPainted)

	CPoint	m_pointPrimary;
	COLORREF	m_rgbPrimary;
	int			m_nWidth;
};


