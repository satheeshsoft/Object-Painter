// line.h : interface of the CPaintLine class
//
/////////////////////////////////////////////////////////////////////////////

class CPaintLine : public CPainted
{
public:
    CPaintLine() {};

  	void Draw(CDC* pCDC);
	void DragDraw(CDC* pCDC, CPoint& pointDragged);
	void DrawSelected(CDC* pCDC);

	void OnDown(CPoint& pointDown);
	void OnUp(CPoint& pointUp, CWnd* pWnd);

	virtual BOOL IsHit(CPoint& pointBang);
	void Serialize(CArchive& ar);
	void GetBoundingRect(CRect* pRect);

protected:
	DECLARE_SERIAL(CPaintLine)

	CPoint m_pointEnd;
};


