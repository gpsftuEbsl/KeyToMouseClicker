#include <windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// 定義 Key 類別
class Key {
public:
    char keyCode;       // 按鍵代碼（例如 'W', 'A', 'S', 'D', ' '）
    int x, y;           // 按鍵的螢幕座標
    bool pressed;       // 是否按下
    bool newState;      // 是否是新狀態

    Key(char code, int xPos, int yPos)
        : keyCode(code), x(xPos), y(yPos), pressed(false), newState(false) {}
};

// 常數定義
constexpr int circleOffsetX = 0;
constexpr int circleOffsetY = 0;
constexpr float stretchFactorX = 1.25f;
constexpr float stretchFactorY = 1.25f;
//constexpr int clickDuration = 500; // 按鍵長按時間 (毫秒)

// 獲取螢幕尺寸
const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

// 使用 std::vector 儲存 Key 物件
vector<Key> keys = {
    {'W', screenWidth * 15 / 64, screenHeight * 5 / 8},
    {'S', screenWidth * 15 / 64, screenHeight * 7 / 8},
    {'A', screenWidth * 11 / 64, screenHeight * 6 / 8},
    {'D', screenWidth * 19 / 64, screenHeight * 6 / 8},
    {VK_NUMPAD3, screenWidth * 53 / 64, screenHeight * 25 / 32},
    {VK_NUMPAD2, screenWidth * 11 / 16, screenHeight * 6 / 8},
    {VK_NUMPAD1, screenWidth * 10 / 16, screenHeight * 6 / 8},
    {VK_NUMPAD6, screenWidth * 53 / 64, screenHeight * 9 / 16}
};
/*
Soul Knight
vector<Key> keys = {
{ 'W', screenWidth * 15 / 64, screenHeight * 5 / 8 },
{ 'S', screenWidth * 15 / 64, screenHeight * 7 / 8 },
{ 'A', screenWidth * 11 / 64, screenHeight * 6 / 8 },
{ 'D', screenWidth * 19 / 64, screenHeight * 6 / 8 },
{ VK_NUMPAD3, screenWidth * 13 / 16, screenHeight * 6 / 8 },
{ VK_NUMPAD2, screenWidth * 11 / 16, screenHeight * 6 / 8 },
{ VK_NUMPAD1, screenWidth * 10 / 16, screenHeight * 6 / 8 },
{ VK_NUMPAD6, screenWidth * 13 / 16, screenHeight * 5 / 8 }
};
*/

// 畫圓形標記
void drawCircle(int x, int y, int radius = 10, COLORREF color = RGB(255, 0, 0)) {
    HDC hdc = GetDC(NULL);
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    HBRUSH hBrush = CreateSolidBrush(color);
    HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

    // 還原原始畫筆與畫刷
    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush);
    ReleaseDC(NULL, hdc);
}

// 模擬按鍵行為
void press(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
}

void release(int x, int y) {
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

/*
void click(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(clickDuration);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
*/

int main() {
    while (true) {
        // 按鍵狀態更新
        for (auto& key : keys) {
            const bool isPressed = (GetAsyncKeyState(key.keyCode) & 0x8000);
            if (isPressed != key.pressed) {
                key.newState = isPressed; // 更新新狀態

                if (isPressed) {
                    press(key.x, key.y); // 模擬按下
                }
                else {
                    release(key.x, key.y); // 模擬放開
                }

                key.pressed = isPressed; // 更新狀態
            }
        }

        // 顯示對應的數字或字母
        HDC hdc = GetDC(NULL);
        SetTextColor(hdc, RGB(0, 0, 0)); // 設定文字顏色為黑色
        SetBkMode(hdc, TRANSPARENT);      // 設定文字背景透明

        // 固定圓形的大小
        const int circleSize = 10;

        // 繪製按鍵位置圓形
        for (const auto& key : keys) {
            // 繪製圓形，顏色根據按鍵是否按下而改變
            drawCircle(
                static_cast<int>(key.x * stretchFactorX + circleOffsetX),
                static_cast<int>(key.y * stretchFactorY + circleOffsetY),
                circleSize, key.pressed ? RGB(100, 100, 200) : RGB(230, 230, 250));

            // 根據 keyCode 來構造按鍵文字
            string keyText = "";
            if (key.keyCode == VK_NUMPAD1) keyText = "1";
            else if (key.keyCode == VK_NUMPAD2) keyText = "2";
            else if (key.keyCode == VK_NUMPAD3) keyText = "3";
            else if (key.keyCode == VK_NUMPAD6) keyText = "6";
            else keyText = string(1, key.keyCode); // 其他字母或符號直接顯示字符

            // 計算文字位置，將圓心的坐標調整為文字的起始位置
            int textX = static_cast<int>(key.x * stretchFactorX + circleOffsetX) - circleSize / 2;
            int textY = static_cast<int>(key.y * stretchFactorY + circleOffsetY) - circleSize / 2;

            // 顯示文字
            TextOut(hdc, textX, textY, keyText.c_str(), keyText.length());
        }

        // 釋放設備上下文
        ReleaseDC(NULL, hdc);

        // 防止 CPU 過度使用
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
