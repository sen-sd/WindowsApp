
// Sample_MFCView.h : interface of the CSample_MFCView class
//

#pragma once


class CSample_MFCView : public CView
{
protected: // create from serialization only
	CSample_MFCView();
	DECLARE_DYNCREATE(CSample_MFCView)

// Attributes
public:
	CSample_MFCDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSample_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Sample_MFCView.cpp
inline CSample_MFCDoc* CSample_MFCView::GetDocument() const
   { return reinterpret_cast<CSample_MFCDoc*>(m_pDocument); }
#endif

