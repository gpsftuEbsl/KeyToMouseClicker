# click-screen-with-keyboard

# 簡易鍵盤模擬與按鍵記錄工具

這是一個用於模擬鍵盤按鍵行為的工具，能根據指定的按鍵在螢幕上對應的位置執行點擊操作。使用者可以自行添加新的按鍵並自訂按下該按鍵時滑鼠點擊的螢幕位置。本程式以 C++ 編寫，適用於 Windows 系統。

---

### 功能簡介

1. **按鍵模擬**  
   - 程式會模擬指定按鍵按下與釋放時的滑鼠點擊行為，並可實時更新按鍵狀態。
2. **畫面顯示**  
   - 程式會在螢幕上繪製按鍵對應的圓形位置，按鍵狀態不同（按下/未按下）會以不同顏色顯示。
   - ![image1](https://github.com/user-attachments/assets/ed885c9f-9e8e-4e36-b908-0a6518199353)
   - ![image2](https://github.com/user-attachments/assets/cb5f3982-5aca-4e46-8aa6-3040b4a93922)

3. **動態鍵盤配置**  
   - 使用者可以依需求新增鍵盤按鍵，並自訂按鍵對應的螢幕點擊位置。

---

### 使用方式

1. **執行程式**  
   編譯並運行此程式，螢幕上會顯示對應按鍵的圓形位置，根據按鍵狀態進行變色。
   
2. **新增按鍵與自訂位置**  
   修改以下程式碼部分來添加按鍵及其對應螢幕位置：
   ```cpp
   // 使用 std::vector 儲存 Key 物件
   vector<Key> keys = {
       {'W', screenWidth * 15 / 64, screenHeight * 5 / 8},
       {'S', screenWidth * 15 / 64, screenHeight * 7 / 8},
       {'A', screenWidth * 11 / 64, screenHeight * 6 / 8},
       {'D', screenWidth * 19 / 64, screenHeight * 6 / 8},
       {VK_NUMPAD3, screenWidth * 53 / 64, screenHeight * 25 / 32},
       // 新增按鍵，例如：新增 'E' 鍵對應螢幕中央
       {'E', screenWidth / 2, screenHeight / 2}
   };
   ```
   每個 `Key` 物件包含：
   - `keyCode`：對應的按鍵（例如 'E'）。
   - `x, y`：螢幕點擊位置的座標。
   
3. **運行效果**  
   當按下已配置的鍵時，程式會將滑鼠指標移動到指定位置並模擬點擊。

---

### 使用說明

1. **直接執行**  
   - 前往 Release 頁面，下載最新版本的執行檔，解壓縮後即可直接運行，無需額外設定。

2. **修改或新增按鍵**  
   - 如果需要自訂按鍵或調整點擊位置，可以使用 Visual Studio 開啟程式碼進行修改：
     - **新增按鍵：**  
       在程式中的 `keys` 向量裡添加新的按鍵設定，例如：  
       ```cpp
       {'鍵盤按鍵', 點擊位置X, 點擊位置Y}
       ```
       範例：  
       ```cpp
       {'E', screenWidth * 1 / 4, screenHeight * 1 / 2}
       ```
     - **調整螢幕比例：**  
       根據實際螢幕分辨率，可以透過調整 `stretchFactorX` 和 `stretchFactorY` 的值來改變按鍵位置的縮放比例。
     - **調整圓形標記顏色：**  
       修改 `drawCircle` 函式中 `color` 的值來改變標記的顏色。

3. **免責聲明**  
   - 本程式僅供學習與個人使用，使用者需自行承擔相關風險。  
   - 請勿將本程式用於任何違反法律或規範的用途。  
   - 程式對於模擬點擊的精準性可能會受螢幕分辨率或系統設定影響，請根據實際需求調整相關參數。  

--- 

### 系統需求

- **作業系統**：Windows 10 或以上版本
- **開發工具**：C++ 編譯器（支援 C++11，如 Visual Studio）

---

### 注意事項

- **客製化配置**：可自由修改 `keys` 陣列來自訂按鍵與螢幕位置。請確保按鍵代碼正確且座標合理。
- **警告**：請勿使用本工具進行任何違反當地法律或侵犯他人權益的操作。

---

### LICENSE

本程式僅用於個人學習與研究用途，未經授權禁止商業用途。

---

如有其他建議想法歡迎聯繫我

---

### README English Version

# Keyboard Simulation and Key Press Recording Tool

This tool simulates keyboard key presses and executes mouse clicks at specified screen positions. Users can customize key mappings by adding new keys and assigning specific screen click positions. The program is written in C++ and designed for Windows systems.

---

### Features

1. **Key Simulation**  
   - The program simulates mouse click actions for specified key presses and releases.
2. **Visual Feedback**  
   - Displays circles on the screen corresponding to key positions, with different colors for pressed and unpressed states.
   - ![image1](https://github.com/user-attachments/assets/ed885c9f-9e8e-4e36-b908-0a6518199353)
   - ![image2](https://github.com/user-attachments/assets/cb5f3982-5aca-4e46-8aa6-3040b4a93922)

3. **Dynamic Configuration**  
   - Users can add custom keys and define corresponding screen positions.

---

### How to Use

1. **Run the Program**  
   Compile and run the program. Circles will appear on the screen representing the configured keys, changing color based on their state.

2. **Add Keys and Customize Positions**  
   Edit the following part of the code to add new keys and assign their screen positions:
   ```cpp
   // Store Key objects in std::vector
   vector<Key> keys = {
       {'W', screenWidth * 15 / 64, screenHeight * 5 / 8},
       {'S', screenWidth * 15 / 64, screenHeight * 7 / 8},
       {'A', screenWidth * 11 / 64, screenHeight * 6 / 8},
       {'D', screenWidth * 19 / 64, screenHeight * 6 / 8},
       {VK_NUMPAD3, screenWidth * 53 / 64, screenHeight * 25 / 32},
       // Example: Add the 'E' key mapped to the center of the screen
       {'E', screenWidth / 2, screenHeight / 2}
   };
   ```
   Each `Key` object includes:
   - `keyCode`: The associated key (e.g., 'E').
   - `x, y`: The screen click coordinates.

3. **Execution Behavior**  
   When a configured key is pressed, the program moves the mouse pointer to the specified position and simulates a click.

---

### Instructions for Use

1. **Run the Program**  
   - Go to the Release page, download the latest version of the executable, extract it, and run it directly without additional configuration.

2. **Modify or Add Keys**  
   - If you need to customize keys or adjust the click positions, you can open the source code in Visual Studio and modify it as follows:
     - **Add a New Key:**  
       Add new key settings in the `keys` vector, for example:  
       ```cpp
       {'Key', ClickPositionX, ClickPositionY}
       ```
       Example:  
       ```cpp
       {'E', screenWidth * 1 / 4, screenHeight * 1 / 2}
       ```
     - **Adjust Screen Scaling:**  
       Modify the values of `stretchFactorX` and `stretchFactorY` to scale the key positions based on your screen resolution.
     - **Change Circle Marker Color:**  
       Update the `color` parameter in the `drawCircle` function to change the marker color.

3. **Disclaimer**  
   - This program is intended for learning and personal use only. Users are responsible for any risks associated with its use.  
   - Do not use this program for any illegal or unauthorized purposes.  
   - The accuracy of simulated clicks may vary depending on screen resolution or system settings. Please adjust the parameters as needed.  

---

### System Requirements

- **Operating System**: Windows 10 or later
- **Development Tools**: C++ compiler (C++11 support, e.g., Visual Studio)

---

### Notes

- **Custom Configuration**: You can freely modify the `keys` array to customize keys and positions. Ensure the key codes and coordinates are correct.
- **Warning**: Do not use this tool for any actions that violate local laws or infringe upon the rights of others.

---

### LICENSE

This program is intended for personal learning and research purposes only. Commercial use is not allowed without permission.
