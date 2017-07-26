#include "main.h"
#include <windows.h>
#include <string>
#include "VictoryMethod.h"
#include "Computer.h"

using namespace std;

#include <gdiplus.h>
#include <gdipluspen.h>
using namespace Gdiplus;

#pragma comment(lib,"gdiplus.lib")


#define ID_buttonStart 2000
#define ID_buttonIntro 2001
#define ID_buttonDeaf 2002




int x = 0;
int y = 0;
boolean flag = false;
// ����֮ǰ�¹�ȫ����������� 0= null 1 = black 2 = white 


wstring print = L"��Ϸ��Ϣ���ڷ�����";
int allChess[19][19];



//���������ִ�з���

LRESULT CALLBACK mainWNDPROC(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{




	switch (message)
	{
		//���ܴ��ڹر���Ϣ��

	case WM_CREATE:
	{



		//����������ť���ֱ�ʵ�ָ�λ��˵���������书��

		CREATESTRUCT* pcs = (CREATESTRUCT*)lParam;

		HWND buttonStart = CreateWindow(L"Button", L"��ʼ��Ϸ", WS_CHILD,
			390, 70, 70, 30, hWnd, NULL, pcs->hInstance, NULL);
		SetWindowLong(buttonStart, GWL_ID, ID_buttonStart);

		HWND buttonIntro = CreateWindow(L"Button", L"��Ϸ˵��", WS_CHILD,
			390, 120, 70, 30, hWnd, NULL, pcs->hInstance, NULL);
		SetWindowLong(buttonIntro, GWL_ID, ID_buttonIntro);

		HWND buttonDeaf = CreateWindow(L"Button", L"����", WS_CHILD,
			390, 300, 50, 30, hWnd, NULL, pcs->hInstance, NULL);
		SetWindowLong(buttonDeaf, GWL_ID, ID_buttonDeaf);


		ShowWindow(buttonDeaf, SW_NORMAL);
		ShowWindow(buttonIntro, SW_NORMAL);
		ShowWindow(buttonStart, SW_NORMAL);
		return 0;
	}






	case WM_COMMAND:
	{
		//��ʼ��ť��ʵ��
		if (LOWORD(wParam) == ID_buttonStart)
		{

			int s = MessageBox(hWnd, L"�Ƿ����¿�ʼ��Ϸ��", L"��ʼ��Ϸ", MB_YESNO);
			if (s == 6) {
				for (int i = 0;i < 19;i++)
				{
					for (int j = 0;j < 19;j++)
						allChess[i][j] = 0;
				}
				print = L"��Ϸ��Ϣ���ڷ�����";
				flag = false;
				RECT r;
				GetClientRect(hWnd, &r);
				InvalidateRect(hWnd, &r, 1);
			}

		}
		//˵����ť��ʵ��
		if (LOWORD(wParam) == ID_buttonIntro)
		{
			MessageBox(hWnd, L"˫����ʼ���壬�����������߻�ʤ��", L"���", MB_OK);
		}
		//���䰴ť��ʵ��
		if (LOWORD(wParam) == ID_buttonDeaf)
		{
			int d = MessageBox(hWnd, L"ȷ�����䣿", L"LOSER", MB_YESNO);
			if (d == 6) {
				if (flag == false) MessageBox(hWnd, L"��������", L"Defeat", MB_OK);
				else MessageBox(hWnd, L"�������䣡", L"Defeat", MB_OK);

				PostQuitMessage(0);
			}
		}



		return 0;
	}


	//�������������룬����Ӧ
	case WM_LBUTTONDOWN:
	{




		VictoryMethod Vic;
		Computer com;


		POINT pos;
		GetCursorPos(&pos);
		ScreenToClient(hWnd, &pos);
		int x = (int)pos.x;
		int y = (int)pos.y;
		if (x >= 13 && x <= 373 && y >= 70 && y <= 430) {

			int x1 = (x - 13) / 20;
			int y1 = (y - 70) / 20;

			if ((x - x1 * 20 - 13) >= ((x1 + 1) * 20 + 13 - x))
				x = x1 + 1;
			else x = x1;

			if ((y - y1 * 20 - 70) >= ((y1 + 1) * 20 + 70 - y))
				y = y1 + 1;
			else y = y1;

			if (allChess[x][y] == 0)
			{

				allChess[x][y] = 1;
				com.putwhite(x, y, allChess);

			}
			else
			{
				MessageBox(hWnd, L"�˴��������ӣ����������ӣ�", L"����ѽ", MB_OK);
			}
		}




		int v = Vic.Victory(5, allChess);
		if (v == 1)
			MessageBox(hWnd, L"���ӻ�ʤ", L"Victory", MB_OK);
		else if (v == 2)
			MessageBox(hWnd, L"���ӻ�ʤ", L"Victory", MB_OK);





		RECT r;
		GetClientRect(hWnd, &r);
		InvalidateRect(hWnd, &r, 0);
		return  0;
	}





	//�������ڵĻ���
	case WM_PAINT:
	{


		PAINTSTRUCT ps;

		HDC hDC = BeginPaint(hWnd, &ps);
		Graphics gra(hDC);



		COLORREF   color = RGB(200, 200, 200);
		SetBkColor(hDC, color);

		wstring text = print;
		RECT rect;
		rect.top = 20;
		rect.left = 33;
		rect.bottom = 65;
		rect.right = 233;
		DrawText(hDC, text.c_str(), text.length(), &rect, DT_CENTER);


		Pen newpen(Color::Black, 1);

		for (int i = 13;i <= 375;)
		{
			gra.DrawLine(&newpen, i, 70, i, 430);
			i += 20;
		}
		for (int j = 70;j <= 430;)
		{
			gra.DrawLine(&newpen, 13, j, 373, j);
			j += 20;
		}
		SolidBrush brush(Color::Black);
		gra.FillEllipse(&brush, 70.5, 127.5, 5, 5);
		gra.FillEllipse(&brush, 310, 127.5, 5, 5);
		gra.FillEllipse(&brush, 70.5, 367.5, 5, 5);
		gra.FillEllipse(&brush, 310, 367.5, 5, 5);
		gra.FillEllipse(&brush, 189, 246.5, 7, 7);
		gra.FillEllipse(&brush, 190, 367.5, 5, 5);
		gra.FillEllipse(&brush, 70.5, 247.5, 5, 5);
		gra.FillEllipse(&brush, 310, 247.5, 5, 5);
		gra.FillEllipse(&brush, 190, 127.5, 5, 5);


		for (int i = 0; i<19;i++)
		{
			for (int j = 0;j<19;j++)
			{
				if (allChess[i][j] == 1)
				{
					// black
					int tempX = i * 20 + 13;
					int tempY = j * 20 + 70;
					SolidBrush brush(Color::Black);
					gra.FillEllipse(&brush, tempX - 7, tempY - 7, 14, 14);

				}
				if (allChess[i][j] == 2)
				{
					// white
					int tempX = i * 20 + 13;
					int tempY = j * 20 + 70;
					gra.DrawEllipse(&newpen, tempX - 7, tempY - 7, 14, 14);
					SolidBrush brush(Color::White);
					gra.FillEllipse(&brush, tempX - 7, tempY - 7, 14, 14);

				}
			}
		}


		EndPaint(hWnd, &ps);

		return 0;}

	//ʵ���˳�
	case WM_DESTROY:
	{// ����Ϣѭ�����ύһ��quit��Ϣ
		PostQuitMessage(0);
		return 0;}
	default:
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);

}




//������ע��һ��������������ʾ

int APIENTRY WinMain(
	HINSTANCE hInst,
	HINSTANCE hPrevInst,
	LPSTR lpCmpLine,
	int nCmdShow
	)
{
	GdiplusStartupInput gpsi;
	ULONG_PTR token;
	GdiplusStartup(&token, &gpsi, NULL);

	class VictoryMethod;







	WNDCLASSEX  wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW; // ʵ�ִ�ֱ��ˮƽ����ı�ʱ�������ػ�
	wcex.lpfnWndProc = mainWNDPROC;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	//���ں�Ӧ�ó����

	wcex.hInstance = hInst;

	wcex.hIcon = NULL;

	//���������Ϊ��ͨ��ͷ
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);

	wcex.hbrBackground = CreateSolidBrush(RGB(200, 200, 200)); //GetSysColorBrush(COLOR_WINDOW);

															   // long pointer string zero based
	wstring	classname = L"MyfivechessMainWnd";
	wcex.lpszMenuName = NULL;
	// ���ַ���ת��Ϊc����ָ��
	wcex.lpszClassName = classname.c_str();
	wcex.hIconSm = NULL;

	// �ύ��windows ���

	RegisterClassEx(&wcex);

	// ׼����������
	wstring Myfivechess = L"�ҵ�������";
	HWND mainWnd = CreateWindow(classname.c_str(), Myfivechess.c_str(), WS_OVERLAPPEDWINDOW,
		128, 128, 500, 500, NULL, NULL, hInst, NULL);

	// ��ʾ
	ShowWindow(mainWnd, nCmdShow);
	// ˢ��
	UpdateWindow(mainWnd);

	//����һ����Ϣ����
	MSG msg;
	// ѭ����ȡ��Ϣ
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// ������ת��������Ϣ���͸���Ϣ������ main
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}





	GdiplusShutdown(token);

	return 0;
}



