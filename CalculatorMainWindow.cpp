﻿#pragma once
#include "CalculatorMainWindow.h"
#include "MatrixCalculator.h"

//------------------------------------------------------------------
// Initialization
//------------------------------------------------------------------

// Connect controls with corresponding member variables, so we don't need
// explicitly get control from dialog.
void CalculatorMainWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DISPLAY, m_csDigitDisplay);
	DDX_Control(pDX, IDC_BTN_0, m_button0);
	DDX_Control(pDX, IDC_BTN_1, m_button1);
	DDX_Control(pDX, IDC_BTN_2, m_button2);
	DDX_Control(pDX, IDC_BTN_3, m_button3);
	DDX_Control(pDX, IDC_BTN_4, m_button4);
	DDX_Control(pDX, IDC_BTN_5, m_button5);
	DDX_Control(pDX, IDC_BTN_6, m_button6);
	DDX_Control(pDX, IDC_BTN_7, m_button7);
	DDX_Control(pDX, IDC_BTN_8, m_button8);
	DDX_Control(pDX, IDC_BTN_9, m_button9);
	DDX_Control(pDX, IDC_BTN_DIVISION, m_buttonDivision);
	DDX_Control(pDX, IDC_BTN_PRODUCT, m_buttonProduct);
	DDX_Control(pDX, IDC_BTN_MINUS, m_buttonMinus);
	DDX_Control(pDX, IDC_BTN_PLUS, m_buttonPlus);
	DDX_Control(pDX, IDC_BTN_COMMA, m_buttonComma);
	DDX_Control(pDX, IDC_BTN_EQUAL, m_buttonEqual);
	DDX_Control(pDX, IDC_BTN_BACKSPACE, m_buttonBackspace);
	DDX_Control(pDX, IDC_BTN_CLEAR, m_buttonClear);
	DDX_Control(pDX, IDC_EDIT_DISPLAY, m_ceDisplay);
	DDX_Control(pDX, IDC_BTN_MATRIXCALC, m_cbtnMatrixCalc);
}

// Initial values for fonts, colors and other style.
BOOL CalculatorMainWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add some fonts.
	//---------------------------------------
	// Buttons
	m_cfCalcButtonFont.CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, L"Microsoft Sans Serif");
	m_button0.SetFont(&m_cfCalcButtonFont);
	m_button1.SetFont(&m_cfCalcButtonFont);
	m_button2.SetFont(&m_cfCalcButtonFont);
	m_button3.SetFont(&m_cfCalcButtonFont);
	m_button4.SetFont(&m_cfCalcButtonFont);
	m_button5.SetFont(&m_cfCalcButtonFont);
	m_button6.SetFont(&m_cfCalcButtonFont);
	m_button7.SetFont(&m_cfCalcButtonFont);
	m_button8.SetFont(&m_cfCalcButtonFont);
	m_button9.SetFont(&m_cfCalcButtonFont);
	m_buttonDivision.SetFont(&m_cfCalcButtonFont);
	m_buttonProduct.SetFont(&m_cfCalcButtonFont);
	m_buttonMinus.SetFont(&m_cfCalcButtonFont);
	m_buttonPlus.SetFont(&m_cfCalcButtonFont);
	m_buttonComma.SetFont(&m_cfCalcButtonFont);
	m_buttonEqual.SetFont(&m_cfCalcButtonFont);
	m_buttonBackspace.SetFont(&m_cfCalcButtonFont);
	m_buttonClear.SetFont(&m_cfCalcButtonFont);

	// Display
	m_cfCalcDisplayFont.CreateFont(22, 0, 0, 0, FW_ULTRALIGHT, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, L"Lucida Console");
	m_ceDisplay.SetFont(&m_cfCalcDisplayFont);
	m_ceDisplay.SetReadOnly();

	// Matrix Calc button
	m_cfCalcButtonMatrixFont.CreateFont(16, 0, 0, 0, FW_ULTRALIGHT, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, L"Lucida Console");
	m_cbtnMatrixCalc.SetFont(&m_cfCalcButtonMatrixFont);

	// Vertical align text inside the calculator's display.
	CRect crEditRect;
	m_ceDisplay.GetRect(&crEditRect);
	// Reduce the formatting rect of the edit control by
	// 10 pixels on each side.
	if (crEditRect.Height() > 20)
	{
		crEditRect.DeflateRect(0, 20, 0, 0);
		m_ceDisplay.SetRect(&crEditRect);
	}

	// Change the buttons colors.
	//---------------------------
	// Digit buttons
	m_button0.EnableWindowsTheming(FALSE);
	m_button0.SetFaceColor(m_crfDigitBtnColor);
	m_button0.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button1.EnableWindowsTheming(FALSE);
	m_button1.SetFaceColor(m_crfDigitBtnColor);
	m_button1.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button2.EnableWindowsTheming(FALSE);
	m_button2.SetFaceColor(m_crfDigitBtnColor);
	m_button2.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button3.EnableWindowsTheming(FALSE);
	m_button3.SetFaceColor(m_crfDigitBtnColor);
	m_button3.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button4.EnableWindowsTheming(FALSE);
	m_button4.SetFaceColor(m_crfDigitBtnColor);
	m_button4.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button5.EnableWindowsTheming(FALSE);
	m_button5.SetFaceColor(m_crfDigitBtnColor);
	m_button5.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button6.EnableWindowsTheming(FALSE);
	m_button6.SetFaceColor(m_crfDigitBtnColor);
	m_button6.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button7.EnableWindowsTheming(FALSE);
	m_button7.SetFaceColor(m_crfDigitBtnColor);
	m_button7.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button8.EnableWindowsTheming(FALSE);
	m_button8.SetFaceColor(m_crfDigitBtnColor);
	m_button8.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_button9.EnableWindowsTheming(FALSE);
	m_button9.SetFaceColor(m_crfDigitBtnColor);
	m_button9.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	// Equals sign and comma
	m_buttonEqual.EnableWindowsTheming(FALSE);
	m_buttonEqual.SetFaceColor(m_crfEqualBtnColor);
	m_buttonEqual.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_buttonComma.EnableWindowsTheming(FALSE);
	m_buttonComma.SetFaceColor(m_crfEqualBtnColor);
	m_buttonComma.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	// Math operations
	m_buttonDivision.EnableWindowsTheming(FALSE);
	m_buttonDivision.SetFaceColor(m_crfMathOperationsBtnColor);
	m_buttonDivision.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_buttonProduct.EnableWindowsTheming(FALSE);
	m_buttonProduct.SetFaceColor(m_crfMathOperationsBtnColor);
	m_buttonProduct.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_buttonMinus.EnableWindowsTheming(FALSE);
	m_buttonMinus.SetFaceColor(m_crfMathOperationsBtnColor);
	m_buttonMinus.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	m_buttonPlus.EnableWindowsTheming(FALSE);
	m_buttonPlus.SetFaceColor(m_crfMathOperationsBtnColor);
	m_buttonPlus.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	// Clear button
	m_buttonClear.EnableWindowsTheming(FALSE);
	m_buttonClear.SetFaceColor(m_crfClearBtnColor);
	m_buttonClear.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	// Backspace
	m_buttonBackspace.EnableWindowsTheming(FALSE);
	m_buttonBackspace.SetFaceColor(m_crfBackSpaceBtnColor);
	m_buttonBackspace.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	// Matrix Calc
	m_cbtnMatrixCalc.EnableWindowsTheming(FALSE);
	m_cbtnMatrixCalc.SetFaceColor(m_crfBackSpaceBtnColor);
	m_cbtnMatrixCalc.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;
	//m_cbtnMatrixCalc.SetButtonStyle(BS_VCENTER); // A vertical alignment by this way just kills other style tweaks.

	return TRUE;
}

// Translate keyboard message to dialog. That's a litle bit easier then custom CEdit class with input processing on its side.
// Each allowed key from user keyboard will be processed by corresponding handler for GUI key.
BOOL CalculatorMainWindow::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		// Get the virtual code from message.
		WPARAM nCode = pMsg->wParam;
		// Convert virtual code into a character.
		UINT nChar = MapVirtualKeyA(nCode, MAPVK_VK_TO_CHAR);

		// Filter for non-digit characters or minus, or dot, or...
		if ((nChar < CHAR_0 || nChar > CHAR_9)
			&& nChar != CHAR_ASTERISK && nChar != CHAR_PLUS && nChar != CHAR_COMMA && nChar != CHAR_MINUS && nChar != CHAR_PERIOD && nChar != CHAR_SLASH
			&& nChar != VK_ESCAPE && nChar != VK_RETURN && nChar != CHAR_EQUALS && nChar != VK_BACK)
		{
			return CDialog::PreTranslateMessage(pMsg);
		}

		// Set method for each key.
		switch (nChar)
		{
		case CHAR_0: OnBnClickedBtn0(); break;
		case CHAR_1: OnBnClickedBtn1(); break;
		case CHAR_2: OnBnClickedBtn2(); break;
		case CHAR_3: OnBnClickedBtn3(); break;
		case CHAR_4: OnBnClickedBtn4(); break;
		case CHAR_5: OnBnClickedBtn5(); break;
		case CHAR_6: OnBnClickedBtn6(); break;
		case CHAR_7: OnBnClickedBtn7(); break;
		case CHAR_8: OnBnClickedBtn8(); break;
		case CHAR_9: OnBnClickedBtn9(); break;
		case CHAR_ASTERISK: OnBnClickedBtnProduct(); break;
		case CHAR_PLUS:		OnBnClickedBtnPlus(); break;
		case CHAR_COMMA:	OnBnClickedBtnComma(); break;
		case CHAR_MINUS:	OnBnClickedBtnMinus(); break;
		case CHAR_PERIOD:	OnBnClickedBtnComma(); break;
		case CHAR_SLASH:	OnBnClickedBtnDivision(); break;
		case VK_ESCAPE:		OnBnClickedBtnClear(); break;
		case VK_RETURN:		OnBnClickedBtnEqual(); break;
		case CHAR_EQUALS:	OnBnClickedBtnEqual(); break;
		case VK_BACK:		OnBnClickedBtnBackspace(); break;
		}

		// Don't do more with it.
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

// Set background color for calculator's display.
HBRUSH CalculatorMainWindow::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (nCtlColor)
	{
		// Case for edit mode. Stay here for those case if I allow user edit display's string.
	case CTLCOLOR_EDIT:
		if (pWnd->GetDlgCtrlID() == IDC_EDIT_DISPLAY)
		{
			pDC->SetBkColor(m_crfDisplayBkColor);
			//pDC->SetBkColor(RGB(255, 255, 255));
			return (HBRUSH)(m_hbrushDisplay->GetSafeHandle());
		}
		// Case for read-only display. CTLCOLOR_EDIT doesn't work for read-only edit control.
	case CTLCOLOR_STATIC:
		if (pWnd->GetDlgCtrlID() == IDC_EDIT_DISPLAY)
		{
			pDC->SetBkColor(m_crfDisplayBkColor);
			//pDC->SetBkColor(RGB(255, 255, 255));
			return (HBRUSH)(m_hbrushDisplay->GetSafeHandle());
		}
	}

	return hbr;
}

//------------------------------------------------------------------
// Buttons handlers
//------------------------------------------------------------------

// Add character argument to the end of display string and left or right operand.
void CalculatorMainWindow::AddDigitToDisplay(char cDigit)
{
	// Check for displayng result previouse calculation.
	if (m_bDisplayResult && m_eMathOperation == NONE)
	{
		m_csDigitDisplay = "0";
		m_bDisplayResult = false;
	}

	// Take care of any first zeroes.
	if (m_csDigitDisplay.GetLength() == 1 && m_csDigitDisplay.GetAt(0) == '0' && cDigit != '.')
	{
		// Just replace the first number.
		m_csDigitDisplay.SetAt(0, cDigit);
	}
	// Do the same if right operand is current.
	else if (m_csRightOperand.GetLength() == 1 && m_csRightOperand.GetAt(0) == '0' && cDigit != '.')
	{
		// Just replace the first number.
		m_csRightOperand.SetAt(0, cDigit);
	}
	else
	{
		// Special check for comma input.
		if (cDigit == '.')
		{
			// Are there any comma in the string?
			if (m_eMathOperation == NONE)
			{
				// A left operand's case, so we should check the display string.
				if (m_csDigitDisplay.Find('.') != -1)
				{
					// There's already one separator exists, so nothing to do here.
					return;
				}
			}
			else
			{
				// A right operand's case, so we should check the right operand string.
				if (m_csRightOperand.Find('.') != -1)
				{
					// There's already one separator exists, so nothing to do here.
					return;
				}
				if (!m_csRightOperand.GetLength())
				{
					// If comma is the first character here then add zero before it.
					m_csDigitDisplay += '0';
					m_csRightOperand += '0';
				}
			}
		}

		// Add character to the end of the display string.
		m_csDigitDisplay += cDigit;
		// Check for adding to the rhs operand.
		if (m_eMathOperation != NONE)
		{
			m_csRightOperand += cDigit;
		}
	}

	UpdateData(FALSE);
}

// Backspace button - removes last character from display string.
void CalculatorMainWindow::OnBnClickedBtnBackspace()
{
	int iLength = m_csDigitDisplay.GetLength();
	// Delete last character.
	if (iLength > 1)
	{
		// First we must check for math operation in last character.
		char cLastChar = m_csDigitDisplay.GetAt(iLength - 1);
		if (cLastChar == '/' || cLastChar == '*' || cLastChar == '-' || cLastChar == '+')
		{
			// Set current operation to NONE for preventing unexpected calculations.
			m_eMathOperation = NONE;
			// Clear the right operand.
			m_csRightOperand = "";
		}
		m_csDigitDisplay.Delete(iLength - 1);

		// Trim the right operand if it's the case.
		if (m_eMathOperation != NONE)
		{
			int iLenghtRight = m_csRightOperand.GetLength();
			if (iLenghtRight > 0)
			{
				m_csRightOperand.Delete(iLenghtRight - 1);
			}
		}
	}
	// If there are only one last number, just change it to zero.
	else
	{
		m_csDigitDisplay = "0";
	}
	UpdateData(FALSE);
}

// Clear button - set '0' to display, drop everithing to default values.
void CalculatorMainWindow::OnBnClickedBtnClear()
{
	// Change things to default for a next work.
	m_csDigitDisplay = "0";
	m_csLeftOperand = "";
	m_csRightOperand = "";
	m_eMathOperation = NONE;
	m_bDisplayResult = false;
	UpdateData(FALSE);
}

// Button '0'.
void CalculatorMainWindow::OnBnClickedBtn0()
{
	AddDigitToDisplay('0');
}

// Button '1'.
void CalculatorMainWindow::OnBnClickedBtn1()
{
	AddDigitToDisplay('1');
}

// Button '2'.
void CalculatorMainWindow::OnBnClickedBtn2()
{
	AddDigitToDisplay('2');
}

// Button '3'.
void CalculatorMainWindow::OnBnClickedBtn3()
{
	AddDigitToDisplay('3');
}

// Button '4'.
void CalculatorMainWindow::OnBnClickedBtn4()
{
	AddDigitToDisplay('4');
}

// Button '5'.
void CalculatorMainWindow::OnBnClickedBtn5()
{
	AddDigitToDisplay('5');
}

// Button '6'.
void CalculatorMainWindow::OnBnClickedBtn6()
{
	AddDigitToDisplay('6');
}

// Button '7'.
void CalculatorMainWindow::OnBnClickedBtn7()
{
	AddDigitToDisplay('7');
}

// Button '8'.
void CalculatorMainWindow::OnBnClickedBtn8()
{
	AddDigitToDisplay('8');
}

// Button '9'.
void CalculatorMainWindow::OnBnClickedBtn9()
{
	AddDigitToDisplay('9');
}

// Button '.' - add period as a decimal separator. 
void CalculatorMainWindow::OnBnClickedBtnComma()
{
	AddDigitToDisplay('.');
}

// Button '/'.
void CalculatorMainWindow::OnBnClickedBtnDivision()
{
	AddMathOperation(DIV);
}

// Button '*'.
void CalculatorMainWindow::OnBnClickedBtnProduct()
{
	AddMathOperation(MULT);
}

// Button '-'.
void CalculatorMainWindow::OnBnClickedBtnMinus()
{
	AddMathOperation(SUB);
}

// Button '+'.
void CalculatorMainWindow::OnBnClickedBtnPlus()
{
	AddMathOperation(SUM);
}

// Button '=' - it's a start for actaul calculation.
void CalculatorMainWindow::OnBnClickedBtnEqual()
{
	PerformMathOperation();
}

//------------------------------------------------------------------
// Calculations
//------------------------------------------------------------------

// Set the type if math operation and perform previous one if exists.
void CalculatorMainWindow::AddMathOperation(MATH eOperation)
{
	// When previous calculation isn't finished yet.
	if (m_eMathOperation != NONE)
	{
		// Then we must perform exist operation first.
		PerformMathOperation();
	}
	m_eMathOperation = eOperation;
	m_csLeftOperand = m_csDigitDisplay;
	switch (eOperation)
	{
	case DIV: m_csDigitDisplay += " / "; break;
	case MULT: m_csDigitDisplay += " * "; break;
	case SUB: m_csDigitDisplay += " - "; break;
	case SUM: m_csDigitDisplay += " + "; break;
	default: MessageBox(NULL, L"An arithmetic operation is not defined.", MB_OK); break;
	}
	UpdateData(FALSE);
}

// All math operations we do here.
void CalculatorMainWindow::PerformMathOperation()
{
	double dLeft = _wtof(m_csLeftOperand);
	double dRight = _wtof(m_csRightOperand);

	switch (m_eMathOperation)
	{
	case DIV: m_dResult = (dRight) ? dLeft / dRight : dRight; break;
	case MULT: m_dResult = dLeft * dRight; break;
	case SUB: m_dResult = dLeft - dRight; break;
	case SUM: m_dResult = dLeft + dRight; break;
	default: MessageBox(NULL, L"An arithmetic operation is not defined.", MB_OK); break;
	}
	// Get string for display.
	m_csDigitDisplay.Format(L"%f", m_dResult);
	// Get rid of all this trailing zeroes.
	// First check for separator.
	int iFindResult = m_csDigitDisplay.Find('.');
	if (iFindResult != -1)
	{
		m_csDigitDisplay.TrimRight('0');
		int iLength = m_csDigitDisplay.GetLength();
		char cLastCharacter = m_csDigitDisplay.GetAt(iLength - 1);
		if (cLastCharacter == '.')
		{
			m_csDigitDisplay.Delete(iLength - 1);
		}
	}

	// Change everything to default for a next work.
	m_eMathOperation = NONE;
	m_csLeftOperand = "";
	m_csRightOperand = "";
	m_bDisplayResult = true;
	UpdateData(FALSE);
}

//------------------------------------------------------------------
// Child dialogs
//------------------------------------------------------------------

// Open second dialog with matrix calculator inside.
void CalculatorMainWindow::OnBnClickedBtnMatrixcalc()
{
	MatrixCalculator MatrixCalc;
	MatrixCalc.DoModal();
}