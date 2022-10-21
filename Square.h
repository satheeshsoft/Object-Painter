// square.h : interface of the CPaintSquare and CPaintRect class
//
/////////////////////////////////////////////////////////////////////////////

class CPaintSquare : public CPainted
{
public:
	CPaintSquare() { };
	CPaintSquare(BOOL bFilled);

  	void Draw(CDC* pCDC);
	void DragDraw(CDC* pDC, CPoint& pointDragged);
	void DrawSelected(CDC* pDC);

	void OnDown(CPoint& pointDown);
	void OnUp(CPoint& pointUp, CWnd* pWnd);

	BOOL IsHit(CPoint& pointBang);
	void GetBoundingRect(CRect* pRect);

	void Serialize(CArchive& ar);

protected:
	DECLARE_SERIAL(CPaintSquare)

	CPoint m_pointLower;
	COLORREF m_rgbInside;
	BOOL m_bFilled;
};


class CPaintRect : public CPainted
{
public:
	CPaintRect() { };
	CPaintRect(BOOL bFilled);

  	void Draw(CDC* pCDC);
	void DragDraw(CDC* pDC, CPoint& pointDragged);
	void DrawSelected(CDC* pDC);

	void OnDown(CPoint& pointDown);
	void OnUp(CPoint& pointUp, CWnd* pWnd);
	BOOL IsHit(CPoint& pointBang);
  	void Serialize(CArchive& ar);
	void GetBoundingRect(CRect* pRect);

protected:
	DECLARE_SERIAL(CPaintRect)

	CPoint m_pointLower;
	COLORREF m_rgbInside;
	BOOL m_bFilled;
};
