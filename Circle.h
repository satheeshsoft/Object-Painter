// circle.h: interface of the CPaintCircle and CPaintEllipse classes
//
/////////////////////////////////////////////////////////////////////////////

class CPaintCircle : public CPainted
{
public:
	CPaintCircle(BOOL bFilled);
	CPaintCircle() { };

  	void Draw(CDC* pCDC);
	void DragDraw(CDC* pDC, CPoint& pointDragged);
	void DrawSelected(CDC* pDC);

	void OnDown(CPoint& pointDown);
	void OnUp(CPoint& pointUp, CWnd* pWnd);
	BOOL IsHit(CPoint& pointBang);
	void GetBoundingRect(CRect* pRect);

	void Serialize(CArchive& ar);

protected:
	DECLARE_SERIAL(CPaintCircle)

	CPoint m_pointLower;
	COLORREF m_rgbInside;
	BOOL m_bFilled;
};


class CPaintEllipse : public CPainted
{
public:
	CPaintEllipse(BOOL bFilleds);
	CPaintEllipse() { };

  	void Draw(CDC* pCDC);
	void DragDraw(CDC* pDC, CPoint& pointDragged);
	void DrawSelected(CDC* pDC);

	void OnDown(CPoint& pointDown);
	void OnUp(CPoint& pointUp, CWnd* pWnd);
	BOOL IsHit(CPoint& pointBang);
	void GetBoundingRect(CRect* pRect);

	void Serialize(CArchive& ar);

protected:
	DECLARE_SERIAL(CPaintEllipse)

	COLORREF m_rgbInside;
	CPoint m_pointLower;
	BOOL m_bFilled;
};
